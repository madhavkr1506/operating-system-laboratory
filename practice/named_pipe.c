#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>


int main(){
	int fd[2];
	int p;
	char buffer[100];
	mkfifo("madhav.fifo",0777);
	p=fork();
	if(p==0){
		fd[1]=open("madhav.fifo",O_WRONLY);
		write(fd[1],"hello world",11);
		close(fd[1]);
	}
	else{
		fd[0]=open("madhav.fifo",O_RDONLY);
		int b=read(fd[0],buffer,100);
		write(1,buffer,b);
		close(fd[0]);
	}
return 0;
}
