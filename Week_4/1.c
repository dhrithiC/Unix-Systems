#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void error(char *);

int main()
{
	fork();
	fork() && fork() || fork();
    fork();
    printf("test\n");
    
    return 0;
}
