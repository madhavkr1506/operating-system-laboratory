#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char buffer[100];
	FILE * pipe;
	pipe=popen("wc -c","w");
	sprintf(buffer,"madhav kumar");
	fwrite(buffer,sizeof(char),strlen(buffer),pipe);
	printf("%s",buffer);
	pclose(pipe);
return 0;
}
