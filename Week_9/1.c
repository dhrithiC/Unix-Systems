#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	if(pipe(fd)==-1)
	{
		perror("pipe");
		exit(1);
	}
	
	if(fork()!=0)
	{
		char data[]="hello";
		write(fd[1], data, strlen(data));
		wait((void *)0);
		read(fd[0], data, strlen(data));
		printf("message from child:%s\n", data);
	}
	else
	{
		char data[5];
		read(fd[0], data, strlen(data));
		if(data[0]>=97 && data[0]<=123)
			data[0]-=32;		
		write(fd[1], data, strlen(data));
	}
	
	return 0;
}
