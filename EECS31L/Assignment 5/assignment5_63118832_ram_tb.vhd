LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY RAM_TB IS
END RAM_TB;

ARCHITECTURE RAM_TEST OF RAM_TB IS
COMPONENT ram IS
PORT(
addr : IN std_logic_vector (10 DOWNTO 0);
rw : IN std_logic ;
csb : IN std_logic ;
oeb : IN std_logic ;
dataIO : INOUT std_logic_vector (31 DOWNTO 0)
);
END component ram;
SIGNAL addr_tb: STD_LOGIC_VECTOR (10 DOWNTO 0);
SIGNAL rw_tb, csb_tb, oeb_tb : STD_LOGIC;
SIGNAL dataIO_tb : STD_LOGIC_VECTOR (31 DOWNTO 0);

BEGIN
	ram_INST: ram PORT MAP(addr_tb, rw_tb, csb_tb, oeb_tb, dataIO_tb);
	PROCESS 
	BEGIN		
		addr_tb <= "00000000000";
		dataIO_tb <= "00000000000000000000000000000000";
		csb_tb <= '0';
		oeb_tb <= '0'; 
		rw_tb <= '0';
		wait for 10 ns;
		addr_tb <= "00000000001";
		dataIO_tb <= "00000000000000000000000000000001";
		wait for 10 ns; 
		addr_tb <= "00000000011";
		dataIO_tb <= "00000000000000000000000000000011";
		wait for 10 ns; 
		rw_tb <= '1';
		wait for 10 ns; 
		addr_tb <= "00000000001";
		dataIO_tb <= "00000000000000000000000000000001";
		wait for 10 ns; 
		addr_tb <= "00000000000";
		dataIO_tb <= "00000000000000000000000000000000";
		wait for 10 ns; 
		oeb_tb <= '1';
		dataIO_tb <= "00000000000000000000000000000001";

	END PROCESS;

END RAM_TEST;