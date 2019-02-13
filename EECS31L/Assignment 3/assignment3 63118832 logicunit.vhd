library ieee;
use ieee.std_logic_1164.all;

ENTITY logic_UNIT IS
PORT (
	A : IN STD_LOGIC ;
	B : IN STD_LOGIC ;
	cin : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0) ;
	sum_TWO : OUT STD_LOGIC ;
	cout_TWO : OUT STD_LOGIC 
	);
END logic_UNIT ;

ARCHITECTURE logic_arch of logic_UNIT is 
begin
	sum_TWO <= (A AND B) WHEN opsel = "000" ELSE
		(A OR B) WHEN opsel = "001" ELSE
		(A XOR B) WHEN opsel = "010" ELSE
		(NOT A) WHEN opsel = "011" ELSE 
		cin WHEN opsel = "101" ;
	cout_TWO <= '0' ;
END logic_arch ;