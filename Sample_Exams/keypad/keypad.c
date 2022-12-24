/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 5/29/2022
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>

#include <delay.h>

#include <stdlib.h>

#define KEYPAD_R1 PORTB.4
#define KEYPAD_R2 PORTB.5 
#define KEYPAD_R3 PORTB.6
#define KEYPAD_R4 PORTB.7
#define KEYPAD_C1 PINB.0
#define KEYPAD_C2 PINB.1
#define KEYPAD_C3 PINB.2
#define KEYPAD_C4 PINB.3

#define KEYPAD_NUM0 0
#define KEYPAD_NUM1 1
#define KEYPAD_NUM2 2
#define KEYPAD_NUM3 3
#define KEYPAD_NUM4 4
#define KEYPAD_NUM5 5
#define KEYPAD_NUM6 6
#define KEYPAD_NUM7 7
#define KEYPAD_NUM8 8
#define KEYPAD_NUM9 9
#define KEYPAD_DIV  10
#define KEYPAD_MUL  11
#define KEYPAD_PLS  12
#define KEYPAD_MNS  13
#define KEYPAD_EQU  14
#define KEYPAD_ON   15

unsigned char keypad_scan();

void putnumber(float result) {
    unsigned char reschar[10];
    ftoa(result, 2, reschar);
    lcd_puts(reschar);
}

void main(void)
{
int a = -1, b = -1;
char sgn = '#';
unsigned char done = 0;

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 0
// RD - PORTA Bit 1
// EN - PORTA Bit 2
// D4 - PORTA Bit 4
// D5 - PORTA Bit 5
// D6 - PORTA Bit 6
// D7 - PORTA Bit 7
// Characters/line: 16
lcd_init(16);

while (1)
      {
      unsigned char key_res;
      if ((key_res = keypad_scan()) != 255) {   
            while(keypad_scan() != 255){;}
            delay_ms(5);
            if (key_res == KEYPAD_ON) {
                lcd_clear();   
                a = -1;
                b = -1;
                sgn = '#';
                done = 0;                
            }
            else if (key_res == KEYPAD_MUL) {
                if (a != -1 && b == -1 && sgn == '#') { 
                    sgn = '*';
                    lcd_putchar('*');
                }
            } else if (key_res == KEYPAD_DIV) {                
                if (a != -1 && b == -1 && sgn == '#') {
                    sgn = '/';
                    lcd_putchar('/');
                }
            } else if (key_res == KEYPAD_EQU) {
                if (a > -1 && b > -1 && !done) {
                    lcd_putchar('=');
                    if (sgn == '*') {
                        putnumber((long)a * b);
                    }
                    if (sgn == '/') {
                        putnumber((float)a / b);
                    }             
                    done = 1;
                } 
            } else if (key_res >= 0 && key_res <= 9) {
                if (a <= 99 && sgn == '#') {
                    lcd_putchar('0' + key_res);
                    if (a == -1) {
                        a = key_res;
                    } else {
                        a = a * 10 + key_res;
                    }
                }                            
                if (a != -1 && sgn != '#' && b <= 99) {
                    lcd_putchar('0' + key_res);
                    if (b == -1) {
                        b = key_res;
                    } else {
                        b = b * 10 + key_res;
                    }
                }                
            }
      }
      delay_ms(5);
      }
}

unsigned char keypad_scan()
{
unsigned char result=255;
////////////////////////  ROW1 ////////////////////////
KEYPAD_R1 = 1; KEYPAD_R2 = 0;  KEYPAD_R3 = 0;  KEYPAD_R4 = 0; //set Row1 for Keypad
delay_ms(5);
if (KEYPAD_C1)
result = KEYPAD_NUM7;
else if (KEYPAD_C2)
result = KEYPAD_NUM8;
else if (KEYPAD_C3)
result = KEYPAD_NUM9;
else if (KEYPAD_C4)
result = KEYPAD_DIV;

////////////////////////  ROW2 ////////////////////////
KEYPAD_R1 = 0; KEYPAD_R2 = 1;  KEYPAD_R3 = 0;  KEYPAD_R4 = 0; //set Row2 for Keypad
delay_ms(5);
if (KEYPAD_C1)
result = KEYPAD_NUM4;
else if (KEYPAD_C2)
result = KEYPAD_NUM5;
else if (KEYPAD_C3)
result = KEYPAD_NUM6;
else if (KEYPAD_C4)
result = KEYPAD_MUL;

////////////////////////  ROW3 ////////////////////////
KEYPAD_R1 = 0; KEYPAD_R2 = 0;  KEYPAD_R3 = 1;  KEYPAD_R4 = 0; //set Row3 for Keypad
delay_ms(5);
if (KEYPAD_C1)
result = KEYPAD_NUM1;
else if (KEYPAD_C2)
result = KEYPAD_NUM2;
else if (KEYPAD_C3)
result = KEYPAD_NUM3;
else if (KEYPAD_C4)
result = KEYPAD_MNS;

////////////////////////  ROW4 ////////////////////////
KEYPAD_R1 = 0; KEYPAD_R2 = 0;  KEYPAD_R3 = 0;  KEYPAD_R4 = 1; //set Row4 for Keypad
delay_ms(5);
if (KEYPAD_C1)
result = KEYPAD_ON;
else if (KEYPAD_C2)
result = KEYPAD_NUM0;
else if (KEYPAD_C3)
result = KEYPAD_EQU;
else if (KEYPAD_C4)
result = KEYPAD_PLS;

return result;
} 