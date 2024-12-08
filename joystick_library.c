#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include "joystick_library.h"
#include "plotter_library.h"
#include "plotter_utils.h"
#include "lcd_library.h"

#define LCD_ADDRESS 0x78
#define DEADZONE 20

volatile int joystick_x_vector = 0;
volatile int joystick_y_vector = 0;

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

//    int adc_x = ADC1BUFB - 512;
//    int adc_y = ADC1BUFC - 512;
//    
//    //If movement is within joystick deadzone, neglect
//    joystick_x_vector = (abs(adc_x) < DEADZONE) ? 0 : adc_x;
//    joystick_y_vector = (abs(adc_y) < DEADZONE) ? 0 : adc_y;
//    
//    raw_x = raw_x + joystick_x_vector >> 5, 1023;
//    if (raw_x > 1023) {
//        raw_x = 1023;
//    }
//    raw_y += joystick_y_vector;
    
    raw_x = 1023-ADC1BUF0;
    raw_y = 1023-ADC1BUF1;

    LATBbits.LATB6 ^= 1; // Toggle RB15 (heartbeat LED)
//
}

//void __attribute__((interrupt, auto_psv)) _T1Interrupt(void){
//    _T1IF = 0;
//    
//    lcd_set_cursor(0,0);
//    lcd_print_int(x_pos);
//    
//    lcd_set_cursor(2,0);
//    lcd_print_int(y_pos);
//    
//    delay_ms(50);
//}

void set_x_pos(void){
    x_pos = get_raw_x();
}

void set_y_pos(void){
    y_pos = get_raw_y();
}