#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	printf("parent id : %d and child id : %d\n",getpid(),getppid());
	int p2=fork();
	if(p2 == 0){
		printf("child id : %d and parent id : %d\n",getpid(),getppid());
		int p3=fork();
		if(p3 == 0){
			printf("child id : %d and parent id : %d\n",getpid(),getppid());
			int p4=fork();
			if(p4 == 0){
				printf("child id : %d and parent id : %d\n",getpid(),getppid());
				sleep(10);
			}
		}
	}
	int p5=fork();
	if(p5 == 0){
		printf("child id : %d and parent id : %d\n",getpid(),getppid());
		int p6=fork();
		if(p6 == 0){
			printf("child id : %d and parent id : %d\n",getpid(),getppid());
			int p7=fork();
			if(p7 == 0){
				printf("child id : %d and parent id : %d\n",getpid(),getppid());
				return 0;
			}
		}
	}
	wait(NULL);
	wait(NULL);
	wait(NULL);
        wait(NULL);
	wait(NULL);
        wait(NULL);
	wait(NULL);
      

return 0;
}
