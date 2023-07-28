/*
 * File:   extint.c
 * Author: Berni
 *
 * Created on 17 May, 2023, 3:49 PM
 */


#include <xc.h>
#include "config.h"
// Global Variable:
unsigned int extint_pbCount = 0; // Keep track of button presses.
unsigned int extint_RefreshLCDFlag = 0; // Flag:Set when ext int is detected
// Cleared when display is completed
void initSysExtInt(void)
{
    INTCONbits.GIE = 0;
    PIR0bits.INTF = 0;
    INTPPS = 0x01;
    INTCONbits.INTEDG = 1;
    PIE0bits.INTE = 1;
    INTCONbits.GIE=1;
            
}

unsigned int extint_GetCount(void)
{
    return (extint_pbCount);
}