
#include <mega32.h>
#include <delay.h>

const unsigned char Code[]=
{
	0x04,	//	0001		. . . . . # . . 
	0x0A,	//	0002		. . . . # . # . 
	0x11,	//	0003		. . . # . . . # 
	0x11,	//	0004		. . . # . . . # 
	0x1F,	//	0005		. . . # # # # # 
	0x11,	//	0006		. . . # . . . # 
	0x11 	//	0007		. . . # . . . # 
};
void main(void)
{
// Declare your local variables here
unsigned char Row,Scan;
DDRC=0xFF;
DDRD=0xFF;

while (1)
      {
      // Place your code here
      Scan = 0b11111110;
      for (Row=0; Row<7; Row++)
      {
            PORTD = Scan;
            Scan = Scan << 1;
            Scan = Scan | 1;
            PORTC = Code[Row];
            delay_ms(5);
            //PORTC = 0x00;
      }
      }
}
