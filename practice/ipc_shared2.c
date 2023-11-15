#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){
	void * shared_memory;
	int shmid;
	char buffer[100];
	shmid=shmget((key_t)4444,1024,0666|IPC_CREAT);
	printf("shmid %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("address %p\n",shared_memory);
	read(0,buffer,100);
	strcpy(shared_memory,buffer);
	printf("you wrote %s\n",(char*)shared_memory);
return 0;
}
