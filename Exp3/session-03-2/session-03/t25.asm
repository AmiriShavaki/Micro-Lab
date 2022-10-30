;Slide No 123 & Page No 295
;--------------------------
.include "m32def.inc"
		LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16
		;Intialize PORTD as OUTPUT
		;-------------------------
		LDI		R16,0b00100000		;Output OC1A 
		OUT		DDRD,R16
		;Initialize Timer 1
		;------------------
		LDI		R16,HIGH(749)			;fREQUENCY: 5 KHz
		OUT		OCR1AH,R16				;OCR1A1 = 749
		LDI		R16,LOW(749)
		OUT		OCR1AL,R16
		LDI		R16,0b10000010	
		OUT		TCCR1A,R16
		LDI		R16,0b00010010			
		OUT		TCCR1B,R16
		LDI		R16,HIGH(999)
		OUT		ICR1H,R16
		LDI		R16,LOW(999)
		OUT		ICR1L,R16
HERE:	RJMP	HERE

