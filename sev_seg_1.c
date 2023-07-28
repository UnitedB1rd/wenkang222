/*
 * File:   sev_seg.c
 * Author: Berni
 *
 * Created on 31 May, 2023, 7:50 PM
 */


#include <xc.h>
#include "config.h"
#define SEV_SEG_PORT      PORTC

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

void seg_DispAll(unsigned int result)
{
    int dig0,dig1,dig2,dig3,dig4;
    dig0 = result%10;
    dig1 =(result/10)%10;
    dig2 =(result/100)%10;
    dig3 =(result/1000%10);
    PORTAbits.RA5=0;
    PORTAbits.RA4=0;
    PORTC = segTable[dig0];
    __delay_ms(5);
    PORTC = segTable[10];
    
    PORTAbits.RA5 = 0;
    PORTAbits.RA4 = 1;
    PORTC = segTable[dig1];
    __delay_ms(5);
    PORTC= segTable[10];
    
    PORTAbits.RA5 = 1;
    PORTAbits.RA4 = 0;
    PORTC = segTable[dig2];
    __delay_ms(5);
    PORTC= segTable[10];
    
    PORTAbits.RA5 = 1;
    PORTAbits.RA4 = 1;
    PORTC = segTable[dig3];
    __delay_ms(5);
    PORTC= segTable[10];
}    
     