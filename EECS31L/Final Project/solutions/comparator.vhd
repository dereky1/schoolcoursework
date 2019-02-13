library IEEE;
use IEEE.STD_LOGIC_1164.all;

ENTITY comparator IS
PORT (
	in_0 : IN STD_LOGIC_vector (31 downto 0) ;
	in_1 : IN STD_LOGIC_vector (31 downto 0) ;
	greater : OUT STD_LOGIC ;
	equal : OUT STD_LOGIC ;
	less : OUT STD_LOGIC
);
END comparator ;

architecture DataFlow of comparator is
BEGIN
	process(in_0, in_1)
	begin	
		looper: for i in 0 to 31 loop
			if (in_0(i) = '1' and in_1(i) = '0') then
				greater <= '1';
				less <= '0';
				equal <= '0';
				exit looper;
			elsif (in_0(i) = '0' and in_0(i) = '1') then
				less <= '1';
				greater <= '0';
				equal <= '0';
				exit looper;
			elsif (in_0(31) = in_1(31)) then
				equal <= '1';
				greater <= '0';
				less <= '0';
				exit looper;
			end if;
		end loop;
	end process;
END DataFlow;
