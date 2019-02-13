#include <iostream>
#include "MapArray.h"
#include "SetList.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
	ifstream in("sample_doc.txt");
	ofstream out("frequency.txt");
	ifstream notin("stopwords.txt");
	MapArray <string, int> M;
	SetList <string> S;

	for_each( istream_iterator<string>(notin), istream_iterator<string>()		, [&](string s){transform(begin(s), end(s), begin(s), ::tolower);		S.insert(s);});

	for_each( istream_iterator<string>(in), istream_iterator<string>(), 
	[&](string s){transform(begin(s), end(s), begin(s), ::tolower);			 if(S.find(s) != true) int i = 0;});

	for_each( M.begin(), M.end(), 
	[&](string i){out<<" "<<endl;});	
	
	return 0;
}
