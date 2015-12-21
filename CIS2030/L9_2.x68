*-----------------------------------------------------------
* Title      : L9_2
* Written by : Julian De Angelis
* Date       : Nov 19 2015
* Description: 5x^2 + 2xy - z^1 ... Final answer stored in D1
*-----------------------------------------------------------
    ORG    $8000
START:                  ; first instruction of program

    LEA $9100,SP
    MOVE.W  X,-(SP)
    MOVE.W  Y,-(SP)
    MOVE.W  Z,-(SP)
    JSR SQUARE
    LEA 4(SP),SP
    MOVE.W  -14(SP),D1

    ADD.W   -16(SP),D1
    SUB.W   -18(SP),D1

    TRAP    #14
    
SQUARE  LINK    A0,#-6
        MOVEM.L D0-D1/A0/A6,-(SP)
        MOVE.W  12(A0),D0   ;Move x to D0
        MOVE.W  D0,D1       
        MULS    D0,D0       ;x^2
        MULS    #5,D0       ;5x^2
        MOVE.W  D0,-2(A0)   
        CLR D0
        MOVE.W  10(A0),D0   Move y to D0
        MULS    D0,D1       ;xy
        MULS    #2,D1       ;2xy
        MOVE.W  D1,-4(A0)
        MOVE.W  8(A0),D2    ;Move z to D2
        MULS    D2,D2       ;z^2

       MOVE.W  D2,-6(A0)
        CLR D0
        CLR D2
        MOVE.W  -2(A0),D0
        ADD.W   -4(A0),D0
        SUB.W   -6(A0),D0   ;Calculate result
        MOVE.L  8(A0),A6    ;Push to memory
        MOVE.W  D0,A6
        MOVEM.L (SP)+,D0-D1/A0/A6
        UNLK    A0
        RTS

        
    ORG    $9000
X   DC.W    1
Y   DC.W    2
Z   DC.W    2


    END    START        ; last line of source







*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
