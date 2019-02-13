library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
ENTITY reg IS
GENERIC ( NBIT : INTEGER :=32);
PORT (
clk : IN std_logic ;
rst_a : IN std_logic ; -- asynchronous reset
rst_s : IN std_logic ; -- synchronous reset
inc : IN std_logic ; -- increment
we : IN std_logic ; -- write enable
din : IN std_logic_vector ( NBIT -1 downto 0); -- input data
dout : OUT std_logic_vector ( NBIT -1 downto 0) -- output data
);
END reg ;


architecture beh of reg is

begin  -- beh

  regist: process(clk,rst_a)
    variable temp : std_logic_vector(NBIT-1 downto 0);
    begin
    if(rst_a='1') then
          temp := (others=>'0');
    elsif (clk'event and clk='1') then
       if (rst_s ='1') then 
          temp := (others=>'0');
       elsif (inc='1') then 
          temp:= std_logic_vector(unsigned(temp) + 1);
       elsif (we='1') then
          temp := din;
       end if;
    end if;
    dout <= temp;    
         
  end process;

end beh;
