*-----------------------------------------------------------
* Title      : L5_5
* Written by : Julian De Angelis
* Date       : October 21 2015
* Description: S = 3Y + 2X  Simple Equation
*-----------------------------------------------------------

Y	EQU	$8002
Z	EQU	$8006

    ORG    $8000
START:                  ; first instruction of program

	MOVE.W	#2,Y
	MOVE.W	Y,D0
	MULS	#3,D0

	MOVE.W	#1,Z
	MOVE.W	Z,D1
	MULS	#2,D1

	ADD	D0,D1
	MOVE.W	D1,S

	TRAP	#14

    ORG	    $9000
X	DC.W	1
S	DS.W	1

    END START


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
