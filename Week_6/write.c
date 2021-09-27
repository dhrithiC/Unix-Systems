#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	if((fd=open("data.txt", O_WRONLY|O_APPEND|O_CREAT, 0755))==-1)
	{
		perror("open");
		exit(1);
	}
	
	char c='a';
	if((write(fd, (void*)&c, sizeof(char))!=sizeof(char)))
	{
		perror("write");
		exit(1);
	}
	close(fd);
	return 0;
}
