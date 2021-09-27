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
	msqid=msgget(key,0);
	
	d.type=1;
	strcpy(d.cmd, "sqr");
	d.val=4;
	
	msgsnd(msqid, (void *)&d, sizeof(d), 0);
	return 0;
}
