library ieee;
use ieee.std_logic_1164.all;

ENTITY arith_UNIT IS
PORT (
	A : IN STD_LOGIC ;
	B : IN STD_LOGIC ;
	cin : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0) ;
	sum_ZERO : OUT STD_LOGIC ;
	cout_ZERO : OUT STD_LOGIC 
	);
END arith_UNIT ;

ARCHITECTURE arith_arch of arith_UNIT is 
COMPONENT Circuity_B IS
PORT(
	B : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0) ;
	Free_B : OUT STD_LOGIC 
	); 
END COMPONENT Circuity_B ;
SIGNAL Free_B, sum_ONE, cout_ONE : STD_LOGIC ;
begin
	CB: Circuity_B PORT MAP ( B, opsel, Free_B );
	Free_B <= (NOT B AND opsel(0)) OR 
	(opsel(2) AND opsel(0)) OR 
	(B AND NOT opsel(2) AND NOT opsel(0)) OR 
	(opsel(1) AND NOT opsel(0) AND B);

	sum_ONE <= A XOR Free_B XOR cin;
	cout_ONE <= (A AND Free_B) OR (A AND cin) OR (Free_B AND cin) ;

	sum_ZERO <= A WHEN opsel = "010" ELSE 
		(A XOR '1') WHEN opsel = "100" ELSE sum_ONE ;
	cout_ZERO <= '0' WHEN opsel = "010" ELSE 
		'0' WHEN opsel = "101" ELSE cout_ONE ;
END arith_arch ;
