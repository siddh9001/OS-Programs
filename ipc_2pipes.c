#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SIZE 20
char *msg1 = "Hello child!";
char *msg2 = "Hello parent!";

void main()
{
	char inbuff1[MAX_SIZE], inbuff2[MAX_SIZE];
	int pid, i, pipe_id1, pipe_id2;
	int p1[2],p2[2];

	pipe_id1 = pipe(p1);
	pipe_id2 = pipe(p2);

	if(pipe_id1 < 0 || pipe_id2 < 0)
		exit(1);

	pid = fork();

	if(pid < 0) printf("Fork error\n");

	if(pid > 0)
	{
		printf("Parent process is writing content in pipe 1\n");
		write(p1[1], msg1, MAX_SIZE);
		

		printf("Parent process reading data from pipe 2\n");
		read(p2[0], inbuff2, MAX_SIZE);
		printf("%s\n",inbuff2);
	
	}

	else
	{
		printf("Child process is reading content from pipe 1\n");
		read(p1[0], inbuff1, MAX_SIZE);
		printf("%s\n", inbuff1);
		

		printf("Child process is writing masg in pipe 2\n");
		write(p2[1], msg2, MAX_SIZE);

	}
}
