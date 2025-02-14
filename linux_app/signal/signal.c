#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void sig_func(int sig_no)
{
	if(sig_no == SIGINT)
	{
		printf("I get SIGINT!\n");
	}
	else if(sig_no == SIGQUIT)
	{
		printf("I get SIGQUIT\n");
	}
	else
	{
		printf("invaild signal!\n");
	}
}

int main()
{
	printf("wait for signal...\n");

	signal(SIGINT, sig_func);
	signal(SIGQUIT, sig_func);

	pause();

	return 0;
}
