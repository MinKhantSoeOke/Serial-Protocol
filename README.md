# Serial Communication Protocol

**by**: Min Khant Soe Oke, Kaung Sithu

## Overview

This project implements a master-slave communication protocol over a serial link using C. The master device sends messages to and receives responses from the slave device using a defined text-based protocol. This project demonstrates the basics of serial communication, protocol frame structures, and checksum calculation to ensure data integrity.

## Dependencies

**To run this project, you need to have the following dependencies installed:**

* GCC (GNU Compiler Collection)
* Standard C Libraries

## Features

**Master-Slave Communication**
- The master device initiates communication by sending commands to the slave device, which responds accordingly.

**Protocol Frame Structure**
- Each message frame follows a specific structure: start character (`:`), address, command, data, checksum, and end character (`\n`).

**Checksum Calculation**
- Ensures data integrity by calculating the checksum as a modulo 256 sum of the frame's ASCII values.

**Message Input and Transmission**
- The user inputs a message, which is then sent over the serial port after appending the calculated checksum.

**Response Reception and Validation**
- The program reads the response from the serial port, validates the checksum, and displays the result.

## Example Execution

**Message Input**
- The program prompts the user to enter a message, calculates the checksum, appends it to the frame, and sends it over the serial port.

**Response Parsing**
- The program reads the response, validates the format and checksum, and prints the result.

## How to Use

1. **Enter the Message**:
   - Run the application and enter the message when prompted.

2. **View the Response**:
   - The application will display the sent message and the response received from the slave device.

3. **Verify Data Integrity**:
   - The application will automatically check the integrity of the received data using checksum validation.

## Authors

- Min Khant Soe Oke
- Kaung Sithu
