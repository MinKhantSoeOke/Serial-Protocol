#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

void checksum_calculator(char frame[], char* checksum_string){
    int checksum = 0;
    for (int i=0; i<strlen(frame); i++){
        checksum += frame[i];
    }

    checksum = checksum % 256;
    sprintf(checksum_string, "%02X\n", checksum);
}


int main(void) {
    int process;
    char frame[32];
    char checksum[3];
    char *portname = "/dev/ttyS1";
    int ser_fd, ret;
    char read_string[24];

    ser_fd = open(portname, O_RDWR);

    while(1) {
        printf("Enter the message : ");
        scanf("%s", frame);
        checksum_calculator(frame, checksum);
        strcat(frame, checksum);

        ret = write (ser_fd, frame, strlen(frame));
        printf("Message Sent - %d %s\n", strlen(frame), frame);

        ret = read (ser_fd, read_string, sizeof(read_string));
        read_string[ret] = '\0';
        printf ("Received: %d %s\n", ret, read_string);

        char temp[24] = "";
        if (read_string[0] == ':' && read_string[ret-1] == '\n'){
            strncat(temp, read_string, ret-3);
            checksum_calculator(temp, checksum);
        }

        strcat(temp, checksum);

        bool result = true;
        for (int i=0; i<ret; i++){
            if (read_string[i] != temp[i]){
                result = false;
            }
            else {
                result = true;
            }
        }

        if (temp[3] == 'N'){
            result = false;
        }

        printf("Checksum : %sData : %s\n", checksum, temp);

        if (result){
            printf("The result is correct.\n\n");
        } else {
            printf("There is an error.\n\n");
        }
    }

    return EXIT_SUCCESS;
}