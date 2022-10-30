;Slide No 81 & PAGE nO 277
;-------------------------
.include "m32def.inc"
.ORG	0
		RJMP	START
.ORG	OC1Aaddr
		RJMP	ROUTINE		

		;Initialize Stack Pointer
		;------------------------
START:	LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16
		
		;Intialize PORTC as OUTPUT
		;-------------------------
		LDI		R16,0xFF
		OUT		DDRC,R16
		
		;Initialize Timer 1
		;------------------
		LDI		R16,HIGH(31250-1)			;Set for 31250 counts
		OUT		OCR1AH,R16				;OCR1A1 = 31249
		LDI		R16,LOW(31250-1)
		OUT		OCR1AL,R16
		LDI		R16,0b00000000			;CTC: TOP=OCR1A
		OUT		TCCR1A,R16
		LDI		R16,0b00001100			;Prescaler = 256
		OUT		TCCR1B,R16
		LDI		R16,0b00010000			;Enable OCF1A interrupt
		OUT		TIMSK,R16
		SEI								;Enable global Interrupt

		LDI		R20,1

F:		OUT		PORTC,R20
		RJMP	F

ROUTINE:
		INC		R20
		RETI		
