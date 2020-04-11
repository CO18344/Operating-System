#include<stdio.h>
#include<pthread.h>


void* do_nothing(void *data);
int S=0;//Semaphore
//0 value indicates that all threads will wait for cpu
void wait();
void signal();

int main()
{
	int id1=1;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,do_nothing,(void*)&id1);

	int id2=2;
	pthread_t tid2;
	pthread_attr_t attr2;
	pthread_attr_init(&attr2);
	pthread_create(&tid2,&attr2,do_nothing,(void*)&id2);

	int id3=3;
	pthread_t tid3;
	pthread_attr_t attr3;
	pthread_attr_init(&attr3);
	pthread_create(&tid3,&attr3,do_nothing,(void*)&id3);

	
	int x=0;
	
	while(1)
	{
		scanf("%d",&x);
		if(x==1)
		{
			signal();
		}
		else
			break;
			
		
	}
	printf("\nOut of loop\n");
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);

	
	return 0;
}
char str[]={"Thread1"};
void* do_nothing(void *data)
{
	int id = *((int*)data);
	wait();
	printf("Thread %d grabbed cpu",id);
	pthread_exit(0);
}

void wait()
{
	while(S<=0);
	S--;
}

void signal()
{
	S++;
}
