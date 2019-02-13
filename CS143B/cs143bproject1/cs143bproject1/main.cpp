#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

class pcb
{
public:
	pcb()
	{
	}
	pcb(string name, int prior)
		:pid(name), priority(prior)
	{
		for (int i = 0; i < 4; ++i) {
			resources[i] = 0;
			request[i] = 0;
		}
	}
	~pcb()
	{
	}
	string pid;
	int resources[4];
	int request[4];
	int priority;
	vector<pcb> parent;
	vector<pcb> child;
};

deque<pcb> ready_list[3];
deque<pcb> blocked_list[4];
pcb running;
int resource[4] = {1,2,3,4};
int maxr[4] = { 1,2,3,4 };
bool error = false;

void shuffle()
{
	pcb temp = running;
	running = ready_list[running.priority].front();
	ready_list[running.priority].pop_front();
	ready_list[running.priority].push_back(temp);
}


void init(ofstream &out)
{
	deque<pcb> empty[3];
	deque<pcb> empty2[4];
	for (int i = 0; i < 3; ++i)
		ready_list[i].swap(empty[i]);
	for (int x = 0; x < 4; ++x)
		blocked_list[x].swap(empty2[x]);
	pcb init_p("init", 0);
	ready_list[0].push_back(init_p);
	running = init_p;
	for (int i = 0; i < 4; ++i)
		resource[i] = maxr[i];
	out << endl;
	error = false;
	return;
}
void cr(string name, int priority)
{
	pcb newp(name, priority);
	running.child.push_back(newp);
	newp.parent.push_back(running);
	ready_list[priority].push_back(newp);
	return;
}
void de(pcb process)
{
	if (process.child.empty()) {
		for (int x = 0; x < 4; ++x) 
			resource[x] += process.resources[x];

		int pri = process.priority;
		for (int i = 0; i < ready_list[pri].size(); ++i)
			if (ready_list[pri][i].pid == process.pid)
				ready_list[pri].erase(ready_list[pri].begin() + i);
	}
	else {
		for (int i = 0; i < process.child.size(); ++i)
			de(process.child[i]);
		
		int pri = process.priority;
		for (int i = 0; i < ready_list[pri].size(); ++i)
			if (ready_list[pri][i].pid == process.pid)
				ready_list[pri].erase(ready_list[pri].begin() + i);
	}

	return;
}
void to()
{
	shuffle();
	return;
}

void req(pcb &proc, int re, int quantity, ofstream &out)
{
	if (resource[re] >= quantity) {
		proc.resources[re] += quantity;
		resource[re] -= quantity;
		for (int i = 0; i < 4; ++i) 
			proc.request[i] = 0;
	}
	else if (proc.resources[re] + quantity > maxr[re]) {
		out << "error ";
		error = true;
	}
	else {
		proc.request[re] = quantity;
		ready_list[proc.priority].pop_front();
		blocked_list[re].push_back(proc);

		if (ready_list[2].size() != 0) 
			proc = ready_list[2].front();
		else if (ready_list[1].size() != 0) 
			proc = ready_list[1].front();
		else
			proc = ready_list[0].front();
	}

	return;
}

void rel(int re, int quantity, ofstream &out)
{
	if (running.resources[re] >= quantity) {
		resource[re] += quantity;
		running.resources[re] -= quantity;
	}
	else {
		out << "error ";
		error = true;
	}
	return;
}

void block_free(ofstream &out)
{
	for (int i = 0; i < 4; ++i) {
		if(blocked_list[i].size() != 0)
			if (blocked_list[i].front().request[i] > 0 && blocked_list[i].front().request[i] <= resource[i]) {
				pcb temp = blocked_list[i].front();
				req(temp, i, blocked_list[i].front().request[i], out);
				ready_list[temp.priority].push_back(temp);
				blocked_list[i].pop_front();
			}
	}
	return;
}

void scheduler(ofstream &out)
{	
	for (int i = 0; i < 4; ++i) {
		if (ready_list[i].size() != 0) {
			if (ready_list[i].front().pid == running.pid) {
				ready_list[i].pop_front();
				ready_list[i].push_front(running);
			}
		}
	}
	block_free(out);
	if (error != true) {
		if (ready_list[2].size() == 0) {
			if (ready_list[1].size() == 0) {
				out << "init ";
			}
			else {
				pcb temp = ready_list[1].front();
				running = temp;
				out << running.pid << " ";
			}
		}
		else {
			pcb temp = ready_list[2].front();
			running = temp;
			out << running.pid << " ";
		}
	}

	return;
}

