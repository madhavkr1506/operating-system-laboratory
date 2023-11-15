#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int fd[2];
	int p;
	pipe(fd);
	char buffer[100];
	p=fork();
	if(p>0){
		printf("passing message to child\n");
		write(fd[1],"hello madhav",13);
	}
	else{
		printf("child receiving message\n");
		int b=read(fd[0],buffer,100);
		write(1,buffer,b);
	}
return 0;
}
