#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	printf("parent %d\n",(int)getppid());
	int pid=fork();
	//printf("parent %d\n",(int)getppid());
	if(pid == 0){
		printf("child %d\nparent %d\n",(int)getpid(),(int)getppid());
		int pid1=fork();
		if( pid1 == 0){
			printf("child %d\nparent %d\n",(int)getpid(),(int)getppid());
		}
	}
return 0;
}
