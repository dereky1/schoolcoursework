	.ORIG x3000

	ADD R3, R3, #1

	ADD R4, R4, #1			
	
	AND R1, R1, #0
	
	ADD R1, R1, #-10
	
	ADD R1, R1, #-10

	ADD R1, R1, #-10

	ADD R1, R1, #-10

	ADD R1, R1, #-9

	AND R5, R5, #0

RESTART	LD R5, COUNTER

	TRAP x23
	
	ADD R0, R0, R1
	
	BRp LOOP

OVER	AND R0, R0, #0
	
	LEA R0, CClock	;5Degrees

	TRAP x22
	
	AND R0, R0, #0 

	ADD R0, R0, xA

	TRAP x21

	LEA R0, CClock2	;10Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, CClock3	;15Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, CClock4	;20Degrees

	TRAP x22
	
	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21
	
	ADD R5, R5, #-1

	BRp OVER

	LEA R0, Clock3	;-5Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock4	;-10Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock	;-15Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock2	;-20Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock3	;-25Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA
	
	TRAP x21

	LEA R0, Clock4	;-30Degrees

	TRAP x22
	
	ADD R5, R5, #0

	BRz RESTART

LOOP	AND R0, R0, #0

	LEA R0, Clock	;-5Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock2	;-10Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock3	;-15Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock4	;-20Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock	;-25Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock2	;-30Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock3	;-35Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock4	;-40Degrees

	TRAP x22

	AND R0, R0, #0

	ADD R0, R0, xA

	TRAP x21

	LEA R0, Clock	;-45Degrees

	TRAP x22

	ADD R3, R3, R4

	BRp RESTART

CClock .STRINGZ "1100"

CClock2 .STRINGZ "1001"

CClock3 .STRINGZ "0011"

CClock4 .STRINGZ "0110"

Clock .STRINGZ "1100"

Clock2 .STRINGZ "0110"

Clock3 .STRINGZ "0011"

Clock4 .STRINGZ "1001"

COUNTER .FILL x0003

	.END