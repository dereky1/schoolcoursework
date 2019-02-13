	.ORIG x3000

	AND R1, R1, #0

	AND R2, R2, #0

	AND R3, R3, #0
	
	AND R4, R4, #0

	AND R5, R5, #0

	ADD R1, R1, #1
	
	ADD R2, R2, #2

	ADD R3, R3, #3
 	
	ADD R4, R4, #4 
	
	ADD R5, R5, #5

	AND R0, R0, #0
	
	ADD R0, R2, R1

	ADD R0, R3, R0

	ADD R0, R4, R0

	ADD R0, R5, R0

	TRAP x21

	TRAP x25
	
	.END 