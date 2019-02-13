library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity reg_bank is
port(clk : in std_logic;
	rd,wr : in std_logic;
	rs_index : in std_logic_vector(5 downto 0);
	rt_index : in std_logic_vector(5 downto 0);
	rd_index : in std_logic_vector(5 downto 0);
	reg_source_out : out std_logic_vector(31 downto 0);
	reg_target_out : out std_logic_vector(31 downto 0);
	reg_dest_new : in std_logic_vector(31 downto 0)
);
end reg_bank; --entity reg_bank

architecture reg_bank_arch of reg_bank is
  
subtype word is std_logic_vector(31 downto 0);
type mem is array (0 to 63) of word;
begin  -- beh
  -- purpose: <[description]>
  memory_handle: process (clk,rd,wr,rs_index,rt_index,rd_index, reg_dest_new)
    variable mem1:mem;
    begin
      if (clk'event and clk = '1' and rd='0' and wr='1') then
        reg_source_out<=mem1(to_integer(unsigned(rs_index)));
	reg_target_out<=mem1(to_integer(unsigned(rt_index)));
      elsif (clk = '0' and rd='1' and wr ='0') then
        mem1(to_integer(unsigned(rd_index))):= reg_dest_new;
      end if;
    end process;

end reg_bank_arch;
