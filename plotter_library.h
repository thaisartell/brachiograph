/**
 * @file example.c
 * @brief This file contains the implementation of ...
 * @author Justin Troth
 */

#ifndef PLOTTER_LIBRARY_H
#define	PLOTTER_LIBRARY_H

#include "circular_buffer_library.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>

#define ARCTAN_TABLE_SIZE 1024

// Constants
/**
 * @brief Sets the OC1R register for PWM control.
 * Must be set to 40000 at F_CY = 16 MHz for servo to function properly.
 */
static const int SERVO_PERIOD = 40000; // Prescale 8: 20ms

/**
 * @brief The amount of time, in ms, to delay between each move operation.
 * Minimum 30ms for LCD to work.
 */
static const int DELAY_TIME = 50;

/**
 * @brief Controls how quickly the test pattern moves. 
 * Lower values makes it go more quickly.
 */
static const int CYCLES_TO_TRAVEL = 10;

/**
 * @brief The minimum value that the x coordinate can be.
 * This value must be capped because (0,0) is the outer servo.
 * Y could also be clamped, or some other logic could be used to prevent collision.
 * Capping X is a simple solution to prevent collision.
 */
static const int X_MIN = 128;

// Global Variables

/**
 * @brief Look up table for the inner angle.
 * Use the distance function as input.
 * Pre-calculated using python.
 */
extern const unsigned int inner_angle_table[1447];

/**
 * @brief Look up table for arctan.
 * Use (x<<16/y) or (y<<16/x) as input, whichever is smaller.
 * Pre-calculated using python.
 */
extern const unsigned int arctan_table[ARCTAN_TABLE_SIZE];

/**
 * @brief Flag set by IC1 to run the test pattern.
 */
extern volatile int run_test_pattern_flag;

/**
 * @brief The raw x value, modified by the ADC.
 */
extern volatile int raw_x;

/**
 * @brief The raw y value, modified by the ADC.
 */
extern volatile int raw_y;

// Function Declarations

/**
 * @brief Initializes a PWM signal to be sent to RB14 and RB13
 * RP14 corresponds to the outer servo.
 * RP13 corresponds to the inner servo.
 *
 * This function must be called before using the servos.
 */
void init_servos(void);

/**
 * @brief Initializes a Input Capture 1 to RB5 to capture a button press.
 * 
 * This function must be called before using the test pattern button.
 */
void init_test_pattern_button(void);

/**
 * @brief Sets a flag that the test pattern button has been pressed.
 */
void __attribute__((__interrupt__, auto_psv)) _IC1Interrupt(void);

/**
 * @brief Sets the outer servo to the given angle.
 * 
 * @param percent The angle to set the degree, range from 0-65535.
 * 
 * Angle is given as an unsigned int, 0 reprsenting the minimum angle, 65535 representing the maximum angle.
 * This value is then converted and used to set the OC1RS register to send a PWM signal to the servo.
 * Important value: 32768 sets the servo to 90*, which can be used for calibration.
 */
void set_servo(unsigned int percent);

/**
 * @brief Sets the inner servo to the given angle.
 * 
 * @param percent The angle to set the degree, range from 0-65535.
 * 
 * Angle is given as an unsigned int, 0 reprsenting the minimum angle, 65535 representing the maximum angle.
 * This value is then converted and used to set the OC1RS register to send a PWM signal to the servo.
 * Important value: 32768 sets the servo to 90*, which can be used for calibration.
 */
void set_servo2(unsigned int percent);

/**
 * @brief Approximates the distance spanned by x and y using Halley's Method.
 * 
 * @param x The x value to use as a coordinate
 * @param y The y value to use as a coordinate
 * 
 * Uses a single iteration of Halley's Method to calculate sqrt(x^2+y^2).
 */
unsigned int distance(unsigned int x, unsigned int y);

/**
 * @brief Calculates the index to use for the inner_angle_table to get the appropriate angle.
 * 
 * @param x The x value to use as a coordinate
 * @param y The y value to use as a coordinate
 */
unsigned int calculate_inner_angle(unsigned int x, unsigned int y);

/**
 * @brief Calculates the inner angle given a coordinate.
 * 
 * @param x The x value to use as a coordinate
 * @param y The y value to use as a coordinate
 */
unsigned int calculate_arctan_index(unsigned int x, unsigned int y);

/**
 * @brief Calculates the outer angle given a coordinate.
 * 
 * @param x The x value to use as a coordinate
 * @param y The y value to use as a coordinate
 */
unsigned int calculate_outer_angle(unsigned int x, unsigned int y);

/**
 * @brief Moves raw_x and raw_y to new_x and new_y over cycles_to_travel cycles.
 * 
 * @param new_x The x value to move to
 * @param new_y The y value to move to
 * @param cycles_to_travel How many cycles it takes to move to the new coordinate
 * 
 * Stops the main loop from running to prevent interference from user input.
 */
void move_to(int new_x, int new_y, int cycles_to_travel);

/**
 * @brief Looks at raw_x and raw_y and sets appropriate angles for the servos. Optionally prints to the LCD as well.
 * 
 * @param print_to_lcd Booleaen. If 1, then the function will also print angles and positions to the LCD.
 * 
 * Stops the main loop from running to prevent interference from user input.
 */
void update_servo_angles(int print_to_lcd);

/**
 * @brief Runs a test pattern. Draws a square, circle, and line.
 * 
 * Stops the main loop from executing because it uses move_to.
 */
void run_test_pattern(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PLOTTER_LIBRARY_H */

