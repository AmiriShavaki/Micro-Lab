/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 3/15/2022
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
#include <delay.h>

const unsigned char Code[80]=
{
    0xFF,    //    0001        # # # # # # # # 
    0x81,    //    0002        # . . . . . . # 
    0xEE,    //    0003        # # # . # # # . 
    0xEE,    //    0004        # # # . # # # . 
    0xEE,    //    0005        # # # . # # # . 
    0x81,    //    0006        # . . . . . . # 
    0xFF,    //    0007        # # # # # # # # 
    0xFF,    //    0008        # # # # # # # # 
    0xFF,    //    0009        # # # # # # # # 
    0xFF,    //    000A        # # # # # # # # 
    0xFF,    //    000B        # # # # # # # # 
    0xFF,    //    000C        # # # # # # # # 
    0xFF,    //    000D        # # # # # # # # 
    0x80,    //    000E        # . . . . . . . 
    0xB6,    //    000F        # . # # . # # . 
    0xB6,    //    0010        # . # # . # # . 
    0xB6,    //    0011        # . # # . # # . 
    0xC9,    //    0012        # # . . # . . # 
    0xFF,    //    0013        # # # # # # # # 
    0xFF,    //    0014        # # # # # # # # 
    0xFF,    //    0015        # # # # # # # # 
    0xFF,    //    0016        # # # # # # # # 
    0xFF,    //    0017        # # # # # # # # 
    0xFF,    //    0018        # # # # # # # # 
    0xFF,    //    0019        # # # # # # # # 
    0xC1,    //    001A        # # . . . . . # 
    0xBE,    //    001B        # . # # # # # . 
    0xBE,    //    001C        # . # # # # # . 
    0xBE,    //    001D        # . # # # # # . 
    0xDD,    //    001E        # # . # # # . # 
    0xFF,    //    001F        # # # # # # # # 
    0xFF,    //    0020        # # # # # # # # 
    0xFF,    //    0021        # # # # # # # # 
    0xFF,    //    0022        # # # # # # # # 
    0xFF,    //    0023        # # # # # # # # 
    0xFF,    //    0024        # # # # # # # # 
    0xFF,    //    0025        # # # # # # # # 
    0x80,    //    0026        # . . . . . . . 
    0xBE,    //    0027        # . # # # # # . 
    0xBE,    //    0028        # . # # # # # . 
    0xBE,    //    0029        # . # # # # # . 
    0xC1,    //    002A        # # . . . . . # 
    0xFF,    //    002B        # # # # # # # # 
    0xFF,    //    002C        # # # # # # # # 
    0xFF,    //    002D        # # # # # # # # 
    0xFF,    //    002E        # # # # # # # # 
    0xFF,    //    002F        # # # # # # # # 
    0xFF,    //    0030        # # # # # # # # 
    0xFF,    //    0031        # # # # # # # # 
    0x80,    //    0032        # . . . . . . . 
    0xB6,    //    0033        # . # # . # # . 
    0xB6,    //    0034        # . # # . # # . 
    0xB6,    //    0035        # . # # . # # . 
    0xBE,    //    0036        # . # # # # # . 
    0xFF,    //    0037        # # # # # # # # 
    0xFF,    //    0038        # # # # # # # # 
    0xFF,    //    0039        # # # # # # # # 
    0xFF,    //    003A        # # # # # # # # 
    0xFF,    //    003B        # # # # # # # # 
    0xFF,    //    003C        # # # # # # # # 
    0xFF,    //    003D        # # # # # # # # 
    0x80,    //    003E        # . . . . . . . 
    0xF6,    //    003F        # # # # . # # . 
    0xF6,    //    0040        # # # # . # # . 
	0xF6,	//	0041		# # # # . # # . 
	0xFE,	//	0042		# # # # # # # . 
	0xFF,	//	0043		# # # # # # # # 
	0xFF,	//	0044		# # # # # # # # 
	0xFF,	//	0045		# # # # # # # # 
	0xFF,	//	0046		# # # # # # # # 
	0xFF,	//	0047		# # # # # # # # 
	0xFF,	//	0048		# # # # # # # # 
	0xFF,	//	0043		# # # # # # # # 
	0xFF,	//	0044		# # # # # # # # 
	0xFF,	//	0045		# # # # # # # # 
	0xFF,	//	0046		# # # # # # # # 
	0xFF,	//	0047		# # # # # # # # 
	0xFF,	//	0048		# # # # # # # #
    0xFF,	//	0047		# # # # # # # # 
	0xFF,	//	0048		# # # # # # # #      
};

void main(void)
{

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

while (1) {

    unsigned long i, offset = 4000000 + 65;           
    for (; offset >= 0; offset--) {
        int repeat = 0; 
        for (; repeat < 5; repeat++) {
            unsigned long scan = 0b01;                   
            PORTB = 0; //C9-C16
            for (i = 0; i < 8; i++) {
                PORTD = scan & 0xFF;
                PORTC = Code[(i + offset) % 80];
                scan <<= 1;
                delay_ms(2);         
            }     
            PORTD = 0; //C1-C8
            for (i = 8; i < 16; i++) {
                PORTB = scan >> 8;
                PORTC = Code[(i + offset) % 80];
                scan <<= 1;
                delay_ms(2);        
            }  
        }                        
    }

}

}
