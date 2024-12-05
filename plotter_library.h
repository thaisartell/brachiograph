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
static const int SERVO_PERIOD = 40000; // Prescale 8: 20ms
static const int DELAY_TIME = 50;    // in ms, minimum 30 for LCD to work
static const int CYCLES_TO_TRAVEL = 10;
static const int X_OFFSET = 128;

// Global Variables
extern const unsigned int inner_angle_table[1447];
extern const unsigned int arctan_table[ARCTAN_TABLE_SIZE];
extern volatile int run_test_pattern_flag;
extern volatile int raw_x;
extern volatile int raw_y;

// Function Declarations
void delay_ms(unsigned int ms);
void init_servos(void);
void init_test_pattern_button(void);
void __attribute__((__interrupt__, auto_psv)) _IC1Interrupt(void);
void set_servo(unsigned int percent);
void set_servo2(unsigned int percent);
unsigned int distance(unsigned int x, unsigned int y);
unsigned int calculate_inner_angle(unsigned int x, unsigned int y);
unsigned int calculate_arctan_index(unsigned int x, unsigned int y);
unsigned int calculate_outer_angle(unsigned int x, unsigned int y);
void move_to(int new_x, int new_y, int cycles_to_travel);
void update_servo_angles(int print_to_lcd);
void run_test_pattern(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PLOTTER_LIBRARY_H */

