#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int usr1_sent = 0;
int sigint = 0;

void int_handler()
{
	setbuf(stdout, NULL);	
	printf("Signals: %d\n", usr1_sent);
	sigint++;
}

static void usr1_handler(int signum, siginfo_t* info, void *context)
{
	usr1_sent++;
	kill(info->si_pid, SIGUSR2);
}

int main()
{
	struct sigaction act;

	act.sa_sigaction = &usr1_handler;
	act.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &act, NULL);
//	signal(SIGUSR1, usr1_handler);
	signal(SIGINT, int_handler);

	while(1)
	{
		sleep(1);
		if(sigint != 0)
			break;	
	}

	return 0;
}
