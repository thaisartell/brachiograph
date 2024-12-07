#include "xc.h"
#include <stdio.h>
#include "joystick_library.h"
#include "plotter_utils.h"
#include "lcd_library.h"

#define LCD_ADDRESS 0x78

volatile int joystick_x_vector = 0;
volatile int joystick_y_vector = 0;

volatile int x_pos;
volatile int y_pos;

volatile int joystick_sel = 0;

volatile int x_time;
volatile int y_time;

void init_joystick(void){
        // HOR -> pin 24 (RP13, AN11)
    TRISBbits.TRISB11 = 1;
    AD1PCFGbits.PCFG11 = 0;
    AD1CSSLbits.CSSL0 = 1;
    
    // VERT -> pin 23(RP12, AN12)
    TRISBbits.TRISB12 = 1;
    AD1PCFGbits.PCFG12 = 0;
    AD1CSSLbits.CSSL1 = 1;
    
    // SEL -> [tbd]
    //TRISBbits.TRISBxx = 1;
    AD1PCFGbits.PCFG2 = 0;
    AD1CSSLbits.CSSL2 = 1;
    
    //AD1CON1, 2, 3
    AD1CON1 = 0;
    AD1CON1bits.FORM = 0;
    AD1CON1bits.SSRC = 0b111;
    AD1CON1bits.ASAM = 0;
    
    AD1CON2 = 0;
    
    AD1CON3 = 0;
    AD1CON3bits.SAMC = 0b11111;
    AD1CON3bits.ADCS = 0;
    
    AD1CSSL = 0x0007;   //an0, an1, an2
    
    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = 1;
    
    //TIMER1 Config
    T1CON = 0;
    T1CONbits.TCKPS = 0b11;
    PR1 = 31250;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    T1CONbits.TON = 1;
}

//SEL -> AN2
//Interrupt detects button clicks. Button click controls pen up/down
void __attribute((interrupt, auto_psv)) _ADC1Interrupt(void){
    IFS0bits.AD1IF = 0;
    joystick_x_vector = ADC1BUF0 - 512;
    joystick_y_vector = ADC1BUF1 - 512;
    AD1CON1bits.SAMP = 1;
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void){
    _T1IF = 0;
    
    lcd_set_cursor(0,0);
    sprintf((joystick_x_vector * x_time) + x_pos, "%.3f");
    lcd_print_string(x_pos);
    
    lcd_set_cursor(1,0);
    sprintf((joystick_x_vector * y_time) + y_pos, "%.3f");
    lcd_print_string(y_pos);
    
}

void set_x_pos(void){
    x_pos = get_raw_x();
}

void set_y_pos(void){
    y_pos = get_raw_y();
}