#include <stdlib.h>
#include <stdio.h>

void error(char *s)
{
	perror(s);
	exit(1);
}
