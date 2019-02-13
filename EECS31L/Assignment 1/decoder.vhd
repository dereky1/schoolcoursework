library IEEE;
use IEEE.STD_LOGIC_1164.all;

ENTITY decoder IS
PORT (
	in_0 : IN STD_LOGIC ;
	enable : IN STD_LOGIC ;
	f_0 : OUT STD_LOGIC ;
	f_1 : OUT STD_LOGIC
);
END decoder ;

architecture DataFlow of decoder is
BEGIN
	f_0 <= (not in_0) and (enable);
	f_1 <= (in_0) and (enable);
END DataFlow;