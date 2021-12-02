#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SIZE 16
char *msg1 = "Hello Sid! #1  ";
char *msg2 = "Hello Patle! #2";

void main()
{	
	char inbuff[MAX_SIZE];
	int p[2],i,pipe_id;

	pipe_id = pipe(p);

	if(pipe_id < 0)
		exit(1);

	int pid = fork();

	if(pid < 0) 
		printf("Fork error\n");

	if(pid > 0)
	{
		printf("Parent process is writing the message in pipe\n");
		write(p[1], msg1, MAX_SIZE);
		write(p[1], msg2, MAX_SIZE);
	}

	else
	{
		printf("Child process is reading message from pipe\n");
		for(i = 0; i < 2; i++)
		{
			read(p[0], inbuff, MAX_SIZE);
			printf("%s \n",inbuff);
		}
	}
}
