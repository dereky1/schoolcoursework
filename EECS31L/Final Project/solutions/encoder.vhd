library IEEE;
use IEEE.STD_LOGIC_1164.all;

ENTITY encoder IS
PORT (
	in_0 : IN STD_LOGIC ;
	in_1 : IN STD_LOGIC ;
	enable : IN STD_LOGIC ;
	f : OUT STD_LOGIC
);
END encoder ;

architecture DataFlow of encoder is
BEGIN
		f <= (enable) and (in_1) and (not in_0);
END DataFlow;