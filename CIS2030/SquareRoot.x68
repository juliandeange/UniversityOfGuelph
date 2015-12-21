*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG    $8000
START:                  ; first instruction of program
       
    MOVE.W    N,D0
    MOVE.W    O,D1
    MOVE.W    C,D2       

WHILE    CMP #0,D0
         BLE EXIT
    
    SUB.W   D1,D0
    ADD     #2,D1
    ADD     #1,D2
    BRA     WHILE

EXIT    TRAP    #14


    
    ORG     $9000
    
N   DC.W    32
C   DC.W    0
O   DC.W    1

    END    START        ; last line of source






*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
