#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		if(fork() == 0){
			printf("my process id is %d and my parent process id is %d\n",getpid(),getppid());
		}
	}
	sleep(1);
return 0;
}
