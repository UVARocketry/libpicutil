# libpicutil

Code providing interface to PIC18F26K83 microcontroller peripherals and intended to be a submodule included in each of the RCU software repositories. We don't need a full hardware abstraction layer - just implement functions as needed. So far I have working:
- UART serial output, non-blocking
- ADC input
- Millisecond counter
- Configuration byte settings which should work for all RCUs