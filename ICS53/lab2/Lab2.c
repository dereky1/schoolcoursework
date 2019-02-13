/////// Derek Yang 63118832
/////// James Kim 59088715

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int prit = 0;
int lan = 0;
void calc(int array[], int index[], int num, int len)
{
	pid_t one, two, wpid;
	int pass_len;
	int odd = 0;
	if(len%2==0)
		pass_len=len/2;
	else{	
		pass_len = len/2 + 1;
		odd = 1;
		}
	int new_array_1[pass_len];
	int new_index_1[pass_len];
	int new_array_2[pass_len];
	int new_index_2[pass_len];
	if(len == 1){
		if(array[0] == num){
			printf("%d\n", index[0]);
			prit = 1;				
		}
		exit(0);
	}
	else{
		//printf("\n");
		int i;
		for(i = 0; i<pass_len; ++i){
			new_array_1[i] = array[i];
			new_index_1[i] = index[i];
			//printf("n1: %d,i1: %d\n",new_array_1[i], new_index_1[i]);
		}
		int j;
		for(j = 0; j<pass_len; ++j){
			new_array_2[j] = array[j+i];
			new_index_2[j] = index[j+i];
			//printf("n2: %d,i2 %d\n",new_array_2[j], new_index_2[j]);
		}	
		one = fork();
		if(one == 0){
			calc(new_array_1, new_index_1, num, pass_len);
		}
		else{
			two = fork();
			if(two == 0){
				calc(new_array_2, new_index_2, num, pass_len);
			}
		}
	}
	int status = 0;
	waitpid(one, NULL, 0);
	waitpid(two, NULL, 0);
	while(wait(wpid, &status, 0) == 0);
	if(len != lan)
		exit(0);
	return;
}


int main(int argc, char* args[])
{
	FILE* file;
	char line[256];
	int array[10];
	size_t len;
	int match = 0;
	int actual_len,x;
	int count = 0;
	int numnum = atoi(args[2]);
	if(argc < 3){
		printf("Error: Incorrect Usage. \"Mysearch .txt #\"\n");
		return 1;}
	file = fopen(args[1], "r");
	fgets(line, 256, file);
	if(file == NULL){
		printf("Error: Could not read file.\n");
		return 1;}
	len = strlen(line);
	if(len%2 == 0)
		actual_len = len/2;
	else
		actual_len = len/2 + 1;
	lan = actual_len;
	int i = 0;
	char* tok;
	int num;
	tok = strtok(line, " ");
	while(tok != NULL){
		if(count >= 10){
			printf("error\n-1\n");
			exit(0);}
		sscanf(tok, "%d", &num);
		array[i++] = num;
		tok = strtok(NULL, " ");
		count++;}
	for(x = 0; x< actual_len; ++x)
		if(array[x] == numnum)
			match++;
	int index[i];
	int j;
	for(j=0; j<i; ++j)
		index[j] = j;
	calc(array, index, numnum, actual_len);		
	if(prit != 1)
		if(match == 0)
			printf("-1\n");
	return 0;
}