int main()
{
	string filename;
	ifstream infile;

//Reading file
	while (true) {
		//cout << "Input filename: ";
		//getline(cin, filename);
		filename = "input.txt";
		//filename = "D:\\" + filename;
		infile.open(filename);
		if (infile.is_open()) {
			break;
		}
		else
			printf("Unable to open read file!\nPlease try again!\n");
	}

	//Creates Output Text File
	//ofstream outfile("D:\\63118832.txt");
	ofstream outfile("C:\\Users\\Derek\\Desktop\\63118832.txt");
	
	outfile << "init ";
	pcb main("init", 0);
	ready_list[0].push_back(main);
	running = main;
	bool first = true;

	string command, name, num;
	for (string line; getline(infile, line); ) {
		if (line != "") {
			stringstream ss(line);
			if (ss >> command)
				;
			else
				outfile << "error" << endl;

			if (command == "cr" || command == "de" || command == "req" || command == "rel") {
				if (ss >> name)
					;
				else
					outfile << "error" << endl;
				if (command == "cr" || command == "req" || command == "rel") {
					if (ss >> num)
						;
					else
						outfile << "error" << endl;
				}
			}

			if (command == "init" && first == false) {
				init(outfile);
				scheduler(outfile);
			}
			else if (command == "cr") {
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < ready_list[i].size(); ++j) {
						if (ready_list[i][j].pid == name) {
							outfile << "error ";
							error = true;
						}
					}
				}

				for (int i = 0; i < 4; ++i) {
					for (int j = 0; j < blocked_list[i].size(); ++j) {
						if (blocked_list[i][j].pid == name) {
							outfile << "error ";
							error = true;
						}
					}
				}

				cr(name, stoi(num));
				scheduler(outfile);
			}
			else if (command == "de") {
				if (name == "init") {
					outfile << "error ";
					error = true;
				}

				bool match = false;
				for (int i = 0; i < 3; ++i)
					for (int j = 0; j < ready_list[i].size(); ++j)
						if (ready_list[i][j].pid == name)
							match = true;
				for (int i = 0; i < 4; ++i)
					for (int j = 0; j < blocked_list[i].size(); ++j)
						if (blocked_list[i][j].pid == name)
							match = true;

				if (match == false) {
					outfile << "error ";
					error = true;
				}

				for (int i = 0; i < ready_list[0].size(); ++i)
					if (ready_list[0][i].pid == name)
						de(ready_list[0][i]);
				for (int i = 0; i < ready_list[1].size(); ++i)
					if (ready_list[1][i].pid == name)
						de(ready_list[1][i]);
				for (int i = 0; i < ready_list[2].size(); ++i)
					if (ready_list[2][i].pid == name)
						de(ready_list[2][i]);
				for (int i = 0; i < blocked_list[0].size(); ++i)
					if (blocked_list[0][i].pid == name)
						de(blocked_list[0][i]);
				for (int i = 0; i < blocked_list[1].size(); ++i)
					if (blocked_list[1][i].pid == name)
						de(blocked_list[1][i]);
				for (int i = 0; i < blocked_list[2].size(); ++i)
					if (blocked_list[2][i].pid == name)
						de(blocked_list[2][i]);
				for (int i = 0; i < blocked_list[3].size(); ++i)
					if (blocked_list[3][i].pid == name)
						de(blocked_list[3][i]);

				scheduler(outfile);
			}
			else if (command == "req") {
				if (stoi(num) == 0) {
					outfile << "error ";
					error = true;
				}
				else if (name == "R1" && stoi(num) <= 1) {
					req(running, 0, stoi(num), outfile);
				}
				else if (name == "R2" && stoi(num) <= 2) {
					req(running, 1, stoi(num), outfile);
				}
				else if (name == "R3" && stoi(num) <= 3) {
					req(running, 2, stoi(num), outfile);
				}
				else if (name == "R4" && stoi(num) <= 4) {
					req(running, 3, stoi(num), outfile);
				}
				else {
					outfile << "error ";
					error = true;
				}
				scheduler(outfile);
			}
			else if (command == "rel") {
				int res;
				if (name == "R1")
					res = 0;
				else if (name == "R2")
					res = 1;
				else if (name == "R3")
					res = 2;
				else if (name == "R4")
					res = 3;

				rel(res, stoi(num), outfile);
				scheduler(outfile);
			}
			else if (command == "to") {
				to();
				scheduler(outfile);
			}
			else if (command == "init" && first == true) {
				;
			}
			else {
				outfile << "error" << endl;
				error = true;
			}
		}
		first = false;
	}


	outfile.close();
	infile.close();

	return 0;
}