#include "Coins.h"
using namespace std;
const int CENTS_FOR_CHIPS = 68; 
int main()
{
	Coins pocket(5,3,6,8);
	Coins piggybank(50,50,50,50);
	cout << "\n========start========" << endl;
	cout << "pocket: " << pocket << "\npiggybank: " << piggybank << endl;
	cout << "========start========\n\n";
	pocket.extractChange(68);
	cout << "You just bought a bag of Hot Cheetohs for 68 cents.\npocket: " << pocket <<  endl; 
	Coins bunch = piggybank.extractChange(410);
	//Coins bunch(16,1,0,0);
	cout << "You take " << bunch << " from your piggybank and put it into your pocket." << endl;
	cout << "coins added: " << bunch << endl;	
	pocket.depositChange(bunch);
	cout << "pocket:  " << pocket << "\npiggybank:  " << piggybank << endl; 
	Coins vacuum(1,2,3,4);		
	cout << "You find " << vacuum << " while vacuuming your couch and deposit it into your piggybank." << endl;
	piggybank.depositChange(vacuum);
	cout << "piggybank: " << piggybank << endl << endl;
	cout << "========end========" << endl;	
	cout << "pocket: " << pocket << "\npiggybank: " << piggybank << endl;
	cout << "========end========\n\n";
	return 0;
}
