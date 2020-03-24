#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

/*
fork() function creates a child process
Creating process is known as "Parent Process".
The newly creates process is known as "Child Process".

Both the process will use same 
1. Program counter
2. Address Space(Clear from output of program)

*/

/* Although output addresses are same.
In reality actual physical address is different for both process.
However they are assigned same logical address(clear from output)
*/ 

int y=0;
int main()
{
	int x=0;
	pid_t pid;
	pid = fork();
	
	if(pid<0)
	{
	printf("Process Creation Failed");
	}

	else if(pid==0)
	{
	printf("Child Process\n");
	x=x+1;
	y=y+1;
	printf("Local Variable: %d\n",x);
	printf("Global Varible: %d\n",y);
	printf("Address of Local Variable: %p\n",&x);
	printf("Address of Global Varible: %p\n",&y);
	}

	else
	{
	printf("Parent Process\n");
	x=x-1;
	y=y-1;
	printf("Local Variable: %d\n",x);
	printf("Global Varible: %d\n",y);	
	printf("Address of Local Variable: %p\n",&x);
	printf("Address of Global Varible: %p\n",&y);
	}

	return 0;
}
