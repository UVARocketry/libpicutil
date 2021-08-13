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
    TRISC3 = 0;
    
    //flash both LEDs on startup
    for(uint8_t x = 0; x < 3; x++) {
        LATC3 = 1;
        LATC2 = 0;
        __delay_ms(100);
        LATC3=0;
        LATC2 = 1;
        __delay_ms(100);
    }
    LATC2 = 0; //off at end
}

void leds_connected(uint8_t connected) {
    if(connected) {
        LATC3 = (time_millis() % 200) < 100;
    } else {
        LATC3 = (time_millis() % 2000) < 250;
    }
}