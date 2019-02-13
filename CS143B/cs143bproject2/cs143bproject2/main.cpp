#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;


class process
{
public:
	process()
	{
	}
	process(int new_pid, int new_start, int new_size)
		:pid(new_pid), start(new_start), size(new_size)
	{
	}
	~process()
	{
	}
	int pid;
	int start;
	int size;
};

//Flips the boolean switch
void flip(bool &lever)
{
	if (lever == true)
		lever = false;
	else
		lever = true;
}

double cut(double value)
{
	double temp = value * 100.0;
	int i = temp;
	temp = (double)i / 100.0;
	return temp;
}

void FIFO(ofstream &out, vector<process> vect)
{
	vector<int> start;
	vector<int> times;
	int count = 0;
	for (int i = 0; i < vect.size(); ++i){
		start.push_back(vect[i].start);
		count += vect[i].size;
		times.push_back(count - start[i]);
	}

	double average = 0.0;
	for (int i = 0; i < vect.size(); ++i) {
		average += times[i];
	}

	average /= vect.size();
	average = cut(average);
	out << average;


	for (int i = 0; i < vect.size(); ++i) {
		out << " " << times[i];
	}
	out << endl;

	return;
}

void SJF(ofstream &out, vector<process> vect)
{
	int counts = 0;
	int time = 0;
	vector<process> line;
	vector<process> temp = vect;

	while (true) {
		if (0 == temp.size())
			break;
		vector<process> order;
		for (int i = 0; i < temp.size(); ++i) {
			if (temp[i].start <= time) {
				order.push_back(temp[i]);
				counts++;
			}
		}

		sort(order.begin(), order.end(), [](const process &p1, const process &p2){
			return p1.size < p2.size;
		});

		if (order.size() > 0) {
			line.push_back(order.front());
			for (int i = 0; i < temp.size(); ++i) {
				if (temp[i].start == order.front().start && temp[i].pid == order.front().pid && temp[i].size == order.front().size) {
					temp.erase(temp.begin() + i);
					break;
				}
			}
		}
		
		time += order.front().size;
		order.clear();
	}
	
	vector<int> start;
	vector<int> times;
	int count = 0;
	for (int i = 0; i < line.size(); ++i) {
		start.push_back(line[i].start);
		count += line[i].size;
		times.push_back(count - start[i]);
	}

	double average = 0.0;
	for (int i = 0; i < line.size(); ++i) {
		average += times[i];
	}

	average /= line.size();
	average = cut(average);
	out << fixed << setprecision(2) << average;

	vector<int> ordering;
	for (int i = 0; i < line.size(); ++i) {
		ordering.push_back(line[i].pid);
	}

	for (int i = 0; i < line.size(); ++i) {
		for (int j = 0; j < line.size(); ++j) {
			if(ordering[j] == i)
				out << " " << times[j];
		}
	}
	
	out << endl;

	return;
}

void SRT(ofstream &out, vector<process> vect)
{
	int time = 0;
	int smallest = 0;
	int breaker = 0;
	vector<int> times;
	for (int i = 0; i < vect.size(); ++i) {
		times.push_back(0);
		breaker += vect[i].size;
	}

	for (int p = 0; p < breaker; ++p) {
		
		for (int i = 0; i < times.size(); ++i) {
			if(vect[i].start <= time)
				if(vect[i].size > 0)
					times[i]++;
		}

		for (int i = 0; i < vect.size(); ++i) {
			if (vect[i].start <= time && vect[i].size > 0) {
				if (vect[smallest].size > 0 && vect[i].size < vect[smallest].size)
					smallest = i;
				else if (vect[smallest].size == 0 && vect[i].size > 0)
					smallest = i;
			}
		}

		vect[smallest].size--;

		time++;
	}

	double average = 0.0;
	for (int i = 0; i < vect.size(); ++i) {
		average += times[i];
	}

	average /= vect.size();
	average = cut(average);
	out << average;


	for (int i = 0; i < vect.size(); ++i) {
		out << " " << times[i];
	}
	out << endl;

	return;
}

void MLF(ofstream &out, vector<process> vect) //Round Robin with 5 Levels
{
	int time = 0;
	queue<process> priority[5];
	vector<int> limit[5];
	vector<int> times;
	int breaker = 0;
	int run = 0;
	int flag = 0;

	for (int i = 0; i < vect.size(); ++i) {
		times.push_back(0);
		breaker += vect[i].size;
	}

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < vect.size(); ++j)
			limit[i].push_back(0);

	for (int p = 0; p < breaker; ++p) {
		for (int i = 0; i < times.size(); ++i) {
			if (vect[i].start <= time) {
				if (vect[i].size > 0) {
					times[i]++;
				}
			}
			if (vect[i].start == time) {
				priority[0].push(vect[i]);
				limit[0][i]++;
			}
		}

		for (int i = 0; i < 5; ++i) {
			if (flag != 0) {
				flag = 0;
				break;
			}
			if (!priority[i].empty()) {
				for (int j = 0; j < vect.size(); ++j) {
					if (vect[j].pid == priority[i].front().pid) {
						vect[j].size--;
						limit[i][j]++;
						if (limit[i][j] >= i + 1) 
							priority[i].pop();
						if (vect[j].size > 0) {
							if (i + 1 < 5 && limit[i][j] >= i + 1 )
								priority[i + 1].push(vect[j]);
						}
						
						flag = 1;
						break;
					}
				}
			}
		}
		time++;
	}

	double average = 0.0;
	for (int i = 0; i < vect.size(); ++i) {
		average += times[i];
	}

	average /= vect.size();
	average = cut(average);
	out << average;


	for (int i = 0; i < vect.size(); ++i) {
		out << " " << times[i];
	}
	out << endl;

	return;
}

int main()
{
	string filename;
	ifstream infile;
	vector<process> my_list;

	//Reading file
	while (true) {
		filename = "input.txt";
		filename = "D:\\" + filename;
		infile.open(filename);
		if (infile.is_open()) {
			break;
		}
		else
			printf("Unable to open read file!\nPlease try again!\n");
	}

	//Creates Output Text File
	ofstream outfile("D:\\63118832.txt");
	//ofstream outfile("C:\\Users\\Derek\\Desktop\\63118832.txt");

	bool next = false;
	int count = 0;
	string command, name, start, end;
	string line;
	
	//Gets text from file and outputs a vector of processes 
	getline(infile, line);
	stringstream ss(line);
	while(ss >> name){
		if (next == false) {
			start = name;
		}
		else{
			end = name;
			process siksee(count++, stoi(start), stoi(end));
			my_list.push_back(siksee);
		}
		flip(next);
	}

	FIFO(outfile, my_list);
	SJF(outfile, my_list);
	SRT(outfile, my_list);
	MLF(outfile, my_list);
	
	outfile.close();
	infile.close();

	return 0;
}