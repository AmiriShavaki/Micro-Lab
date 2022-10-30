/*****************************************************
Date    : 6/8/2020
Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
*****************************************************/

#include <mega32.h>
#include <delay.h>
// Standard Input/Output functions
#include <stdio.h>
unsigned char i;
void usart_send_string(char *str);
void main(void)
{
unsigned char a,counter=0;
// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

while (1)
      {
      // Place your code here
      
      a = getchar();
      counter++;
      putchar(a);
      if (counter == 5)
          {
          counter = 0;
          usart_send_string("\n\r ========== Five Characters are recieved =====\n\r");
          }
      }

}

void usart_send_string(char *str)
{
    for(i=0;str[i];i++)
    putchar(str[i]);
}

