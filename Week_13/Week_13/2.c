#include <stdio.h>
#include <pthread.h>
void* partial_sum(void*);
int total=0;

struct indices
{
	int i;
	int j;
};

int a[5]={1, 2, 3, 4, 5};

int main()
{
	int i=0;
	int divs=sizeof(a)/(sizeof(int)*2);
	struct indices pos[divs];
	pthread_t id[divs];
	
	pos[0].i=0;
	pos[0].j=divs;
	pos[1].i=divs;
	pos[1].j=sizeof(a)/sizeof(int);
	
	for(i=0; i<divs; ++i)		
		pthread_create(&id[i], NULL, partial_sum, &pos[i]);		

	for(i=0; i<divs; ++i)
		pthread_join(id[i], NULL);

	printf("total=%d\n", total);
	return 0;	
}

void* partial_sum(void* points)
{
	struct indices* idx=(struct indices*)points;
	int i=0, sum=0;
	for(i=idx->i; i<idx->j; ++i)
		sum+=a[i];
	total+=sum;
	printf("sum=%d\n", sum);	
}
