library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity REGFILE_TB is
  
end REGFILE_TB;

architecture BEH of REGFILE_TB is

COMPONENT regfile
GENERIC ( NBIT : INTEGER := 32;
NSEL : INTEGER := 3);
PORT (
clk : IN std_logic ;
rst_s : IN std_logic ; -- synchronous reset
we : IN std_logic ; -- write enable
raddr_1 : IN std_logic_vector ( NSEL -1 DOWNTO 0); -- read address 1
raddr_2 : IN std_logic_vector ( NSEL -1 DOWNTO 0); -- read address 2
waddr : IN std_logic_vector ( NSEL -1 DOWNTO 0); -- write address
rdata_1 : OUT std_logic_vector ( NBIT -1 DOWNTO 0); -- read data 1
rdata_2 : OUT std_logic_vector ( NBIT -1 DOWNTO 0); -- read data 2
wdata : IN std_logic_vector ( NBIT -1 DOWNTO 0) -- write data 1
);
END COMPONENT;


 signal clk, rst_s, we: std_logic;  -- <[comment]>
 signal raddr1, raddr2, waddr: std_logic_vector(2 downto 0);
 signal rdata1, rdata2, wdata : std_logic_vector(31 downto 0);

begin   --beh
  resgister1: regfile generic map (NBIT => 32,NSEL =>3) port map (clk, rst_s, we, raddr1, raddr2, waddr, rdata1, rdata2, wdata);
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
        raddr1 <= "010";
        raddr2 <= "001";
                  
        rst_s <= '0';
        we <= '0';
        wait for 40 ns;
        rst_s <= '1';
        wait for 45 ns;
        rst_s <= '0';
        waddr <= "010";
        wdata <= "00011111111110110001111111111010";
        wait for 5 ns;
        we <= '1';
        wait for 55 ns;
        waddr <= "001";
        wdata <= "00000000000000000000000000111110";        
        wait for 35 ns;
        we <='0';
        rst_s <= '1';
        wait for 30 ns;
        assert false report "done" severity failure;
        
      end process;
  

end BEH;




