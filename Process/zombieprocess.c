#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t a;
	a=fork();
	if(a>0){
		sleep(20);
		printf("PID of parent %d\n",getpid());
	}
	else{
		printf("PID of CHILD %d",getpid());
		exit(0);
	}
return 0;
}
