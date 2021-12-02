#include <stdio.h>
#include <unistd.h>

void main(int argc, char* argv[])
{
	printf("Overlayed process id:%d\n", getpid());
	printf("argc count in the child: %d\n", argc);
	printf("child id %s and its arguments are %s %s \n", argv[0], argv[1], argv[2]);
	printf("execl ends\n");
}
