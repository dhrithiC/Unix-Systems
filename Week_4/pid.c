#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void error(char *);

int main()
{
	int pid;
	pid=fork();
	if(pid<0)
		error("unable to fork");
	if(pid==0)
		printf("child pid=%ld\n", getpid());
	else
		printf("parent pid=%ld\n", getpid());
	return 0;
}
