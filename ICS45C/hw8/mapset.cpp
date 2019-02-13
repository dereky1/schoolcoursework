#include <iostream>
#include <map>
#include <set>
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
	map <string, int> M;
	set <string> S;

	for_each( istream_iterator<string>(notin), istream_iterator<string>()		, [&](string s){transform(begin(s), end(s), begin(s), ::tolower);		S.insert(s);});

	for_each( istream_iterator<string>(in), istream_iterator<string>(), 
	[&](string s){transform(begin(s), end(s), begin(s), ::tolower);			 if(S.find(s) == S.end()) M[s]++;});
	
	for_each( M.begin(), M.end(), 
	[&](pair<string,int> i){out<<i.first<<" "<<i.second<<endl;});	

	return 0;
}
