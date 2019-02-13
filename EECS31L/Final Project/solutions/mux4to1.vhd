library ieee ;
use ieee.std_logic_1164.all;

ENTITY mux4to1 IS
	PORT (
		in_0 : IN std_logic ;
		in_1 : IN std_logic ;
		in_2 : IN std_logic ;
		in_3 : IN std_logic ;
		sel_0 : IN std_logic ;
		sel_1 : IN std_logic ;
		f : OUT std_logic
	);
END mux4to1 ;


ARCHITECTURE DataFlow OF mux4to1 IS
BEGIN

   f <= (in_0 AND (NOT sel_0 AND NOT sel_1)) OR (in_1 AND ( sel_0 AND NOT sel_1)) OR (in_2 AND (NOT sel_0 AND  sel_1)) OR (in_3 AND ( sel_0 AND sel_1)) ;
END DataFlow;



