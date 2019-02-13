library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


ENTITY counter IS
GENERIC ( NBIT : INTEGER := 32;
STEP : INTEGER := 1);
PORT (
clk : IN std_logic ;
rst_s : IN std_logic ; -- synchronous reset
asc : IN std_logic ; -- ascending ( if it is 0, count descending )
preload : IN std_logic ; -- read din as the counting seed
din : IN std_logic_vector ( NBIT -1 downto 0);
dout : OUT std_logic_vector ( NBIT -1 downto 0)
);
END counter ;

architecture beh of counter is

begin  -- beh

  funct: process (clk)
  variable count: std_logic_vector(NBIT-1 downto 0):=(others =>'0');
  begin  -- process
    if (clk'event and clk='1') then
      if(rst_s='1') then
        count:= (others=>'0');
      elsif (preload = '1') then
        count:= din;
      elsif (asc='1') then
        count:= std_logic_vector(unsigned(count)+STEP);
      else
         count:= std_logic_vector(unsigned(count)-STEP);
      end if;
    end if;
    dout <= count;
  end process;

end beh;
