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
volatile int timesave[2] = {0,0};

void init_ports(void){
    // HOR -> AN0
    AD1PCFGbits.PCFG0 = 0;
    AD1CSSLbits.CSSL0 = 1;
    
    // VERT -> AN1
    AD1PCFGbits.PCFG1 = 0;
    AD1CSSLbits.CSSL1 = 1;
    
    // SEL -> AN2
    AD1PCFGbits.PCFG2 = 0;
    AD1CSSLbits.CSSL2 = 1;
    
}

void init_adc(void){
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
}

void joystick_send_to_lcd(){
    
}

//SEL -> AN2
//Interrupt detects button clicks. Button click controls pen up/down
void __attribute((interrupt, auto_psv)) _ADC1Interrupt(void){
    IFS0bits.AD1IF = 0;
    joystick_x_vector = ADC1BUF0 - 512;
    joystick_y_vector = ADC1BUF1 - 512;
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