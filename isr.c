/*
 * File:   isr.c
 * Author: Berni
 *
 * Created on 22 May, 2023, 12:22 PM
 */
#include <xc.h>
#include "config.h"
// Global Variable for 7-Segment Display
const unsigned char segTable[11]=
{
    
    0b11000000,
    0b11111001,
    0b10100100,
    0b10110000,
    0b10011001,
    0b10010010,
    0b10000010,
    0b11111000,       
    0b10000000,
    0b10010000,
    0b11111111,
            
        
};

int seg = 1;
void initSysTimer1(void);
void __interrupt() isr(void) {
    if (PIR1bits.ADIF) {
        PIR1bits.ADIF = 0; // Clear ADC interrupt flag
        unsigned int result = ADRESH * 256 + ADRESL; // Get ADC result
        // Process the ADC result, if needed
        
        unsigned int scaled_result = (result / 1023.0) * 99;
        // Update the 7-segment display with the new result
        int dig0 = scaled_result % 10;
        int dig1 = (scaled_result / 10) % 10;

        switch (seg) {
            case 1:
                //Turn on digit 0
                PORTAbits.RA4 = 0; //set RB<1:0> =01
                PORTAbits.RA5 = 1;
                PORTC = segTable[dig1];
                seg = 2;
                break;

            case 2:
                //Turn on digit 1
                PORTAbits.RA4 = 1; //set RB<1:0> =10
                PORTAbits.RA5 = 0;
                PORTC = segTable[dig0];
                seg = 1;
                break;
        }
    }

    if (TMR1IF == 1) {
        TMR1IF = 0; // Clear Timer1 interrupt flag
        // Call the 7-segment display task
        dspTaskT_Disp7Seg();
        TMR1H = 0xFF;
        TMR1L = 0x83;
    }
}
