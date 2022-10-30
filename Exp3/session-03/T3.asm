.include "m32def.inc"
.ORG	0
		RJMP	BEGIN
.ORG	OVF0addr
		RJMP	ROUTINE

BEGIN:	LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16

		;Initialize PIN0 PORTD as OUTPUT
		;-------------------------------
		LDI		R16,0b00000001
		OUT		DDRD,R16
		
		;Initialize Timer 0
		;------------------
		LDI		R16,156
		OUT		TCNT0,R16
		LDI		R16,2
		OUT		TCCR0,R16
		LDI		R16,1
		OUT		TIMSK,R16
		SEI
		
		LDI		R16,01
HERE:	OUT		PORTD,R16
		RJMP	HERE


ROUTINE:
		LDI		R18,156
		OUT		TCNT0,R18
		LDI		R17,1
		EOR		R16,R17
		RETI
