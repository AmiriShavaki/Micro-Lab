;Slide No 90 & Page No 281
;-------------------------
.include "m32def.inc"
.ORG	0
		RJMP	START

		;Initialize Stack Pointer
START:	LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16
		
		;Intialize PORTD as OUTPUT
		LDI		R16,0b00110000		;Output OC1A and OC1B
		OUT		DDRD,R16
		
		;Initialize Timer 1
		LDI		R16,HIGH(499)			;Set for 500 counts
		OUT		OCR1AH,R16				;OCR1A1 = 499
		LDI		R16,LOW(499)
		OUT		OCR1AL,R16
		LDI		R16,HIGH(99)			;Set for 100 counts
		OUT		OCR1BH,R16				;OCR1B1 = 99
		LDI		R16,LOW(99)
		OUT		OCR1BL,R16
		LDI		R16,0b01010000			;CTC: TOP=OCR1A
		OUT		TCCR1A,R16
		LDI		R16,0b00001010			;Prescaler = 8
		OUT		TCCR1B,R16				;OC1A output: Toggle
  										;OC1B output: Toggle
HERE:	RJMP	HERE

