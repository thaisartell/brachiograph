/**
 * @file 
 * @brief This file contains the implementation of ...
 * @author Justin Troth
 */

#include "xc.h"
#include "plotter_utils.h"

void delay_ms(unsigned int ms) {
    while (ms-- > 0) {
        asm("repeat #15998");
        asm("nop");
    }
}
