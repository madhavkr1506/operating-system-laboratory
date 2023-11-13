#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t p3,p2,p1,p4,p5;
	if((p3 = fork()) == 0){
		printf("this is process three having id %d and my parent process id is %d \n",getpid(),getppid())
		exit(0);
	}
	if((p2 = fork()) == o){
		printf("this is child process two having id %d and my parent process id %d \n",getpid(),getppid());
	 	if((p1 = fork()) == 0){
			printf("this is child process one having id %d and my parent process id is %d \n",getpid(),getppid());
			if((p4 = fork()) == 0){
				printf("this is child process four having id %d and my parent process id is %d \n",getpid(),getppid()); 
				sleep(2);
				printf("process four now is an orphan and its id %d\n",getpid());
			}
			else{
				wait(NULL);
			}
			if((p5 = fork()) == 0){
				printf("this is child process five having id %dand my parent process id is %d \n",getpid(),getppid());
				exit(0);
			}
			exit(0);
		}
		else{
			wait(NULL);
		}
		exit(0);
	}
	wait(NULL);
	printf("this is process three having id %d \n",getpid());
	exit(0);
return 0;
}
