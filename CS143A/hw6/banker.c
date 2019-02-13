#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


int main()
{
	//takes user input of P and R
	int P, R;
	scanf("%d", &P);
	scanf("%d", &R);
	//printf("%d, %d\n", P, R);
	
	//takes user input of number of resources
	int resources[R];
	int i;
	for(i=0; i<R; ++i){
		scanf("%d ", &resources[i]);
		//printf("%d\n", resources[i]);
	}	

	//takes user input of already allocated resources
	int allocates[P][R];
	int ii, jj;
	for(ii=0; ii<P; ++ii)
		for(jj=0; jj<R; ++jj)
			if(jj == R-1){
				scanf("%d\n", &allocates[ii][jj]);
				//printf("%d\n", allocates[ii][jj]);
			}
			else{
				scanf("%d ", &allocates[ii][jj]);
				//printf("%d ", allocates[ii][jj]);
			}
	
	//calculates how much resources is actually available for process use
	int avail_resources[R];
	int a, b, c;
	for(c=0; c<R; ++c)
		avail_resources[c] = resources[c];
		
	for(a=0; a<P; ++a)
		for(b=0; b<R; ++b)
			avail_resources[b] -= allocates[a][b];

	//takes user input of max resources a process can have
	int max[P][R];
	int iii, jjj;
	for(iii=0; iii<P; ++iii)
		for(jjj=0; jjj<R; ++jjj)
			if(jjj == R-1){
				scanf("%d\n", &max[iii][jjj]);
				//printf("%d\n", max[iii][jjj]);
			}
			else{
				scanf("%d ", &max[iii][jjj]);
				//printf("%d ", max[iii][jjj]);
			}

	// calculates how much resources a process still needs
	int need[P][R];
	int o, p;
	for(o=0; o<P; ++o)
		for(p=0; p<R; ++p)
			need[o][p] = max[o][p] - allocates[o][p];		

	// creates an array showing if a process has ran or not
	int process[P];
	int pp;
	for(pp=0; pp<P; ++pp)
		process[pp] = 0;

	//bankers algortithm
	int pro, re, rr, match;
	int change = 1;
	while(1){	
		if(change == 0)
			break;
		change = 0;	
		for(pro=0; pro<P; ++pro){
			match = 0;
			for(re=0; re<R; ++re){
				if(process[pro] == 0){
					//printf("b4: need[%d][%d] is %d <= resources[%d] is %d\n", pro, re, need[pro][re], re, avail_resources[re]);
					if(need[pro][re] <= avail_resources[re]){	
						//printf("need[%d][%d] is %d <= resources[%d] is %d\n", pro, re, need[pro][re], re, avail_resources[re]);
						match++;
					}
					else
						break;
				}
				else
					break;
			}
			//printf("match = %d\n", match);
			if(match == R){
				process[pro] = 1;
				//printf("The process[%d] is %d\n", pro, process[pro]);
				for(rr=0; rr<R; ++rr)
					avail_resources[rr] += allocates[pro][rr];
				printf("Process %d has been granted resources\n", pro);
				change = 1;
			}
		}			
	}

	// final check of safe or unsafe
	int end;
	for(end=0; end<P; ++end)
		if(process[end] == 0){
			//printf("Process[%d] is %d\n", end, process[end]);
			printf("The system is in an unsafe state\n");
			exit(1);
		}
	printf("The system is in a safe state\n");		

	return 0;
}
