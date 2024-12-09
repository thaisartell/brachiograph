#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include "joystick_library.h"
#include "plotter_library.h"

volatile int joystick_x_vector = 0;
volatile int joystick_y_vector = 0;

volatile int x_vel = 0;
volatile int y_vel = 0;

volatile int x_pos;
volatile int y_pos;

void init_joystick(void) {
    // Configure analog pins
    TRISBbits.TRISB13 = 1; // AN11 (HOR) as input
    AD1PCFGbits.PCFG11 = 0; // Set AN11 as analog
    TRISBbits.TRISB12 = 1; // AN12 (VERT) as input
    AD1PCFGbits.PCFG12 = 0; // Set AN12 as analog

    // Configure ADC module
    AD1CON1 = 0x00E4; // Auto-convert after sampling
    AD1CON2 = 0x0404; // Scan inputs, 2 samples per interrupt
    AD1CON3 = 0x1F01; // Max sample time = 31 Tad, Tad = 2 Tcy
    AD1CSSL = 0x1800; // Enable scanning for AN11 and AN12 (bits 11 and 12)
    AD1CON1bits.FORM = 0;
    
    // Enable ADC and interrupt
    IFS0bits.AD1IF = 0; // Clear ADC interrupt flag
    IEC0bits.AD1IE = 1; // Enable ADC interrupt
    IPC3bits.AD1IP = 1; // Set ADC interrupt priority to 1
    AD1CON1bits.ADON = 1; // Turn on ADC
}


//SEL -> AN2
//Interrupt detects button clicks. Button click controls pen up/down
void __attribute((interrupt, auto_psv)) _ADC1Interrupt(void){
    IFS0bits.AD1IF = 0;
    
    x_vel =  (512-ADC1BUF0)>>5;
    y_vel =  (512-ADC1BUF1)>>5;
    
    raw_x = 1023-ADC1BUF0;
    raw_y = 1023-ADC1BUF1;
    
    LATBbits.LATB6 ^= 1; // Toggle RB15 (heartbeat LED)
}