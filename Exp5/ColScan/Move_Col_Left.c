// must run on Matrix_5x7_Col
// Moving an Arrow 
#include <mega32.h>
#include <delay.h>

const unsigned char Code[]=
{
    0xFF,    //    0001        # # # # # # # # 
    0xFF,    //    0002        # # # # # # # # 
    0xFF,    //    0003        # # # # # # # # 
    0xFF,    //    0004        # # # # # # # # 
    0xFF,    //    0005        # # # # # # # #
     
    0xF7,    //    0006        # # # # . # # # 
    0xE3,    //    0007        # # # . . . # # 
    0xD5,    //    0008        # # . # . # . # 
    0xF7,    //    0009        # # # # . # # # 
    0xF7,    //    0010        # # # # . # # #
         
    0xFF,    //    0011        # # # # # # # # 
    0xFF,    //    0012        # # # # # # # # 
    0xFF,    //    0013        # # # # # # # # 
    0xFF,    //    0014        # # # # # # # # 
    0xFF,    //    0015        # # # # # # # # 
};

void main(void)
{
unsigned char Col,Scan,Refresh,Index,S;
DDRC=0xFF;
DDRD=0xFF;

while (1)
      {
      // Place your code here
      for (S=0; S<10; S++)
      {
        for (Refresh=1; Refresh<11; Refresh++)
        {
            Scan = 0b00000001;
            for (Col=0; Col<5; Col++)
            {
                Index = S + Col;
                PORTD = Code[Index];
                PORTC = Scan;
                delay_ms(4);
                Scan = Scan << 1;
                PORTC = 0x00;
            }
        }
      }
      }
}
