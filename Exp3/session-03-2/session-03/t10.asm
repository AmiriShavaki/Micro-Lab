;Slide No 52
;----------- 
.include "m32def.inc"
		LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16

		LDI		R16,0b00001000	;0X08
		OUT		DDRB,R16

		LDI		R16,0b00011010
		OUT		TCCR0,R16

		LDI		R16,100-1
		OUT		OCR0,R16

HERE:	RJMP	HERE

