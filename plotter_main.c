/**
 * @file example.c
 * @brief This file contains the implementation of ...
 * @author Justin Troth
 */

#include "xc.h"
#include "plotter_utils.h"
#include "lcd_library.h"
#include "circular_buffer_library.h"
#include "plotter_library.h"

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
    init_joystick();
   
    // Set servos to 90 90, starting position.
    set_servo(32768);
    set_servo2(32768);
    delay_ms(DELAY_TIME);
    
    while (1) {
        if (run_test_pattern_flag) {
            run_test_pattern();
            run_test_pattern_flag = 0;
        }
        else {
            update_servo_angles(1);

            delay_ms(DELAY_TIME); // Wait
            LATBbits.LATB6 ^= 1; // Toggle RB15 (heartbeat LED)
        }
    }

    return 0;
}