LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY ram IS
PORT(
addr : IN std_logic_vector (10 DOWNTO 0);
rw : IN std_logic ;
csb : IN std_logic ;
oeb : IN std_logic ;
dataIO : INOUT std_logic_vector (31 DOWNTO 0));
END ram;
	
ARCHITECTURE ram_arch OF ram IS

COMPONENT mem_block IS
port (
addr : IN std_logic_vector (10 DOWNTO 0);
rw : IN std_logic ;
cs : IN std_logic ;
oe : IN std_logic ;
dataIO : INOUT std_logic_vector (31 DOWNTO 0));
END COMPONENT mem_block;  
SIGNAL dataIO1, dataIO2, dataIO3, dataIO4 : STD_LOGIC_VECTOR (31 DOWNTO 0); 
SIGNAL sel : STD_LOGIC_VECTOR (1 DOWNTO 0);

BEGIN
	m1: mem_block PORT MAP(addr, rw, csb, oeb, dataIO => dataIO1); 
	m2: mem_block PORT MAP(addr, rw, csb, oeb, dataIO => dataIO2);
	m3: mem_block PORT MAP(addr, rw, csb, oeb, dataIO => dataIO3);
 	m4: mem_block PORT MAP(addr, rw, csb, oeb, dataIO => dataIO4);
	PROCESS(addr, rw, csb, oeb, dataIO)
	VARIABLE x: STD_LOGIC_VECTOR (31 DOWNTO 0);
 	BEGIN
		sel <= addr(10 DOWNTO 9);
		CASE sel IS
			WHEN "00" => x := dataIO1;
			WHEN "01" => x := dataIO2;
			WHEN "10" => x := dataIO3;
			WHEN "11" => x := dataIO4;
			WHEN OTHERS => NULL;
		END CASE;
		dataIO <= x;
	END PROCESS;

END ram_arch;
