#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){
	void *shared_memory;
	int shmid;
	char buffer[100];
	shmid=shmget((key_t)1112,1024,0666);
	printf("%d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("%p\n",shared_memory);
	printf("%s\n",(char*)shared_memory);
return 0;
}
