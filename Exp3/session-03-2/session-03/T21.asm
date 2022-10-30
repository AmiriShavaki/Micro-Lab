;Slide No 103 & Page No 287
;--------------------------
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
		LDI		R16,0b00100000		;Output OC1A 
		OUT		DDRD,R16
		;Initialize Timer 1
		;------------------
		LDI		R16,HIGH(750-1)			;Set for 500 counts
		OUT		OCR1AH,R16				;OCR1A1 = 499
		LDI		R16,LOW(750-1)
		OUT		OCR1AL,R16
		LDI		R16,0b10000010			;FAST PWM: TOP=ICR1
		OUT		TCCR1A,R16
		LDI		R16,0b00011010			;Prescaler = 8
		OUT		TCCR1B,R16				;OC1A output: Non Inverted
  		
		LDI		R16,HIGH(1000-1)
		OUT		ICR1H,R16
		LDI		R16,LOW(1000-1)			;TOP = 999
		OUT		ICR1L,R16								

HERE:	RJMP	HERE

