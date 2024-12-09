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

    extern volatile int x_vel;
    extern volatile int y_vel;
    extern volatile int joystick_x_vector;
    extern volatile int joystick_y_vector;
    
    void init_joystick(void);
    
    int get_x_cursor(void);
    
    int get_y_cursor(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SARTE016_JOYSTICK_LIBRARY_V1_H */