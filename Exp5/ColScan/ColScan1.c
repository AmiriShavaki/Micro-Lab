
#include <mega32.h>
#include <delay.h>

const unsigned char Code[]=
{
	0x83,	//	0001		# . . . . . # # 
	0xED,	//	0002		# # # . # # . # 
	0xEE,	//	0003		# # # . # # # . 
	0xED,	//	0004		# # # . # # . # 
	0x83,	//	0005		# . . . . . # # 
	0xFF,	//	0006		# # # # # # # # 
	0xFF,	//	0007		# # # # # # # # 
	0xFF 	//	0008		# # # # # # # # 
};
void main(void)
{
// Declare your local variables here
unsigned char Col,Scan;
DDRC=0xFF;
DDRD=0xFF;

while (1)
      {
      // Place your code here
      Scan = 0b00000001;
      for (Col=0; Col<5; Col++)
      {
            PORTC = Scan;
            Scan = Scan << 1;
            PORTD = Code[Col];
            delay_ms(10);
            //PORTC = 0x00;
      }
      }
}
