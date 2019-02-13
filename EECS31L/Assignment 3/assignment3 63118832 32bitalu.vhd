library ieee;
use ieee.std_logic_1164.all;

ENTITY alu_32bit IS
PORT (
A : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
B : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
mode : IN STD_LOGIC ;
output : OUT STD_LOGIC_VECTOR (31 DOWNTO 0);
cout : OUT STD_LOGIC 
);
END alu_32bit ;

ARCHITECTURE ALU32_arch of alu_32bit is

COMPONENT alu_1bit IS
PORT (
A : IN STD_LOGIC ;
B : IN STD_LOGIC ;
cin : IN STD_LOGIC ;
opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
mode : IN STD_LOGIC ;
output : OUT STD_LOGIC ;
cout : OUT STD_LOGIC
);
END COMPONENT alu_1bit ;
SIGNAL cint : STD_LOGIC_VECTOR (31 DOWNTO 0);
begin
alubit : alu_1bit PORT MAP (A(0), B(0), cint(0), opsel (2 DOWNTO 0), mode);

generate_alu_1_bit : FOR i IN 0 TO 31 GENERATE
cint(0) <= ((NOT opsel(0)) AND opsel(2) AND (NOT mode)) OR 
	(opsel(1) AND opsel(0) AND (NOT opsel(2)) AND (NOT mode)) ;
alu_gen : alu_1bit PORT MAP (A(i), B(i), cint(i), opsel(2 DOWNTO 0), mode, output(i), cout);
END GENERATE generate_alu_1_bit;

cout <= cint(31);

END ALU32_arch;