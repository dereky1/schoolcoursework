#include "Coins.h"
using namespace std;
int main()
{
	bool quit = true;
	int q, d, n, p;
	cout << "This is your first time with us, you need to initialize your account" << endl;
	cout << "How many quarters do you have? ";
	cin >> q;
	cout << "How many dimes do you have? ";
	cin >> d;
	cout << "How many nickel do you have? ";
	cin >> n;
	cout << "How many pennies do you have? ";
	cin >> p;

	Coins myCoins(q,d,n,p);

	while(quit)
	{
		int choice;

		//cout << "\n --------------------" << endl;
		cout << "\n ====================" << endl;
		cout << "|   Digital  Bank    |" << endl;
		cout << "|                    |" << endl;
		cout << "| 1. Print Balance   |" << endl;
		cout << "| 2. Deposit         |" << endl;
		cout << "| 3. Withdraw        |" << endl;
		cout << "| 4. Quit	     |" << endl;
		cout << "|                    |" << endl;
		//cout << " --------------------" << endl;
		cout << " ====================" << endl;
		cout << "Enter command: ";

		cin >> choice;	
		switch(choice)
		{
			case 1:		
				cout << "====================" << endl;
				cout << "Account Balance " << endl;
				cout << "====================" << endl;
				cout << "Coins: " << myCoins << endl;
				cout << "--------------------" << endl;
				break;
			case 2:
				{	
				int d_q, d_d, d_n, d_p;
				cout << "====================" << endl;
				cout << "Deposit Ammount " << endl;
				cout << "====================" << endl;
				cout << "Quarters? ";
				cin >> d_q;
				cout << "Dimes? ";
				cin >> d_d;
				cout << "Nickels? ";
				cin >> d_n;
				cout << "Pennies? ";
				cin >> d_p;	
				cout << "====================" << endl;
				cout << "Depositing " << endl;
				cout << "====================" << endl;
				Coins deposit(d_q, d_d, d_n, d_p);
				myCoins.depositChange(deposit);
				cout << "====================" << endl;
				cout << "Deposit Successful " << endl;
				cout << "====================" << endl;	
				cout << "--------------------" << endl;
				break;
				}
			case 3:
				{
				int withdraw;
				Coins copy = myCoins;
				cout << "====================" << endl;
				cout << "Withdraw  " << endl;
				cout << "====================" << endl;
				cout << "How much money do you want to withdraw? ";
				cin >> withdraw;
				cout << "====================" << endl;
				cout << "Withdrawing " << endl;
				cout << "====================" << endl;	
				try
				{
					copy.extractChange(withdraw);
					myCoins.extractChange(withdraw);
					cout << "====================" << endl;
					cout << "Withdraw Successful " << endl;
					cout << "====================" << endl;	
					cout << "--------------------" << endl;
				}
				catch(int i)	
				{
					cout << "====================" << endl;
					cout << "Withdraw Unsuccessful " << endl;
					cout << "====================" << endl;
					cout << "ERROR: NOT ENOUGH MONEY" << endl;
					cout << "--------------------" << endl;
				}
				break;
				}
			case 4:
				quit = false;
				cout << "====================" << endl;
				cout << "Thank You " << endl;
				cout << "Have a Nice Day! " << endl;
				cout << "====================\n" << endl;
				break;
			default:
				cout << "ERROR: INVALID COMMAND" << endl;
		}
	}
	
	return 0;
}
