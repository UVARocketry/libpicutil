#include "leds.h"
#include <xc.h>
#include "time.h"

void leds_init() {
    //connected LED on RC3
    ANSELCbits.ANSELC3 = 0; //digital
    TRISCbits.TRISC3 = 0; //out
}
void leds_connected(uint8_t connected) {
    if(connected) {
        LATCbits.LATC3 = (time_millis() % 500) > 250;
    } else {
        LATCbits.LATC3 = (time_millis() % 2000) > 250;
    }
}