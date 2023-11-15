#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	void *shared_memory;
	int shmid;
	char buffer[100];

	shmid=shmget((key_t)1112,1024,0666|IPC_CREAT);
	printf("%d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("%p\n",shared_memory);
	read(0,buffer,100);
	strcpy(shared_memory,buffer);
	printf("%s",(char*)shared_memory);
return 0;
}
