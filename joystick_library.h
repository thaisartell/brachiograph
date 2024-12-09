/* 
 * File:   sarte016_joystick_library_v1.h
 * Author: thai
 *
 * Created on November 28, 2024, 6:11 PM
 */

#ifndef SARTE016_JOYSTICK_LIBRARY_V1_H
#define	SARTE016_JOYSTICK_LIBRARY_V1_H

#ifdef	__cplusplus
extern "C" {
#endif
// Constants
/**
 * @brief Down-scaled values read from buffer to determine direction vectors.
 * Vectors added to raw_x, raw_y respectively to control smooth arm movement.
 */
extern volatile int x_vel;
extern volatile int y_vel;

//Functions
/**
 * @brief Initializes ADC1 to capture buffer values.
 * Values from ADC1BUF0, ADC1BUF1 down-scaled and assigned to x_vel, y_vel respectively (for vector configuration).
 * If not vector configuration, are assigned to raw_x, raw_y for absolute positioning.
 */
void init_joystick(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SARTE016_JOYSTICK_LIBRARY_V1_H */