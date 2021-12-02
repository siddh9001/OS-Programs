#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_buffer{
	long msg_type;
	char msg[100];
}message;

void main()
{
	key_t key = ftok("progfile",65);
	int msgid = msgget(key,0666|IPC_CREAT);

	msgrcv(msgid, &message, sizeof(message), 1, 0);
	//fputs(message.msg);
	printf("Message read from the queue is : %s\n",message.msg);

	msgctl(msgid, IPC_RMID, NULL);

	printf("Message queue deleted.\n");
}
