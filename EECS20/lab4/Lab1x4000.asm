 		.ORIG x4000

               LEA R0, LABEL1

	       TRAP x22

	       AND R0, R0, 0

	       ADD R0, R0, xA

	       TRAP x21

               LEA R0, LABEL2

               TRAP x22

	       AND R0, R0, 0
	
               ADD R0, R0, xA

	       TRAP x21
		
	       LEA R0, LABEL3

	       TRAP x22

	       TRAP x25

LABEL1 .STRINGZ "DEREK"

LABEL2 .STRINGZ "YANG"

LABEL3 .STRINGZ "COMPUTER ENGINEERING"

                .END
