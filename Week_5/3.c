#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main()
{
	printf("parent - %ld\n", getpid());
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("child - %ld\n", getpid());
		while(1);
	}
	else
		kill(getpid(), 9);
	return 0;
}
