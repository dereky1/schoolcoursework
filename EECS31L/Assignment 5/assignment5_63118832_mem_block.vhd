LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY mem_block IS
port (
addr : IN std_logic_vector (10 DOWNTO 0);
rw : IN std_logic ;
cs : IN std_logic ;
oe : IN std_logic ;
dataIO : INOUT std_logic_vector (31 DOWNTO 0));
END mem_block;

ARCHITECTURE mem_block_arch OF mem_block IS
BEGIN

	PROCESS (addr, rw, cs, oe)
	TYPE	ramm IS ARRAY ( 0 to ((2**9) - 1)) OF STD_LOGIC_VECTOR (31 DOWNTO 0); 
	VARIABLE ram_array : ramm; 
	VARIABLE addrr : STD_LOGIC_VECTOR (8 DOWNTO 0);
	BEGIN
	addrr := addr (8 DOWNTO 0);
	IF (cs = '1') THEN
		NULL;
	ELSIF (rw = '0') THEN 
		ram_array(to_integer(unsigned(addr))) := dataIO;
	ELSIF (oe = '1') THEN
		NULL;
	ELSE	
		dataIO <= ram_array(to_integer(unsigned(addr)));
	END IF;
	END PROCESS;

END mem_block_arch;