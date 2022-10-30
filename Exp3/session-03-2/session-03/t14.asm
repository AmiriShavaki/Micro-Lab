;Slide No 85
;-----------
.include "m32def.inc"
.ORG	0
		RJMP	START
.ORG	OVF1addr
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
		LDI		R16,HIGH(65536-31250)			;Set for 31250 counts
		OUT		TCNT1H,R16				;TCNT1 = 34256
		LDI		R16,LOW(65536-31250)
		OUT		TCNT1L,R16
		LDI		R16,0b00000000
		OUT		TCCR1A,R16
		LDI		R16,0b00000100			;Prescaler = 256
		OUT		TCCR1B,R16
		LDI		R16,0b00000100			;Enable TOV1 interrupt
		OUT		TIMSK,R16
		SEI								;Enable global Interrupt

		LDI		R20,1
F:		OUT		PORTC,R20
		RJMP	F

ROUTINE:
		LDI		R16,HIGH(65536-31250)			;Set for 31250 counts
		OUT		TCNT1H,R16				;TCNT1 = 34256
		LDI		R16,LOW(65536-31250)
		OUT		TCNT1L,R16
		INC		R20
		RETI		
