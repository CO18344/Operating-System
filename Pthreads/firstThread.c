//Compile the following code in linux with command: gcc firstThread.c -o out -l pthread
#include<stdio.h>
#include<pthread.h>

/*This function prints 1 to 15 numbers*/
void* print1_To_10(void *thread_id);


/*This function creates delay*/
void delay();
/*Appropriate delay is required to produce in order to view threading effect*/



int main()
{
	/*Information regarding thread1*/
	int id1=1;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,print1_To_10,(void*)&id1);
	
	/*Information regarding thread2*/
	int id2=2;
	pthread_t tid2;
	pthread_attr_t attr2;
	pthread_attr_init(&attr2);
	pthread_create(&tid2,&attr2,print1_To_10,(void*)&id2);
	
	
	/*main thread will wait for both threads to finish*/
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	
	return 0;
}

void* print1_To_10(void *thread_id)
{

	int i;
	int *id = (int*)thread_id;
	for(i=1;i<=10;i++)
	{
		delay();
		printf("\nThread id = %d, value = %d",*id,i);
		
	}
	printf("\n");
	pthread_exit(0);
}

void delay()
{
	int i;
	for(i=0;i<500000;i++);
	return;
}
