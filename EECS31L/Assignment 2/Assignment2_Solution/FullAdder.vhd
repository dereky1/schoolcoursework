library ieee;
use ieee.STD_logic_1164.all;

Entity FullAdder is
port(
 a_fulladder : IN STD_Logic;
 b_fulladder : IN STD_Logic;
 cin_fulladder : IN STD_Logic;
 sum_fulladder : OUT STD_logic;
 cout_fulladder : OUT STD_Logic
);
end FullAdder;

architecture str of FullAdder is

begin
sum_fulladder <= a_fulladder xor b_fulladder xor cin_fulladder; 
cout_fulladder <= (a_fulladder and b_fulladder) or (a_fulladder and cin_fulladder) or (b_fulladder and cin_fulladder); 
end architecture str;
