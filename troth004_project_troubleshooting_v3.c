/*
Date: 10/18/2024
Name: Justin Troth
Student ID number: 5525064
Course number: EE 2361
Term: Fall 2024
 */

#include "xc.h"
#include "troth004_lcd_library_v1.h"
#include "troth004_circular_buffer_library_v1.h"
#include "troth004_plotter_library_v1.h"

// CW1: FLASH CONFIGURATION WORD 1
#pragma config ICS = PGx1          // Comm Channel Select
#pragma config FWDTEN = OFF        // Watchdog Timer Enable
#pragma config GWRP = OFF          // General Code Segment Write Protect
#pragma config GCP = OFF           // General Code Segment Code Protect
#pragma config JTAGEN = OFF        // JTAG Port Enable

// CW2: FLASH CONFIGURATION WORD 2
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select
#pragma config IOL1WAY = OFF       // IOLOCK Protection
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function
#pragma config FCKSM = CSECME      // Clock Switching and Monitor
#pragma config FNOSC = FRCPLL      // Oscillator Select

int main(void) {
    init_buffers();
    init_servos();
    init_test_pattern_button();
    
    setup_heartbeat_LED();
    lcd_init();
   
    // Set servos to 90 90, starting position.
    set_servo(32768);
    set_servo2(32768);
    delay_ms(DELAY_TIME);
    
    // Set to run test pattern first
    run_test_pattern_flag = 0;
    
    while (1) {
        if (run_test_pattern_flag) {
            run_test_pattern();
            run_test_pattern_flag = 0;
        }
        else {

            update_servo_angles(1);

            delay_ms(DELAY_TIME); // Wait
            LATBbits.LATB15 ^= 1; // Toggle RB15 (heartbeat LED)
        }
    }

    return 0;
}