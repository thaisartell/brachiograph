/**
 * @file example.c
 * @brief This file contains the implementation of ...
 * @author Justin Troth
 */

#include "xc.h"
#include "plotter_utils.h"
#include "lcd_library.h"

// Constants
const int LCD_BASE_ADDRESS = 0b00111100; // Base address with SA0 line pulled low (7-bits)
const int LCD_WRITE_ADDR = 0b01111000;  // Address + R/nW (0)
const int LCD_READ_ADDR = 0b01111011;   // Address + R/nW (1)

// Functions
void enable_I2C(void) {
    _RCDIV = 0;
    I2C2CONbits.I2CEN = 0;
    I2C2CONbits.A10M = 0;
    I2C2CONbits.DISSLW = 1;
    I2C2CONbits.I2CEN = 1;
    while (I2C2STATbits.TRSTAT);
}

void setup_I2C_Baud(void) {
    I2C2CONbits.I2CEN = 0;
    I2C2BRG = 157;
    I2C2CONbits.I2CEN = 1;
}

void lcd_send_command(char control_byte, char data) {
    while (I2C2STATbits.TRSTAT);
    I2C2CONbits.SEN = 1;
    while (I2C2CONbits.SEN);

    I2C2TRN = LCD_WRITE_ADDR;
    IFS3bits.MI2C2IF = 0;
    while (!IFS3bits.MI2C2IF);
    while (I2C2STATbits.TBF || I2C2STATbits.ACKSTAT);

    I2C2TRN = control_byte;
    IFS3bits.MI2C2IF = 0;
    while (!IFS3bits.MI2C2IF);
    while (I2C2STATbits.TBF || I2C2STATbits.ACKSTAT);

    I2C2TRN = data;
    IFS3bits.MI2C2IF = 0;
    while (!IFS3bits.MI2C2IF);
    while (I2C2STATbits.TBF || I2C2STATbits.ACKSTAT);

    I2C2CONbits.PEN = 1;
    while (I2C2CONbits.PEN);
}

void lcd_clear() {
    lcd_send_command(0x00, 0x01);   
}

void lcd_init(void) {
    enable_I2C();
    setup_I2C_Baud();
    
    char lcd_orientation_byte = 0x06; // Bottom view by default
    if (LCD_ORIENTATION) {
        lcd_orientation_byte = 0x05; // Top view if selected
    }
    char commands[11] = {0x3A, 0x09, lcd_orientation_byte, 0x1E, 0x39, 0x1B, 0x6E, 0x56, 0x7A, 0x38, 0x0F};

    for (int i = 0; i < 11; i++) {
        lcd_send_command(0x00, commands[i]);
        delay_ms(5);
    }
    lcd_clear();
}

void lcd_print_char(const char c) {
    lcd_send_command(0x40, c);
}

void lcd_print_string(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        lcd_print_char(s[i]);
        i++;
    }
}

void lcd_print_int(const unsigned int value) {
    char string_buffer[6];
    unsigned_int_to_string(value, string_buffer);
    lcd_print_string(string_buffer);
}

void lcd_set_double_height(void) {
    lcd_send_command(0x00, 0x3A);
    lcd_send_command(0x00, 0x1B);
    lcd_send_command(0x00, 0x3C);
}

void lcd_set_ROM_C(void) {
    lcd_send_command(0x00, 0x3A);
    lcd_send_command(0x00, 0x72);
    lcd_send_command(0x40, 0x0C);
    lcd_send_command(0x00, 0x3C);
}

void lcd_set_cursor(int cursor_row, int cursor_column) {
    char command = 0x80 + (cursor_row << 4) + cursor_column;
    if (LCD_ORIENTATION) {
        command += 10;
    }
    lcd_send_command(0x00, command);
}

void setup_heartbeat_LED(void) {
    TRISBbits.TRISB15 = 0;
    LATBbits.LATB15 = 0;
}

void unsigned_int_to_string(unsigned int value, char* output_str) {
    int i = 0;
    if (value == 0) {
        output_str[i++] = '0';
    } else {
        while (value > 0) {
            output_str[i++] = (value % 10) + '0';
            value /= 10;
        }
    }
    output_str[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = output_str[j];
        output_str[j] = output_str[i - j - 1];
        output_str[i - j - 1] = temp;
    }
}