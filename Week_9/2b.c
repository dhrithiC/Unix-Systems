#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct data
{
	long type;
	char cmd[5];
	int val;
};

int main()
{
	int msqid;
	int key=1000;
	struct data d;
	msqid=msgget(key, 0);
	
	long type=1;
	
	msgrcv(msqid, (void *)&d, sizeof(struct data), 1, 0);
	printf("%s\n", d.cmd);
	return 0;
}
