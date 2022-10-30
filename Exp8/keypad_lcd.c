/* Mahdi Amiri Shavaki
98522148
*/

#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>

#include <delay.h>

#include <stdlib.h>

#define KEYPAD_R1 PORTD.0
#define KEYPAD_R2 PORTD.1
#define KEYPAD_R3 PORTD.2
#define KEYPAD_R4 PORTD.3
#define KEYPAD_C1 PIND.4
#define KEYPAD_C2 PIND.5
#define KEYPAD_C3 PIND.6
#define KEYPAD_C4 PIND.7

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

float calc(float num1, float num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '%':
            return num1 / num2;
    }    
}

void main(void)
{
unsigned int num1 = 0, num2 = 0, flg1 = 0, flg2 = 0, done = 0;
unsigned char op = ' ';

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);
lcd_clear();
lcd_gotoxy(1,0);
lcd_puts("KEYPAD AND LCD");
lcd_gotoxy(5,1);
lcd_puts("PROJECT");
delay_ms(2000);
lcd_clear();

while (1)
      {               
      unsigned char key_res = keypad_scan();
      if(key_res != 255)
      { 
      while(keypad_scan() != 255);
      delay_ms(20);
      if (key_res == KEYPAD_DIV && flg1 == 1 && flg2 == 0 && op == ' ') {
          lcd_putchar('%');
          op = '%';
      }
      else if (key_res == KEYPAD_MUL && flg1 == 1 && flg2 == 0 && op == ' ') {
          lcd_putchar('*');
          op = '*';                                      
      }
      else if (key_res == KEYPAD_MNS && flg1 == 1 && flg2 == 0 && op == ' ') {
          lcd_putchar('-');
          op = '-';                                      
      }
      else if (key_res == KEYPAD_PLS && flg1 == 1 && flg2 == 0 && op == ' ') {
          lcd_putchar('+');
          op = '+';            
      }
      else if (key_res == KEYPAD_EQU && flg1 == 1 && flg2 == 1 & done == 0) {
          float ans = calc(num1, num2, op);
          char ansstr[100];
          lcd_putchar('=');  
          done = 1;
          ftoa(ans, 2, ansstr);                                    
          lcd_puts(ansstr);
      }
      else if (key_res == KEYPAD_ON)
      {
          lcd_clear();
          lcd_gotoxy(0,0); 
          num1 = 0;
          num2 = 0;
          op = ' ';  
          done = 0;
          flg1 = 0;
          flg2 = 0;
      }                               
      else if (key_res <= 9) {
          if (flg1 == 0) {
            lcd_putchar(key_res + 48);
            flg1 = 1;
            num1 = key_res;
          } else if (flg1 == 1 && flg2 == 0 && op == ' ' && num1 <= 9) {
            lcd_putchar(key_res + 48);
            num1 = key_res + num1 * 10;
          } else if (flg1 == 1 && flg2 == 0 && op != ' ') {
            lcd_putchar(key_res + 48);
            flg2 = 1;
            num2 = key_res;          
          } else if (flg1 == 1 && flg2 == 1 && num2 <= 9) {
            lcd_putchar(key_res + 48);
            num2 = key_res + num2 * 10;          
          }
      }    
      }
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