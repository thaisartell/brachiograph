#include "xc.h"
#include "sarte016_joystick_library_v1.h"
#include "troth004_utils.h"
#include "troth004_lcd_library_v1.h"

#define LCD_ADDRESS 0x78

volatile int joystick_x = 0;
volatile int joystick_y = 0;
volatile int joystick_sel = 0;

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
    
    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = 1;
}

void joystick_send_to_lcd(){
    
}

void pen_shift(){
    
}

//SEL -> AN2
//Interrupt detects button clicks. Button click controls pen up/down
void __attribute((interrupt, auto_psv)) _AD1Interrupt(void){
    joystick_x = ADC1BUF0;
    joystick_y = ADC1BUF1;
    joystick_sel = ADC1BUF2;
    IFS0bits.AD1IF = 0;
}

int main(){
    enable_I2C();
    init_pic24();
    init_joystick();
    
    
    while (1) {
        
        joystick_send_to_lcd();
        
    }
    
    return 0;
}