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

// Declare your global variables here

// Standard Input/Output functions
#include <stdio.h>

void putterminal(unsigned char n) {
    if (n <= 9) {
        putchar(n + '0');
    } else {
        putchar(n - 10 + 'A');
    }
}

void main(void)
{
const char msg[] = "In the name of God\r\n";
int i, prev = 0;

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

for (i = 0; msg[i]; i++) putchar(msg[i]);

while (1)
      {
      unsigned int dipsw = 1 * PINA.0 + 2 * PINA.1 + 4 * PINA.2 + 8 * PINA.3 + 16 * PINA.4 + 32 * PINA.5 + 64 * PINA.6 + 128 * PINA.7;
      if (dipsw != prev) {
            unsigned char yekan, dahgan, sadgan;
            prev = dipsw;
            yekan = dipsw % 10;            
            dahgan = (dipsw / 10) % 10;
            sadgan = dipsw / 100;    
            putterminal(sadgan);
            putterminal(dahgan);
            putterminal(yekan);
            putchar('\r');
            putchar('\n');
      }
      }
}
