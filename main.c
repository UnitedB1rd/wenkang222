/*
 * File:   main.c
 * Author: Berni
 *
 * Created on 31 May, 2023, 7:50 PM
 */


#include <xc.h>
#include "config.h"
// Function Declarations:
// - Defined in this file:
void initSysPins(void);

// - Defined in other file(s):
void initADC(void);
void initLCD(void);
void dspTaskT_Disp7Seg(void);;
void dspTaskW_OnLCD(void);
void lcdWriteDspData(char x);
void lcdCtrl_SetPos(char row, char col);
void seg_DispAll(unsigned int result);

void main(void)
{
    unsigned int result;
    unsigned int temp;
    initSysPins();
    initADC();
    char message1[] = "PressS2 for Temp";
    char message2[] = "S3 for Water Lvl";
    unsigned int i;
    initLCD(); // Initialise the LCD

    lcdCtrl_SetPos(1, 1);
    for(i = 0; message1[i]!=0; i++) {
    lcdWriteDspData(message1[i]);
    }

    lcdCtrl_SetPos(2, 1);
    for(i = 0; message2[i]!=0; i++) {
    lcdWriteDspData(message2[i]);
    }
    while(1)
    {
        
        
        if(PORTBbits.RB1==0){
                char message3[] = "Temperature:";
                char message4[] = "        ";
                unsigned int i;
                initSysPins(); // Initialise the port pins
                initLCD(); // Initialise the LCD
                lcdCtrl_SetPos(1, 1);
                for(i = 0; message3[i]!=0; i++) {
                lcdWriteDspData(message3[i]);
                }
                lcdCtrl_SetPos(2, 1);
                for(i = 0; message4[i]!=0; i++) {
                lcdWriteDspData(message4[i]);
                }
                PORTA = 0b00000000;
                while(1){
                    
                    dspTaskT_Disp7Seg();
                }
                
            }
            
        
            
        if(PORTBbits.RB2==0){
            char message5[] = "Water Level:";
            char message6[] = "           %";
            unsigned int i;
            initSysPins(); // Initialise the port pins
            initLCD(); // Initialise the LCD
            lcdCtrl_SetPos(1, 1);
            for(i = 0; message5[i]!=0; i++) {
            lcdWriteDspData(message5[i]);
            }
            lcdCtrl_SetPos(2, 1);
            for(i = 0; message6[i]!=0; i++) {
            lcdWriteDspData(message6[i]);
            }
            PORTA = 0b00000000;
            while(1){
                dspTaskW_OnLCD();
            }
            
            
        }
    }
}            
           
           
     
        
        
            
            
      
    
  

// Function to configure the ports
void initSysPins(void)
{
    ANSELA = 0b00001010; 
    TRISA  = 0b11001010; 
    ANSELB = 0b00100000; 
    TRISB  = 0b11111110; 
    ANSELC = 0b00000000; 
    TRISC  = 0b00000000;
    ANSELD = 0b00000000;
    TRISD  = 0b00001111;
    ANSELE = 0b00000000; 
    TRISE  = 0b11101100; 
}