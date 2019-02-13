library ieee ;
use ieee.std_logic_1164.all ;

ENTITY Circuity_B IS
PORT(
B : IN STD_LOGIC ;
opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0) ;
Free_B : OUT STD_LOGIC 
); 
END Circuity_B ;

ARCHITECTURE B_arch of Circuity_B is
begin 
Free_B <= (NOT B AND opsel(0)) OR (opsel(2) AND opsel(0)) OR (B AND NOT opsel(2) AND NOT opsel(0)) OR (opsel(1) AND NOT opsel(0) AND B);
END B_arch ;