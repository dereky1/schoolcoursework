library ieee;
use ieee.STD_logic_1164.all;

entity alu_1bit is
	PORT (
	A : IN STD_LOGIC ;
	B : IN STD_LOGIC ;
	cin : IN STD_LOGIC ;
	opsel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
	mode : IN STD_LOGIC ;
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

with opsel select
	MuxB_out <= B 			when "000",
					B_not when "001",
					'0' 	when "010",
					B_not when "011",
					'0' 	when "100",
					'1' 	when "101",
					B 	when "110" ;

with opsel select
	MuxCin_out <= cin		when "000",
					  cin 	when "001",
					  '0'	when "010",
					  cin    when "011",
					  cin	when "100",
					  '0'	when "101",
					  cin    when "110" ;

with opsel select
	SumLogic_toMuxSum <= (A and B)	when "000",
								(A or B) 	when "001",
								(A xor B)	when "010",
								(not a)     when "011",
								cin			when "101";

with opsel select
	CoutLogic_toMuxCout <= '0'		when "000",
								  '0' 	when "001",
								  '0'		when "010",
								  '0'    when "011",
								  A		when "101";


with mode select
	output <= SumArith_toMuxSum		when '0',
				 SumLogic_toMuxSum 	   when '1';


with mode select
	cout <= CoutArith_toMuxCout		when '0',
			  CoutLogic_toMuxCout 	   when '1';
				 
end architecture str;