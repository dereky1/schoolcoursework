library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

ENTITY carry_gen IS
PORT (
alu_op : IN std_logic_vector(3 downto 0) ;
cout : OUT std_logic
);
END carry_gen ;

architecture arc of carry_gen is
begin
cout <= '1' when alu_op = "0010" else
	'0';

end arc;
