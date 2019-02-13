library ieee;
use ieee.STD_logic_1164.all;

entity alu_1bit is
	PORT (
	A : IN STD_LOGIC ;
	B : IN STD_LOGIC ;
	cin : IN STD_LOGIC ;
	alu_op : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
	output : OUT STD_LOGIC ;
	cout : OUT STD_LOGIC
	);
end alu_1bit;

architecture str of alu_1bit is
component FullAdder 
port(
 a_fulladder : IN STD_Logic;
 b_fulladder : IN STD_Logic;
 cin_fulladder : IN STD_Logic;
 sum_fulladder : OUT STD_logic;
 cout_fulladder : OUT STD_Logic
);
end component FullAdder;

signal B_not,MuxB_out, MuxCin_out, SumArith_toMuxSum , CoutArith_toMuxCout,SumLogic_toMuxSum,CoutLogic_toMuxCout: std_logic;
begin

FullAdder1: FullAdder port map (A, MuxB_out, MuxCin_out,SumArith_toMuxSum,CoutArith_toMuxCout);
B_not <= not B;

with alu_op select MuxB_out <= B when "0001",
			'0' when "1011",
			B_not when "0010",
			'X' when others;

with alu_op select MuxCin_out <= cin when "0001",
			'0' when "1011",
			cin when "0010",
			'X' when others ;

with alu_op select SumLogic_toMuxSum <= (A and B) when "0101",--and
				(A or B) when "0110",--or
				(A xor B) when "1000",--xor
				(not a) when "0111",--not
				cin when "1001",--shift l
				'0' when "1010", --shift r
				'X' when others ;

with alu_op select CoutLogic_toMuxCout <= '0' when "0001",
				'0' when "1011",
				'0' when "0010",
				'X' when others ;


with alu_op select output <= SumArith_toMuxSum when "0001",
				SumArith_toMuxSum when "0010",
				SumArith_toMuxSum when "1011",
				SumLogic_toMuxSum when "0100",
				SumLogic_toMuxSum when "0101",
				SumLogic_toMuxSum when "0110",
				SumLogic_toMuxSum when "0111",
				SumLogic_toMuxSum when "1000",
				SumLogic_toMuxSum when "1001", 
				SumLogic_toMuxSum when "1010",
				'X' when others ;


with alu_op select cout <= CoutArith_toMuxCout when "0001",
			CoutArith_toMuxCout when "0010",
			CoutArith_toMuxCout when "1011",
			CoutLogic_toMuxCout when "0100",
			CoutLogic_toMuxCout when "0101",
			CoutLogic_toMuxCout when "0110",
			CoutLogic_toMuxCout when "0111",
			CoutLogic_toMuxCout when "1000",
			CoutLogic_toMuxCout when "1001",
			CoutLogic_toMuxCout when "1010", 
			'X' when others;
				 
end architecture str;