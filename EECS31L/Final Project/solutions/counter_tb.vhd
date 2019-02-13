library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity counter_tb is
  
end counter_tb;

architecture beh of counter_tb is

component counter
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
END component;

 signal clk, rst_s, asc, preload: std_logic;  -- <[comment]>
 signal din, dout: std_logic_vector(31 downto 0);
begin   --beh

  resgister1: counter generic map (NBIT => 32, STEP =>2) port map (clk, rst_s, asc, preload, din, dout);
    clk_pc: process
      begin
        clk <='0';
        loop
          wait for 10 ns;
           clk <= not clk;
        end loop;
       
      end process;
      

    tb:process
      begin
        rst_s <= '0';
        preload <='0';
        asc <= '1';
        wait for 40 ns;
        rst_s <= '1';
        wait for 45 ns;
        rst_s <= '0';
        preload <='1';
        din <= "00011111111110110001111111111010";
        wait for 25 ns;
        preload <= '0';
        wait for 65 ns;
        asc <= '0';
        wait for 50 ns;
        rst_s <= '1';
        wait for 25 ns;
        rst_s <= '0';
        assert false report "done" severity failure;
        
      end process;

end beh;
