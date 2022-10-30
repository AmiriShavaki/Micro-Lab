#include <mega32.h>
#include <delay.h>
// Graphic LCD functions
#include <glcd.h>

// Font used for displaying text
// on the graphic LCD
#include <font5x7.h>

void main(void)
{
// Declare your local variables here
int i=500;
// Graphic LCD initialization data
GLCDINIT_t glcd_init_data;

// Graphic LCD initialization
// The KS0108 connections are specified in the
// Project|Configure|C Compiler|Libraries|Graphic LCD menu:
// DB0 - PORTA Bit 0
// DB1 - PORTA Bit 1
// DB2 - PORTA Bit 2
// DB3 - PORTA Bit 3
// DB4 - PORTA Bit 4
// DB5 - PORTA Bit 5
// DB6 - PORTA Bit 6
// DB7 - PORTA Bit 7
// E     - PORTB Bit 0
// RD/WR - PORTB Bit 1
// RS    - PORTB Bit 2
// /RST  - PORTB Bit 3
// CS1   - PORTB Bit 4
// CS2   - PORTB Bit 5

// Specify the current font for displaying text
glcd_init_data.font=font5x7;
// No function is used for reading
// image data from external memory
//glcd_init_data.readxmem=NULL;
// No function is used for writing
// image data to external memory
//glcd_init_data.writexmem=NULL;

glcd_init(&glcd_init_data);
glcd_clear();
delay_ms(50);
// Sets the horizontal and vertical text justification values.
//glcd_settextjustify(3,5);
glcd_outtext("Iran Univ of Science & Tech");
delay_ms(i);
glcd_clear();
while (1)
      {
      
      // Draw various styles of lines 
      // Line thickness: 1 pixel 
      glcd_setlinestyle(1,GLCD_LINE_SOLID);
      glcd_line(0,45,127,45);
      delay_ms(i);
      glcd_clear();
    
      glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL);
      glcd_line(0,0,0,63);
      glcd_line(0,0,127,0);
      glcd_line(0,63,127,63);
      glcd_line(127,63,127,0);
      glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE);
      glcd_line(127,63,0,0);
      glcd_line(0,63,127,0);
      delay_ms(i);  
      glcd_clear(); 
      
      // Line thickness: 2 pixels 
      
      glcd_setlinestyle(2,GLCD_LINE_SOLID);
      glcd_line(10,45,115,45);
      glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL);
      glcd_line(10,30,115,30);
      glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE);
      glcd_line(10,15,115,15);
      delay_ms(i);
      glcd_clear();
      
      // Draw a circle with line thickness: 1 pixel 
      
      glcd_setlinestyle(1,GLCD_LINE_SOLID);
      glcd_circle(63,31,30);      
      delay_ms(i);
      glcd_clear();
      
      // Draw a circle with line thickness: 4 pixels 
      glcd_setlinestyle(4,GLCD_LINE_SOLID);
      glcd_circle(63,31,30);
      delay_ms(i);
      glcd_clear();
      
      // Draws and fills a circle at specified center coordinates using the current
      // fill color.
      glcd_setlinestyle(1,GLCD_LINE_SOLID);
      glcd_fillcircle(63,31,30);
      delay_ms(i);
      glcd_clear();
      
      // The angles are measured starting from the 3 o'clock counter-clockwise.
      
      glcd_arc(63,31,0,270,30);
      delay_ms(i);
      glcd_clear();
      
      // Draws a pie slice at specified center coordinates using the
      // current foreground color and line thickness.
      // After that the pie slice is filled with the current fill color.
      // The angles are measured starting from from 3 o'clock counter-clockwise.
      
      //glcd_pieslice(63,31,299,359,30);
      //delay_ms(i);
      //glcd_clear();
                        
      // Draw some lines 
      glcd_setlinestyle(1,GLCD_LINE_SOLID);
      glcd_line(0,0,127,63);
      glcd_line(0,63,127,0);
      glcd_line(63,0,63,63);
      glcd_line(0,31,127,31);
      delay_ms(i);                                        
      glcd_clear();
      
      // Draws a rectangle using the current line thickness, bit pattern and drawing color.
      
      glcd_rectangle(10,10,118,54);
      glcd_rectangle(20,20,108,44);
      delay_ms(i);
      glcd_clear();
      
      // Draws a rectangle using the current line thickness, bit pattern and drawing color.
      
      glcd_rectrel(10,10,108,44);
      glcd_rectrel(20,20,88,24);
      delay_ms(i);
      glcd_clear();
      
      // Draws a rectangle with rounded corners using the current line thickness
      // and drawing color.
      
      glcd_rectround(10,10,108,44,5);
      glcd_rectround(20,20,88,24,3);
      delay_ms(i);
      glcd_clear();
      
      // Draws a filled-in rectangular bar, using absolute coordinates.
      // The bar is filled using the current fill pattern and fill color.
      // No outline is drawn.
      glcd_bar(10,0,30,60);
      glcd_bar(40,0,60,45);
      glcd_bar(70,0,90,30);
      glcd_bar(100,0,120,15);
      delay_ms(i);
      glcd_clear();
                       
      // Draws a filled-in rectangular bar., using relative coordinates.
      // The bar is filled using the current fill pattern and fill color.
      // No outline is drawn.
      
      glcd_barrel(10,0,10,60);
      glcd_barrel(30,0,10,45);
      glcd_barrel(50,0,10,30);
      glcd_barrel(70,0,10,15);
      delay_ms(i);
      glcd_clear();
      }

}
