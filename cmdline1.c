#include <stdio.h>
#include <unistd.h>

void main(int argc, char* argv[])
{
	printf("Before Execution Process id is:%d\n",getpid());
	printf("exec starts \n");
	printf("argc %d \n",argc);
	printf("argv arguments %s %s %s %s %s \n",argv[0], argv[1], argv[2], argv[3], argv[4]);

	execl(argv[1], argv[2], argv[3], argv[4], NULL);
}
