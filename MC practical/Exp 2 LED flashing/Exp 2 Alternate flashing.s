ORG 0000H
START:  MOV P0,#0AAH
        CALL DELAY
        MOV P0,#55H
        CALL DELAY
        SJMP START
DELAY:  MOV R0,#0FH
L3:     MOV R2,#0FFH
L1:     MOV R1,#0FFH
L2:     DJNZ R1,L2
        DJNZ R2,L1
        DJNZ R0,L3
        RET
END
