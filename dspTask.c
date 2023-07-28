/*
 * File:   dspTask.c
 * Author: Berni
 *
 * Created on 31 May, 2023, 7:50 PM
 */


#include <xc.h>
#include "config.h"
// Function Declarations:
// - Defined in other file(s):

void seg_DispAll(unsigned int result);
unsigned int adc_GetTConversion(void);
unsigned int adc_GetWConversion(void);
void lcdWriteDspData(char x);
void lcdCtrl_SetPos(unsigned char row, unsigned char col);
unsigned int extint_GetCount(void);

// Extern Global Variable
// Global Variable for 7-Segment Display
int seg = 1;
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


void dspTaskT_Disp7Seg(void)
{
    unsigned int temp;

    if(adc_GetTConversion()==adc_GetTConversion()) {
        unsigned int result = adc_GetTConversion();
        if (PIR1bits.ADIF) {
        PIR1bits.ADIF = 0;
        unsigned int scaled_result = (result / 1023.0)*99;
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
}
}


void dspTaskW_OnLCD(void)
{
    unsigned int Wlvl;
    int count;
    unsigned char dig0, dig1, dig2;
    if(adc_GetWConversion()== adc_GetWConversion()) {
        
        Wlvl = adc_GetWConversion();
        count = Wlvl/10;// Get the count
        dig0 = count%10;
        dig1 = (count/10)%10;
        dig2 = (count/100)%10;
        lcdCtrl_SetPos(2, 8);
        lcdWriteDspData(dig2 + 0x30);
        lcdWriteDspData(dig1 + 0x30); // Add 0x30 to translate digit to ASCII
        lcdWriteDspData(dig0 + 0x30);
        
    
    }
}