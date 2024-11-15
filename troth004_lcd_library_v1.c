/*
 * File:   troth004_lab5a_library_v001.c
 * Author: ryoth
 *
 * Created on October 18, 2024, 11:52 AM
 */


#include "xc.h"

const int LCDaddy = 0b00111100; // Base address with SA0 line pulled low (7-bits)
const int LCDaddy_w = 0b01111000; // Address + R/nW (0)
const int LCDaddy_r = 0b01111011; // Address + R/nW (1)

void enableIC2(void) {
    _RCDIV = 0;
    I2C1CONbits.I2CEN = 0; // Disable I2C module first to set up
    I2C1CONbits.A10M = 0; // 7-bit addressing mode
    I2C1CONbits.DISSLW = 1; // Disable slew rate control for standard speed (100 kHz)
    I2C1CONbits.I2CEN = 1; // Enable I2C module
    while (I2C1STATbits.TRSTAT); // Wait for I2C bus to become idle
}

void setupBaudGenerator(void) {
    I2C1CONbits.I2CEN = 0; // Disable I2C module first to set up
    I2C1BRG = 157;   // 100 kHz as per datasheet
    I2C1CONbits.I2CEN = 1; // Disable I2C module first to set up
}

void lcd_cmd(char control_byte, char data) {
    while (I2C1STATbits.TRSTAT); // Wait for the bus to become idle

    I2C1CONbits.SEN = 1;  // Start condition
    while (I2C1CONbits.SEN);  // Wait for the start to complete

    I2C1TRN = LCDaddy_w;  // Send device address + write
    IFS1bits.MI2C1IF = 0;
    while (!IFS1bits.MI2C1IF)
    while (I2C1STATbits.TBF || I2C1STATbits.ACKSTAT);  // Wait for transmission to complete

    I2C1TRN = control_byte;  // Send control byte
    IFS1bits.MI2C1IF = 0;
    while (!IFS1bits.MI2C1IF)
    while (I2C1STATbits.TBF || I2C1STATbits.ACKSTAT);  // Wait for transmission to complete

    I2C1TRN = data;  // Send data
    IFS1bits.MI2C1IF = 0;
    while (!IFS1bits.MI2C1IF)
    while (I2C1STATbits.TBF || I2C1STATbits.ACKSTAT);  // Wait for transmission to complete

    I2C1CONbits.PEN = 1;  // Stop condition
    while (I2C1CONbits.PEN);  // Wait for the stop condition
}

void initLCD(void) {
    enableIC2();
    setupBaudGenerator();
    
    char commands[11] = {0x3A, 0x09, 0x06, 0x1E, 0x39, 0x1B, 0x6E, 0x56, 0x7A, 0x38, 0x0F};
    
    for (int i = 0; i < 11; i++) {
        lcd_cmd(0x00, commands[i]);
        delay_ms(5);
    }
    
    lcd_cmd(0x00, 0x01); //Clear display
}

void lcd_printStr(const char s[]) {
    int i = 0;

    // Loop through each character of the string until NULL terminator is encountered
    while (s[i] != '\0') {
        lcd_cmd(0x40, s[i]);
        i++;
    }
}

void setDoubleHeight(void) {
    lcd_cmd(0x00, 0x3A);
    lcd_cmd(0x00, 0x1B);
    lcd_cmd(0x00, 0x3C);
}

void setROMC(void) {
    lcd_cmd(0x00, 0x3A);
    lcd_cmd(0x00, 0x72);
    lcd_cmd(0x40, 0x0C);
    lcd_cmd(0x00, 0x3C);
}

void setCursor(int row, int column) {
    lcd_cmd(0x00, 0x80 + (row << 4) + column);
}

void setupHeartbeat(void) {
    // Configure RB15 as output for LED
    TRISBbits.TRISB15 = 0; // Set RB15 as output
    LATBbits.LATB15 = 0;   // Initialize RB15 to low (LED off)
}

void unsignedIntToString(unsigned int num, char* str) {
    // Initialize the string index
    int i = 0;

    // Handle the special case for 0
    if (num == 0) {
        str[i++] = '0';
    } else {
        // Extract digits in reverse order
        while (num > 0) {
            str[i++] = (num % 10) + '0'; // Convert digit to character
            num /= 10;                    // Remove last digit
        }
    }

    // Reverse the string to get the correct order
    str[i] = '\0'; // Null-terminate the string

    // Reverse the characters in the string
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}
