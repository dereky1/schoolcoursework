library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
ENTITY reg_tb IS
END reg_tb ;

architecture beh of reg_tb is


COMPONENT reg
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
END component;
 signal clk_tb, rst_a_tb, rst_s_tb, inc_tb, we_tb : std_logic;  -- <[comment]>
 signal din_tb, dout_tb: std_logic_vector(31 downto 0);
begin   --beh

  resgister1: reg generic map (NBIT => 32) port map (clk_tb, rst_a_tb, rst_s_tb, inc_tb,we_tb, din_tb,dout_tb);
    clk_pc: process
      begin
        clk_tb <='0';
        loop
          wait for 10 ns;
           clk_tb <= not clk_tb;
        end loop;
       
      end process;
      

    tb:process
      begin
        rst_a_tb <= '0';
        rst_s_tb <= '0';
        inc_tb <='0';
        we_tb <= '0';
        wait for 40 ns;
        rst_a_tb <= '1';
        wait for 45 ns;
        rst_a_tb <= '0';
        din_tb <= "00011111111110110001111111111010";
        wait for 5 ns;
        we_tb <= '1';
        wait for 55 ns;
        we_tb <= '0';
        inc_tb <= '1';
        wait for 35 ns;
        inc_tb <='0';
        rst_s_tb <= '1';
        wait for 30 ns;
        assert false report "done" severity failure;
        
      end process;
      


end beh;

