#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>


void execute(char** command)
{
	pid_t process, wpid;
	int status;

	if((process = fork()) < 0)
	{
		printf("Could Not Create Child Process!\n");;
		exit(1);
	}
	else if(process == 0)
	{
		if(execv(command[0], command) < 0)
		{
			printf("Invalid Command\n");
		}
	}		
	wait(wpid,NULL,0);

}

int main()
{
	char* input = NULL;
	size_t size = 1024;		

	while(!feof(stdin))
	{
		printf("$ ");
		fflush(stdout);
		char* args[1024];
		char* temp;
		char* temp2;
		char* first;
		char* frist2;
		int count = 0;
		getline(&input, &size, stdin);
		//args[count++] = strtok(input, " ");
		first = "/bin/";	
		frist2 = strtok(input," ");
		char* comb = (char*) malloc(1+strlen(first)+strlen(frist2));
		strcpy(comb, first);
		strcat(comb, frist2);
		args[count++] = comb;
		while(!feof(stdin))
		{
			temp = strtok(NULL, " \n");
			if(temp == NULL)
				break;
			args[count++] = temp; 
		}
		args[count] = NULL;

		execute(args);		
		free(comb);
	}
	
	return 0;
}
