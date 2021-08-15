#include "leds.h"
#include <xc.h>
#include "time.h"

void leds_init() {
    //connection status LED on RC3
    ANSELC3 = 0; //digital
    TRISC3 = 0; //out
    
    //aux status LED on RC2
    //PowerPyroRCU: used to show power switch status
    //
    ANSELC2 = 0;
    TRISC2 = 0;
    
    //flash both LEDs on startup
    LATC2 = LATC3 = 1;
    __delay_ms(100);
    LATC2 = LATC3 = 0; //off at end
}

void leds_connected(uint8_t connected) {
    if(connected) {
        LATC3 = (time_millis() % 200) < 100;
    } else {
        LATC3 = (time_millis() % 2000) < 250;
    }
}