/*
 * File:   troth004_utils.c
 * Author: ryoth
 *
 * Created on November 25, 2024, 8:09 PM
 */


#include "xc.h"

void delay_ms(unsigned int ms) {
    while (ms-- > 0) {
        asm("repeat #15998");
        asm("nop");
    }
}
