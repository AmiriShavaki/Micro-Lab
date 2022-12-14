; Mahdi Amiri Shavaki
; 98522148

.include "m32def.inc"
		LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16

		LDI		R16,0xFF
		OUT		DDRC,R16		;PORTC as output
		OUT		DDRD,R16		;PORTD as output
		OUT		PORTA,R16		;Enabling Pullup Resistor on PORTA 
		LDI		R16,0x00
		OUT		DDRA,R16		;PORTA as input

INIT0:	LDI		R20,0
		LDI		R21,0
		LDI		R22,0
		LDI		R23,0
		RJMP	DISP

INIT9:	LDI		R20,9
		LDI		R21,9
		LDI		R22,9
		LDI		R23,9
		RJMP	DISP

MAIN_LOOP:
		IN		R16,PINA 		;read portA digit0
		MOV		R17,R16			;store as R17
		ANDI	R17,0b00000001	;remove other digits
		CPI		R17,0			;detect mode
		BRNE	DECREMENT

INCREMENT:
		CPI		R20,9
		BRLO	INC1
		CPI		R21,9
		BRLO	INC2
		CPI		R22,9
		BRLO	INC3
		CPI		R23,9
		BRLO	INC4
		RJMP	INIT0

DECREMENT:
		CPI		R20,1
		BRSH	DEC1
		CPI		R21,1
		BRSH	DEC2
		CPI		R22,1
		BRSH	DEC3
		CPI		R23,1
		BRSH	DEC4
		RJMP	INIT9

INC1:
		INC		R20
		RJMP	DISP

DEC1:
		DEC		R20
		RJMP	DISP

INC2:
		LDI		R20,0
		INC		R21
		RJMP	DISP

DEC2:
		LDI		R20,9
		DEC		R21
		RJMP	DISP

INC3:
		LDI		R20,0
		LDI		R21,0
		INC		R22
		RJMP	DISP

DEC3:
		LDI		R20,9
		LDI		R21,9
		DEC		R22
		RJMP	DISP

INC4:
		LDI		R20,0
		LDI		R21,0
		LDI		R22,0
		INC		R23
		RJMP	DISP

DEC4:
		LDI		R20,9
		LDI		R21,9
		LDI		R22,9
		DEC		R23
		RJMP	DISP

DISP:   LDI		R30,0xFF
DISPLOOP:
		LDI		R16,0b11110111	;displaying Yekan
		OUT		PORTD,R16
		MOV		R16,R20
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY

		LDI		R16,0b11111011	;displaying Dahgan
		OUT		PORTD,R16
		MOV		R16,R21
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY

		LDI		R16,0b11111101	;displaying Sadgan
		OUT		PORTD,R16
		MOV		R16,R22
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY

		LDI		R16,0b11111110	;displaying Hezargan
		OUT		PORTD,R16
		MOV		R16,R23
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		
		DEC		R30
		BRNE	DISPLOOP

		RJMP	MAIN_LOOP

DELAY:	LDI		R17,0x01
L1:		LDI		R18,0x01
L2:		LDI		R19,0xFF
L3:		DEC		R19
		BRNE	L3
		DEC		R18
		BRNE	L2
		DEC		R17
		BRNE	L1
		RET

CONVERT:				;converts a digit to 7seg code 
		CPI		R16,0
		BRNE	C1
		LDI		R16,0x3F
		RET
C1:		CPI		R16,1
		BRNE	C2
		LDI		R16,0x06
		RET
C2:		CPI		R16,2
		BRNE	C3
		LDI		R16,0x5B
		RET
C3:		CPI		R16,3
		BRNE	C4
		LDI		R16,0x4F
		RET
C4:		CPI		R16,4
		BRNE	C5
		LDI		R16,0x66
		RET
C5:		CPI		R16,5
		BRNE	C6
		LDI		R16,0x6D
		RET
C6:		CPI		R16,6
		BRNE	C7
		LDI		R16,0x7D
		RET
C7:		CPI		R16,7
		BRNE	C8
		LDI		R16,0x07
		RET
C8:		CPI		R16,8
		BRNE	C9
		LDI		R16,0x7F
		RET
C9:		CPI		R16,9
		BRNE	C10
		LDI		R16,0x6F
C10:	RET
					
