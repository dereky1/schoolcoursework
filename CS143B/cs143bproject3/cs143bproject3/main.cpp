#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <bitset>
using namespace std;


int main()
{
	string filename;
	ifstream infile1, infile2;
	vector<int> pm;
	for (int i = 0; i < 524288; ++i)
		pm.push_back(0);
	int bm[1024] = { 0 };
	bm[0] = 1;
	map<int, int> tlb;

	//Reading file
	while (true) {
		filename = "input1.txt";
		filename = "D:\\" + filename;
		infile1.open(filename);
		if (infile1.is_open()) {
			break;
		}
		else
			printf("Unable to open read file!\nPlease try again!\n");
	}

	int first = 0;
	string st_s, st_f, pt_p, pt_s, pt_f;
	string line;
	//Gets text from file and outputs a vector of processes 
	for (string line; getline(infile1, line); ++first) {
		stringstream ss(line);
		if (first == 0) {
			while (ss >> st_s) {
				if (ss >> st_f) {
					pm[stoi(st_s)] = stoi(st_f);
					if (stoi(st_f) != -1) {
						bm[stoi(st_f) / 512] = 1;
						bm[(stoi(st_f) / 512) + 1] = 1;
					}
				}
				else {
					cout << "Input Error!\n";
					exit(1);
				}
			}
		}
		else if (first == 1) {
			while (ss >> pt_p) {
				if (ss >> pt_s) {
					if (ss >> pt_f) {
						pm[pm[stoi(pt_s)] + stoi(pt_p)] = stoi(pt_f);
						bm[stoi(pt_f) / 512] = 1;
					}
					else {
						cout << "Input Error!\n";
						exit(1);
					}
				}
				else {
					cout << "Input Error!\n";
					exit(1);
				}
			}
		}
	}

	infile1.close();
	//Creates Output Text File
	ofstream outfile("D:\\63118832-notlb.txt");
	//ofstream outfile("C:\\Users\\Derek\\Desktop\\63118832-notlb.txt");

	//Creates Output Text File
	ofstream outfile1("D:\\63118832-tlb.txt");
	//ofstream outfile1("C:\\Users\\Derek\\Desktop\\63118832-tlb.txt");

	while (true) {
		filename = "input2.txt";
		filename = "D:\\" + filename;
		infile2.open(filename);
		if (infile2.is_open()) {
			break;
		}
		else
			printf("Unable to open read file!\nPlease try again!\n");
	}

	bool next = false;
	string rw, va;
	string line1;

	//Gets text from file and outputs a vector of processes 
	getline(infile2, line1);
	stringstream ss(line1);
	while (ss >> rw) {
		if (ss >> va) {
			//digest virtual addresss
			string bit = bitset<32>(stoi(va)).to_string();
			string s, p, w, pw = "";
			for (int i = 0; i < 32; ++i) {
				if (i > 3 && i < 13)
					s += bit[i];
				else if (i > 12 && i < 23)
					p += bit[i];
				else if (i > 22 && i < 32)
					w += bit[i];
				if (i > 3 && i < 23)
					pw += bit[i];
			}

			int si = bitset<9>(s).to_ulong();
			int pi = bitset<10>(p).to_ulong();
			int wi = bitset<9>(w).to_ulong();

			///TLB USE
			int sp = bitset<19>(pw).to_ulong();

			if (tlb.find(sp) != tlb.end()) {
				for (auto m : tlb) {
					if (m.first == sp)
						m.second = 3;
					else if(m.second != 0)
						m.second = (m.second + 2) % 3;
				}
				outfile1 << "h ";
			}
			else {
				outfile1 << "m ";
				if (tlb.size() == 4) {
					for (auto m : tlb) {
						if (m.second == 0) {
							int temp = m.first;
							tlb.erase(temp);
							break;
						}
					}
				}
				tlb[sp] = 3;
				for (auto m : tlb) {
					if (m.first == sp)
						m.second = 3;
					else if (m.second != 0)
						m.second = (m.second + 2) % 3;
				}
			}

			//si pi wi has the virtual address
			if (stoi(rw) == 0) { //// Read
				if (pm[si] == -1) {
					outfile << "pf ";
					outfile1 << "pf ";
				}
				else {
					if (pm[si] != 0) {
						if (pm[pm[si] + pi] != 0)
							if (pm[pm[si] + pi] != -1) {
								outfile << pm[pm[si] + pi] + wi << " ";
								outfile1 << pm[pm[si] + pi] + wi << " ";
							}
							else {
								outfile << "pf ";
								outfile1 << "pf ";
							}
						else {
							outfile << "err ";
							outfile1 << "err ";
						}
					}
					else {
						outfile << "err ";
						outfile1 << "err ";
					}
				}
			}
			else if (stoi(rw) == 1) { ///Write
				if (pm[si] == -1) {
					outfile << "pf ";
					outfile1 << "pf ";
				}
				else {
					if (pm[si] != 0) {
						if (pm[pm[si] + pi] != 0) 
							if (pm[pm[si] + pi] != -1) {
								outfile << pm[pm[si] + pi] + wi << " ";
								outfile1 << pm[pm[si] + pi] + wi << " ";
							}
							else {
								outfile << "pf ";
								outfile1 << "pf ";
							}
						else { ///// page table is 0 create new page
							for (int i = 0; i < 1024; ++i) {
								if (bm[i] == 0) {
									bm[i] = 1;
									pm[pm[si] + pi] = i * 512;
									break;
								}
							}
							outfile << pm[pm[si] + pi] + wi << " ";
							outfile1 << pm[pm[si] + pi] + wi << " ";
						}
					}
					else { //// seg table is 0 create new page table
						for (int i = 0; i < 1024; ++i) {
							if (bm[i] == 0) {
								if (i + 1 < 1024 && bm[i + 1] == 0) {
									bm[i] = 1;
									bm[i + 1] = 1;
									pm[si] = i * 512;
									break;
 								}
							}
						}
						for (int i = 0; i < 1024; ++i) {
							if (bm[i] == 0) {
								bm[i] = 1;
								pm[pm[si] + pi] = i * 512;
								break;
							}
						}
						outfile << pm[pm[si] + pi] + wi << " ";
						outfile1 << pm[pm[si] + pi] + wi << " ";
					}
				}
			}
		}
		else {
			cout << "Input Error!\n";
			exit(1);
		}
	}

	outfile.close();
	outfile1.close();
	infile2.close();

	return 0;
}