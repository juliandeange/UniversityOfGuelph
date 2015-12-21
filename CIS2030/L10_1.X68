*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description: Prints remainder = number initially in D0 (One digit at a time)
*-----------------------------------------------------------
    ORG    $8000
START:                  ; first instruction of program

    MOVE    #3,D0
    MOVE.W  #1234,D5
    MOVE.W  D5,-(SP)
    JSR DISPLAY
    TRAP    #14
    
DISPLAY
    LINK    A0,#-4 
    MOVE.W  8(A0),D2 ;D2 has N
    CMP     #0,D2
    BEQ     RETURN
    
    CLR.L   D1
    MOVE.W  D2,D1   ;D1 has N - remainder
    DIVS    #10,D1
    MOVE.W  D1,-4(A0)
    SWAP    D1   
    MOVE.W  D1,-2(A0)
    JSR     DISPLAY

    TRAP    #15
    
RETURN  
    CLR.L   D1
    UNLK    A0
    MOVE.W  -2(A0),D1
    RTS           
    



    END    START        ; last line of source



*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
