#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	pid_t pid = fork();
	if(pid == -1)
		printf("Not able to create child process");
	if(pid == 0)
	{
		printf("Child id  is: %d \n",getpid()); 
		printf("Child parent is: %d \n",getppid());	
	}
	else
	{
		printf("parent id is: %d \n",getpid());
		printf("Parent Parent id is: %d \n",getppid());
	
	}
	return 0;
}
