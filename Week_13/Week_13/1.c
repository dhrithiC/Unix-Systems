#include <stdio.h>
#include <pthread.h>
#define ROWS 2
#define COLS 2

void* multiply(void*);
void display();

int a[2][2]=
{
	{1, 2},
	{3, 4}
};

int b[2][2]=
{
	{1, 2},
	{3, 4}
};

int c[2][2];

int main()
{
	int i=0;	
	pthread_t id[ROWS];
	for(i=0; i<ROWS; ++i)	
		pthread_create(&id[i], NULL, multiply, (int*)i);
	
	for(i=0; i<ROWS; ++i)
		pthread_join(id[i], NULL);	
	
	display();
	return 0;
}

void* multiply(void* i)
{
	int j, sum, k;
	for(j=0; j<COLS; ++j)
	{
		sum=0;
		for(k=0; k<COLS; ++k)
			sum+=a[(int)i][k]*b[k][j];
		c[(int)i][j]=sum;
	}
}

void display()
{
	int i=0, j=0;
	for(i=0; i<ROWS; ++i)
	{
		for(j=0; j<COLS; ++j)
			printf("%d\t", c[i][j]);
		printf("\n");
	}
}
