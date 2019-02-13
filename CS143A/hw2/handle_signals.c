#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int interrupt = 0;
int stop = 0;
int quit = 0;

void int_handler(int signum)
{
	interrupt++;
	setbuf(stdout, NULL);	
	printf("%c",'I');
}

void tstp_handler(int signum)
{
	stop++;
	setbuf(stdout, NULL);	
	printf("%c",'S');
	kill(getpid(), SIGCONT);	
}

void quit_handler(int signum)
{
	quit++;
	setbuf(stdout, NULL);	
	printf("%c",'Q');
}

int main()
{	
	signal(SIGINT, int_handler);
	signal(SIGTSTP, tstp_handler);
	signal(SIGQUIT, quit_handler);
	while(1)
	{
		sleep(1);
		if(stop == 3)
		{
			printf("\n");
			break;
		}	
	}
	printf("Interrupt: %d\n", interrupt);
	printf("Stop: %d\n", stop);
	printf("Quit: %d\n", quit);

	return 0;
}
