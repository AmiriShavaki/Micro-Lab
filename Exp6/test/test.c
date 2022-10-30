#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

void main(void)
{
// Declare your local variables here
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
lcd_gotoxy(5,0);
lcd_putchar('I');
lcd_gotoxy(7,0);
lcd_putchar('U');
lcd_gotoxy(9,0);
lcd_putchar('S');
lcd_gotoxy(11,0);
lcd_putchar('T');

lcd_gotoxy(5,1);
lcd_puts("MIC LAB");


while (1)
      {
      // Place your code here

      }
}
