library IEEE;
use IEEE.STD_LOGIC_1164.all;

ENTITY addsub IS
PORT(
	in_0 : IN std_logic ;
	in_1 : IN std_logic ;
	cin : IN std_logic ;
	AddOrSub : IN std_logic ;
	sum : OUT std_logic ;
	cout : OUT std_logic
);
END addsub ;

Architecture DataFlow of addsub is
BEGIN
	sum <= (in_0 xor (in_1 xor AddOrSub)) xor (cin or AddOrSub);
	cout <= ((in_0 xor (in_1 xor AddOrSub)) and (cin or AddOrSub) )or (in_0 and (in_1 xor AddOrSub));
	
END DataFlow;