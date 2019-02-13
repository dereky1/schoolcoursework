library ieee;
use ieee.std_logic_1164.all;

ENTITY ALU_32BIT_TB IS
END ALU_32BIT_TB;

ARCHITECTURE TEST OF ALU_32BIT_TB IS
COMPONENT alu_32bit
	PORT (
A : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
B : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
mode : IN STD_LOGIC ;
output : OUT STD_LOGIC_VECTOR (31 DOWNTO 0);
cout : OUT STD_LOGIC
	
	);
END component alu_32bit;


SIGNAL  mode_tb, cout_tb: STD_LOGIC;
SIGNAL A_tb,B_tb , output_tb: STD_LOGIC_vector(31 downto 0);

SIGNAL opsel_tb: STD_LOGIC_VECTOR (2 DOWNTO 0);
BEGIN
	alu_INST: alu_32bit PORT MAP(A_tb, B_tb, opsel_tb, mode_tb, output_tb, cout_tb);
	TB: PROCESS
	BEGIN
		mode_tb <= '0';	--arithmetic operation
		A_tb <= x"0f0f0f0f"; -- example inputs
		B_tb <= x"f0f0f0f0";
		opsel_tb <= "000"; --add
		wait for 10 ns; 
		opsel_tb <= "001";	--sub with borrowed carry	
		wait for 10 ns; 
		opsel_tb <= "010";	--move
		wait for 10 ns; 
		opsel_tb <= "011";	--sub
		wait for 10 ns; 
		
		opsel_tb <= "100";	--increment
		wait for 10 ns; 
		
		opsel_tb <= "101";	--DEcrement
		wait for 10 ns; 
		
		opsel_tb <= "110";	--add & increment
		wait for 10 ns;
		
		mode_tb <= '1';		--------Logic operations starts at 70ns
		opsel_tb <= "000";	--AND
		wait for 10 ns; 
		opsel_tb <= "001";	--OR	
		wait for 10 ns; 
		opsel_tb <= "010";	--XOR
		wait for 10 ns; 
		opsel_tb <= "011";	--NOT
		wait for 10 ns;
		opsel_tb <= "100";	--SHL
		wait for 10 ns;
		


		mode_tb <= '0';	-- Second Round:::arithmetic operation
		A_tb <= x"01234567";
		B_tb <= x"3456789a";
		
		opsel_tb <= "000"; --add
		wait for 10 ns; 
		opsel_tb <= "001";	--sub with borrowed carry	
		wait for 10 ns; 
		opsel_tb <= "010";	--move
		wait for 10 ns; 
		
		opsel_tb <= "011";	--sub
		wait for 10 ns; 
		opsel_tb <= "100";	--increment
		wait for 10 ns; 
		
		opsel_tb <= "101";	--DEcrement
		wait for 10 ns; 
		
		opsel_tb <= "110";	--add & increment
		wait for 10 ns; 
		
		mode_tb <= '1';		--------Logic operations starts at 70ns
		opsel_tb <= "000";	--AND
		wait for 10 ns; 
		opsel_tb <= "001";	--OR	
		wait for 10 ns; 
		opsel_tb <= "010";	--XOR
		wait for 10 ns; 
		opsel_tb <= "011";	--NOT
		wait for 10 ns;
		opsel_tb <= "100";	--SHL
		wait for 10 ns;
		

	assert false report "finish" severity failure;
	END PROCESS;
END TEST;
