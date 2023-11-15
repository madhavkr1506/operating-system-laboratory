#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
int main(){
	void * shared_memory;
	char buffer[100];
	int shmid;
	shmid=shmget((key_t)4444,1024,0666);
	printf("%d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("%p\n",shared_memory);
	printf("%s",(char*)shared_memory);

return 0;
}
