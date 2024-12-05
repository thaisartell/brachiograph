/**
 * @file example.c
 * @brief This file contains the implementation of ...
 * @author Justin Troth
 */

#ifndef TROTH004_LCD_LIBRARY_V1_H
#define	TROTH004_LCD_LIBRARY_V1_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define LCD_ORIENTATION 1 // 0 for bottom view, 1 for top view

extern const int LCDaddy; // Base address with SA0 line pulled low (7-bits)
extern const int LCDaddy_w; // Address + R/nW (0)
extern const int LCDaddy_r; // Address + R/nW (1)

/**
 * @brief Enables the I2C module and configures it for 7-bit addressing.
 *
 * This function must be called before using the I2C bus.
 */
void enable_I2C(void);

/**
 * @brief Sets the baud rate generator for the I2C communication.
 *
 * This function sets the I2C communication speed to 100 kHz.
 */
void setup_I2C_Baud(void);

/**
 * @brief Sends a command and data to the LCD using I2C.
 *
 * @param control_byte The control byte indicating the type of command/data.
 * @param data The data byte to send to the LCD.
 *
 * This function issues a start condition, sends the control byte and data,
 * and then issues a stop condition to complete the I2C communication.
 */
void lcd_send_command(char control_byte, char data);

/**
 * @brief Initializes the LCD with the specified startup sequence.
 *
 * This function sends a series of initialization commands to the LCD
 * to set it up for operation, followed by a clear display command.
 */
void lcd_init(void);

/**
 * @brief Prints a char to the LCD.
 *
 * @param c The char to be printed to the LCD.
 *
 * This function uses lcd_send_command to send a single character.
 */
void lcd_print_char(const char c);

/**
 * @brief Prints a null-terminated string to the LCD.
 *
 * @param s The string to be printed to the LCD.
 *
 * This function iterates through each character of the string and sends
 * it to the LCD using the lcd_cmd function.
 */
void lcd_print_string(const char s[]);

/**
 * @brief Configures the display to double height with two lines.
 *
 * This function sets the LCD to display characters in double height mode.
 */
void lcd_set_double_height(void);

/**
 * @brief Sets the ROM to C for displaying Japanese Katakana characters.
 *
 * This function configures the LCD to use a specific ROM set suitable
 * for displaying Katakana characters.
 */
void lcd_set_ROM_C(void);

/**
 * @brief Clears the LCD.
 */
void lcd_clear(void);

/**
 * @brief Sets the cursor on the LCD to the provided row and column
 * 
 * @param row the row of the LCD display to move the cursor to
 * @param column the column of the LCD display to move the cursor to
 * 
 * This function moves the cursor to the provided coordinates. Expects
 * input from 0-3 for the row and 0-9 for the column.
 * The address needs to be incremented by 10 when the LCD is in vertical mode.
 * This is done automatically by the function.
 */
void lcd_set_cursor(int cursor_row, int cursor_column);

/**
 * @brief Sets up a heartbeat LED for debugging purposes (RB6).
 *
 * This function configures the RB15 pin as an output and initializes
 * it to low (LED off). It is used to provide visual feedback during
 * debugging.
 */
void setup_heartbeat_LED(void);

/**
 * @brief Converts and int to a string and puts it in the given buffer str.
 *
 * @param num The int to convert, read as unsigned int.
 * @param str The buffer to put the result, must be at least 6 bytes.
 * 
 * This functino converts the num to string by repeatedly taking the mod 10
 * of the number, then dividing by 10, putting it in the buffer and flipping it
 * at the end.
 */
void unsigned_int_to_string(unsigned int num, char* str);

/**
 * @brief Prints an int as a null-terminated string to the LCD.
 *
 * @param value Displayed as an unsigned int, from (0-65535).
 * 
 * This function uses unsigned_int_to_string to generate a string which is then
 * sent to the lcd using lcd_print_string.
 */
void lcd_print_int(const unsigned int value);

#ifdef	__cplusplus
}
#endif

#endif	/* TROTH004_LCD_LIBRARY_V1_H */

