/*
 * File:   adc.c
 * Author: Berni
 *
 * Created on 31 May, 2023, 7:50 PM
 */


#include <xc.h>
#include "config.h"
// Function to initialise the ADC
void initADC(void)
{
    ADREF = 0b00000000; // Set VREF+ and VREF- to VSS and VDD
    ADCLK = 0b00000011; // Set TAD = 2 us
    ADACQ = 0b00000000; // TACQ to be manually inserted
    ADCON0 = 0b10000100; // Enable ADC, single conversion, FOSC clock,
// result is right justified
}
// Function to start ADC conversion and get the results
unsigned int adc_GetTConversion(void)
{
    unsigned int result;
    ADPCH = 0b00000011; // Select channel ANA3 for input at RA3
    __delay_us(2); // Add 2 us TACQ manually
    ADCON0bits.ADGO = 1; // Start conversion
    while(ADCON0bits.ADGO == 1); // Wait for conversion to complete
    result =  ADRESH*256+ADRESL ;// Get the results
    return (result); // Return the result
}

unsigned int adc_GetWConversion(void)
{
    unsigned int result;
    ADPCH = 0b00001101; // Select channel ANB5 for input at RB5
    __delay_us(2); // Add 2 us TACQ manually
    ADCON0bits.ADGO = 1; // Start conversion
    while(ADCON0bits.ADGO == 1); // Wait for conversion to complete
    result =  ADRESH*256+ADRESL ;// Get the results
    return (result); // Return the result
}
