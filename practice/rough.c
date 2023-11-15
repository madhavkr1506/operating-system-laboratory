#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>


int main(){
	int fd=open("file1.txt",O_RDONLY);
	char buffer[100];
	int size=lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	while(read(fd,buffer,1)>0){
		write(1,buffer,1);
	}
	lseek(fd,0,SEEK_SET);
	char s;
	scanf("%c",&s);
	while(read(fd,buffer,1)>0){
		if(buffer[0]==s){
			printf("found\n");
			break;
		}
	}
return 0;
}
