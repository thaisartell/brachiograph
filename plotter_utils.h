/**
 * @file example.c
 * @brief This file contains the implementation of ...
 * @author Justin Troth
 */

#ifndef PLOTTER_UTILS_H
#define	PLOTTER_UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief Delays execution for a specified number of milliseconds.
 *
 * @param ms The number of milliseconds to delay.
 */
void delay_ms(unsigned int ms);


#ifdef	__cplusplus
}
#endif

#endif	/* PLOTTER_UTILS_H */

