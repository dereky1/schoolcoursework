library ieee;
use ieee.std_logic_1164.all;

ENTITY alu_1bit IS
PORT (
A : IN STD_LOGIC ;
B : IN STD_LOGIC ;
cin : IN STD_LOGIC ;
opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
mode : IN STD_LOGIC ;
output : OUT STD_LOGIC ;
cout : OUT STD_LOGIC
);
END alu_1bit ;

ARCHITECTURE ALU_arch of alu_1bit is

COMPONENT circuit_B IS
PORT(
	B : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0) ;
	sum_ONE : OUT STD_LOGIC;
	cout_ONE : OUT STD_LOGIC;
	Free_B : OUT STD_LOGIC 
	); 
END COMPONENT circuit_B ;
SIGNAL sum_ONE, cout_ONE, Free_B : STD_LOGIC ;

COMPONENT arith_UNIT IS
PORT (
	A : IN STD_LOGIC ;
	B : IN STD_LOGIC ;
	cin : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0) ;
	sum_ZERO : OUT STD_LOGIC ;
	cout_ZERO : OUT STD_LOGIC 
	);
END COMPONENT arith_UNIT ;
SIGNAL sum_ZERO, cout_ZERO : STD_LOGIC;

COMPONENT logic_UNIT IS
PORT (
	A : IN STD_LOGIC ;
	B : IN STD_LOGIC ;
	cin : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0) ;
	sum_TWO : OUT STD_LOGIC ;
	cout_TWO : OUT STD_LOGIC 
	);
END COMPONENT logic_UNIT ;
SIGNAL sum_TWO, cout_TWO : STD_LOGIC;

begin

	circ_b : circuit_B PORT MAP (B, opsel, sum_ONE, cout_ONE, Free_B);
	arith_u : arith_UNIT PORT MAP (A, B, cin, opsel, sum_ZERO, cout_ZERO);
	log_u : logic_UNIT PORT MAP (A, B, cin, opsel, sum_TWO, cout_TWO);

	
	output <= sum_ZERO WHEN mode = '0' ELSE sum_TWO;
	cout <= cout_ZERO WHEN mode = '0' ELSE cout_TWO;

END ALU_arch;