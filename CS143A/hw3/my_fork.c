#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int tru = 0;

int main(int argc, char * args[])
{
	if( argc > 2)
	{
		printf("Error: too many inputs\nUsage: my_fork (integer)\n");
		exit(1);
	}
	
	pid_t child1, child2, child3, wpid;
	int i, status;
	int num;
	
	if(argc > 1)
		num = atoi(args[1]);
	else
		num = 10;

	if(child1 = fork()== 0)
	{
		int j;
		for(j=0; j<num; ++j){
		printf("B");
		fflush(stdout);}
		if(child2 = fork() == 0)
		{
			int opq = 0;/*
			int k;
			for(k=0;k<num;++k){
			printf("C");
			fflush(stdout);}
			waitpid(child1, NULL, 0);
			*/if(child3 = fork() == 0)
			{
				int l;
				for(l=0;l<num;++l){
				printf("D");
				fflush(stdout);}
				waitpid(child1, NULL, 0);
			}	
		}
		else
		{
			int k;
			for(k=0;k<num;++k){
			printf("C");
			fflush(stdout);}
			waitpid(child2, NULL, 0);
		}
	}
	else
	{
		int h;	
		for(h=0;h<num;++h){
		printf("A");
		fflush(stdout);}
		waitpid(child3,NULL,0);
	}
	
	while(wait(wpid, &status, 0) == 0);
	

	return 0;
}
