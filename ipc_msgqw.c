#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>

struct msg_buffer{
	long msg_type;
	char msg[100];
}message;

void main()
{
	key_t key;
	int msgid;
	
	key = ftok("progfile",65);

	msgid = msgget(key,0666|IPC_CREAT); // create a message queue and return id

	message.msg_type = 1;

	printf("Write the message: ");
//	fgets(message.msg,100,stdin);
	scanf("%s",message.msg);

	msgsnd(msgid,&message,sizeof(message),0); //send message

	printf("\nSent message is : %s\n",message.msg);
}
