/*
 * File:   timer.c
 * Author: Berni
 *
 * Created on 26 July, 2023, 8:47 PM
 */


#include <xc.h>
#include "config.h"
void initSysTimer1(void) {
    GIE = 0;
    T1CON = 0b00110011; // pre-scale 8, 16-bit access, start T1
    T1CLK = 0b00000001; // clock select F OSC /4
    TMR1H = 0xFF; // write to TMR1H before TMR1L for simultaneous 
    TMR1L = 0x83; // transfer of 0xFD8F to timer1
    INTCONbits.PEIE = 1;
    TMR1IF = 0;
    TMR1IE = 1;
    GIE = 1;
}