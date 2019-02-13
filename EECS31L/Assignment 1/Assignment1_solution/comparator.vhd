library IEEE;
use IEEE.STD_LOGIC_1164.all;

ENTITY comparator IS
PORT (
	in_0 : IN STD_LOGIC ;
	in_1 : IN STD_LOGIC ;
	greater : OUT STD_LOGIC ;
	equal : OUT STD_LOGIC ;
	less : OUT STD_LOGIC
);
END comparator ;

architecture DataFlow of comparator is
BEGIN
	greater <= in_0 and (not in_1);
	equal <= ((not in_0) and (not in_1)) or (in_0 and in_1);
	less <= (not in_0) and in_1;
END DataFlow;
