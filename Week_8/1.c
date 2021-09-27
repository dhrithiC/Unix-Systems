#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#define SIZE 10

int board[SIZE][SIZE];
int p, c=1;

void display(int);
void handler();
void fill_board();

void display(int i)
{
	int j;
	for(j=0; j<SIZE; ++j)
		printf("%d\t", board[i][j]);
	printf("\n");
}

void handler(){}

void init_task()
{
	fill_board();
	signal(SIGUSR1, handler);	
	signal(SIGINT, exit);
}

void fill_board()
{
	int i, j, val=100;
	for(i=0; i<SIZE; ++i)
		for(j=0; j<SIZE; ++j)
			board[i][i%2?SIZE-j-1:j]=val--;
}

int main()
{	
	int pid;
	if((pid=fork())!=0)
	{
		// parent
		init_task();
		display(p);
		sleep(2);
		kill(pid, SIGUSR1);

		while(1)
		{					
			pause();			
			display(p+=2);
			sleep(2);
			kill(pid, SIGUSR1);
		}
	}
	else
	{
		init_task();
				
		while(1)
		{
			pause();
			display(c);
			c+=2;
			kill(getppid(), SIGUSR1);
		}		
	}
/*	printf("pid:%d\n", getpid());
	
	while(1)
		pause();	
*/
	return 0;
}
