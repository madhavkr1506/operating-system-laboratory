#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t p2, p3;
	printf("my process id is %d and my parent process id is %d\n",getpid(),getppid());
	p2=fork();
	if(p2 == 0){
		printf("my process id is %d and my parent process id is %d\n",getpid(),getppid());
		if((p3=fork()) == 0){
			printf("my process id is %d and my parent process id is %d\n",getpid(),getppid());
		}
		else if(p3 > 0){
			wait(NULL);
		}
	}
	else if(p2 > 0){
		wait(NULL);
	}
return 0;
}
