#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
	int pid;
	pid = getpid();
	printf("current process pid is %d\n",pid);
	printf("forking a child process \n");
	pid = fork();
	if(pid == 0){
		printf("child process id : %d\n and its parent id : %d ",getpid(), getppid());
	}
	else{
		printf("parent process id : %d",getpid());
	}

return 0;
}
