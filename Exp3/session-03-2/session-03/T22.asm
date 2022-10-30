;Slide No 105 & Page 289
.include "m32def.inc"
.ORG	0
		RJMP	START
		;Initialize Stack Pointer
		;------------------------
START:	LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16
		;Intialize PORTD as OUTPUT
		;-------------------------
		LDI		R16,0b00110000		;Output OC1A and OC1B
		OUT		DDRD,R16
		;Initialize Timer 1
		;------------------
		LDI		R16,HIGH(750-1)			;Dutuy Cycle 75%
		OUT		OCR1AH,R16				;OCR1A1 = 749
		LDI		R16,LOW(750-1)
		OUT		OCR1AL,R16
		LDI		R16,HIGH(250-1)			;Dutuy Cycle 25%
		OUT		OCR1BH,R16				;OCR1A1 = 249
		LDI		R16,LOW(250-1)
		OUT		OCR1BL,R16
		LDI		R16,0b10100010			;FAST PWM: TOP=ICR1
		OUT		TCCR1A,R16
		LDI		R16,0b00011010			;Prescaler = 8
		OUT		TCCR1B,R16				;OC1A OUTPUT: non-Inverted
										;OC1B OUTPUT: non-Inverted
  		LDI		R16,HIGH(999)
		OUT		ICR1H,R16
		LDI		R16,LOW(999)			;TOP = 999
		OUT		ICR1L,R16								
HERE:	RJMP	HERE

