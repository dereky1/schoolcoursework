
library ieee;
use ieee.std_logic_1164.all;

ENTITY ALU_1BIT_TB IS
END ALU_1BIT_TB;

ARCHITECTURE TEST OF ALU_1BIT_TB IS
COMPONENT alu_1bit
	PORT (
	A : IN STD_LOGIC ;
	B : IN STD_LOGIC ;
	cin : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
	mode : IN STD_LOGIC ;
	output : OUT STD_LOGIC ;
	cout : OUT STD_LOGIC
	);
END component alu_1bit;
SIGNAL A_tb,B_tb,cin_tb, mode_tb, output_tb, cout_tb: STD_LOGIC;
SIGNAL opsel_tb: STD_LOGIC_VECTOR (2 DOWNTO 0);
BEGIN
	alu_INST: alu_1bit PORT MAP(A_tb, B_tb, cin_tb, opsel_tb, mode_tb, output_tb, cout_tb);
	TB: PROCESS
	BEGIN
		mode_tb <= '0';	--arithmetic operation
		A_tb <= '1';
		B_tb <= '0';
		cin_tb <= '0';
		opsel_tb <= "000"; --add
		wait for 10 ns; 
		opsel_tb <= "001";	--sub with borrowed carry	
		wait for 10 ns; 
		opsel_tb <= "010";	--move
		wait for 10 ns; 
		cin_tb <= '1';
		opsel_tb <= "011";	--sub
		wait for 10 ns; 
		
		opsel_tb <= "100";	--increment
		wait for 10 ns; 
		cin_tb <= '0';
		opsel_tb <= "101";	--DEcrement
		wait for 10 ns; 
		cin_tb <= '1';
		opsel_tb <= "110";	--add & increment
		wait for 10 ns;
		cin_tb <= '0'; 
		mode_tb <= '1';		--------Logic operations starts at 70ns
		opsel_tb <= "000";	--AND
		wait for 10 ns; 
		opsel_tb <= "001";	--OR	
		wait for 10 ns; 
		opsel_tb <= "010";	--XOR
		wait for 10 ns; 
		opsel_tb <= "011";	--NOT
		wait for 10 ns;
		opsel_tb <= "101";	--SHL
		wait for 10 ns;
		


		mode_tb <= '0';	-- Second Round:::arithmetic operation
		A_tb <= '1';
		B_tb <= '1';
		cin_tb <= '0';
		opsel_tb <= "000"; --add
		wait for 10 ns; 
		opsel_tb <= "001";	--sub with borrowed carry	
		wait for 10 ns; 
		opsel_tb <= "010";	--move
		wait for 10 ns; 
		cin_tb <= '1';
		opsel_tb <= "011";	--sub
		wait for 10 ns; 
		opsel_tb <= "100";	--increment
		wait for 10 ns; 
		cin_tb <= '0';
		opsel_tb <= "101";	--DEcrement
		wait for 10 ns; 
		cin_tb <= '1';
		opsel_tb <= "110";	--add & increment
		wait for 10 ns; 
		cin_tb <= '0';
		mode_tb <= '1';		--------Logic operations starts at 70ns
		opsel_tb <= "000";	--AND
		wait for 10 ns; 
		opsel_tb <= "001";	--OR	
		wait for 10 ns; 
		opsel_tb <= "010";	--XOR
		wait for 10 ns; 
		opsel_tb <= "011";	--NOT
		wait for 10 ns;
		opsel_tb <= "101";	--SHL
		wait for 10 ns;
		

	assert false report "finish" severity failure;
	END PROCESS;
END TEST;