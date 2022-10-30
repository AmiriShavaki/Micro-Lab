.include "m32def.inc"

		LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16

		LDI		R16,0b00000001
		OUT		DDRD,R16
		
BEGIN:	LDI		R16,01
		OUT		PORTD,R16
		CALL	DELAY_100
		LDI		R16,00
		OUT		PORTD,R16
		CALL	DELAY_100
		RJMP	BEGIN


DELAY_100:
		LDI		R17,0
M:		LDI		R16,6
		OUT		TCNT0,R16
		LDI		R16,0b00000011
		OUT		TCCR0,R16
S:		IN		R16,TIFR
		ANDI	R16,0b00000001
		BREQ	S
		LDI		R16,0
		OUT		TCCR0,R16
		LDI		R16,01
		OUT		TIFR,R16
		INC		R17
		CPI		R17,5
		BRNE	M
		RET
