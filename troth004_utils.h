/* 
 * File:   troth004_utils.h
 * Author: ryoth
 *
 * Created on November 25, 2024, 8:09 PM
 */

#ifndef TROTH004_UTILS_H
#define	TROTH004_UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define MAX(a, b) ((a) > (b) ? (a) : (b))       // Macro function should remain as #define

/**
 * @brief Delays execution for a specified number of milliseconds.
 *
 * @param ms The number of milliseconds to delay.
 */
void delay_ms(unsigned int ms);


#ifdef	__cplusplus
}
#endif

#endif	/* TROTH004_UTILS_H */

