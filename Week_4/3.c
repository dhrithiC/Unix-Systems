#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
void error(char *);

int main()
{
	int pid, i=0;
	pid=fork();
	if(pid<0)
		error("unable to fork");
	if(pid==0)
		for(i=65; i<91; ++i)
		{
			printf("%c\n", i);
			sleep(rand()%3);
		}
	else
		for(i=97; i<123; ++i)
		{
			printf("%c\n", i);
			sleep(rand()%3);
		}
	return 0;
}
