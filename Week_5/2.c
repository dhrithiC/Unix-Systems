#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main()
{
	char** backup=environ;

	char *s="this";
	const char *newenv;
	const char *envchild;
	setenv(newenv, s, 1);
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("************************child******************************\n");
		while(*environ)
			printf("%s\n", *(environ++));	
		char *a="hi";
		setenv(envchild, a, 1);
	}
	else
	{
		sleep(5);	
		printf("************************parent******************************\n");
		printf("%s\n", envchild);
	}

	return 0;
}
