#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
private:
	int quarters, dimes, nickels, pennies;
public:
	Coins(int q, int d, int n, int p)
		: quarters(q), dimes(d), nickels(n), pennies(p)
	{	
	}
	void depositChange(Coins & c)
	{
		quarters += c.quarters;
		//c.quarters = 0;
		dimes += c.dimes;
		//c.dimes = 0;
		nickels += c.nickels;
		//c.nickels = 0;
		pennies += c.pennies;
		//c.pennies = 0;
		c = Coins(0,0,0,0);
	}
	bool hasSufficientAmounr(int amount)
	{
		return amount < quarters*25 + dimes*10 + nickels*5 + pennies*1;
	}
	Coins extractChange(int amount)
	{
		int total = 0;
		int num_q = 0;
		int num_d = 0;
		int num_n = 0;
		int num_p = 0;
		int q_num = amount / 25;	
		if(q_num <= quarters)
		{
			quarters = quarters - q_num;
			total = 25*q_num;
			num_q = q_num;
			amount = amount - total;	
		}
		else
		{
			total = quarters * 25;
			num_q = quarters;
			quarters = 0;
			amount = amount - total;
		}
		if(amount == 0)
		{
			return Coins(num_q, num_d, num_n, num_p);
		}
		int d_num = amount / 10;
		if(d_num <= dimes)
		{
			dimes = dimes - d_num;
			total = 10*d_num;
			num_d = d_num;
			amount = amount - total;
		}
		else
		{
			total = dimes * 10;
			num_d = dimes;
			dimes = 0;
			amount = amount - total;
		}
		if(amount == 0)
		{	
			return Coins(num_q, num_d, num_n, num_p);
		}
		int n_num = amount / 5;
		if(n_num <= nickels)
		{
			nickels = nickels - n_num;
			total = 5*n_num;
			num_n = n_num;
			amount = amount - total;
		}
		else
		{
			total = nickels * 5;
			num_n = nickels;
			nickels = 0;
			amount = amount - total;	
		}
		if(amount == 0)
		{		
			return Coins(num_q, num_d, num_n, num_p);
		}	
		int p_num = amount / 1;
		if(p_num <= pennies)
		{	
			total = pennies * 5;
			num_p = p_num;
			pennies = pennies - p_num;
			amount = amount -total;
			return Coins(num_q, num_d, num_n, num_p);
		}
		else
		{
			throw -1;	
		}
	}
	void print(ostream & out)
	{
		cout <<  quarters << " quarters, " << dimes << " dimes, " 
			<< nickels << " nickels, " << pennies << " pennies";
	}
	~Coins()
	{
	}
};
ostream & operator << (ostream & out, Coins & c)
{
	c.print(out);
	return out;
}
