ORG 0000H
START:  
        MOV A,#00H
        MOV P0,A
        CALL DELAY
        SJMP COUNT

COUNT:  
        ADD A,#01H
        CJNE A,#0AH,SKIP_RESET
        MOV A,#00H
SKIP_RESET:
        MOV P0,A
        CALL DELAY
        SJMP COUNT

DELAY:  
        MOV R0,#0FH
L3:     MOV R2,#0FFH
L1:     MOV R1,#0FFH
L2:     DJNZ R1,L2
        DJNZ R2,L1
        DJNZ R0,L3
        RET
END

