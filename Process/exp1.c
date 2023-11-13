#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int clo;
		clo=fork();
		if(clo == 0){
			printf("child %d\n",getpid());
		}
		else{
			printf("parent %d\n",getppid());
		}
	}
return 0;
}

