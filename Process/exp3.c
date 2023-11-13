#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
	printf("this is parent process id %d\n",(int)getppid());
	int pid=fork();
	if(pid == 0){
		printf("child %d parent %d\n",(int)getpid(),(int)getppid());
		printf("child %d parent %d\n",(int)getpid(),(int)getppid());
		int pid1=fork();
		if(pid1 == 0){
			printf("child %d parent %d\n",(int)getpid(),(int)getppid());
			int pid=fork();
			if(pid == 0){
				printf("child %d parent %d\n",(int)getpid(),(int)getppid());
			}
		}
	}
	if(pid == 1){
		int pid2=fork();
		if(pid2 == 0){
			printf("child %d  parent %d\n",(int)getpid(),(int)getppid());
		}
	}
return 0;
}
