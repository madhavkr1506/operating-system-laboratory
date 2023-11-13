#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int pid;
	pid=getpid();
	printf("current process pid is : %d\n",pid);
	printf("forking a child process\n");
	pid=fork();
	if(pid==0){
		printf("child process is sleeping \n");
		sleep(10);
		printf("orphan child parent id : %d\n",getppid());
	}
	else{
		printf("parent process completed\n");
	}
return 0;
}
