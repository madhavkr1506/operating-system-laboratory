#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
	FILE * pipe;
	//pipe=popen("wc -c","w");
	//pipe=popen("madhav","w");
	char buffer[100];
	sprintf(buffer,"hello madhav kumar");
	pipe=popen("wc -c","w");
	fwrite(buffer,sizeof(char),strlen(buffer),pipe);
	printf("%s",buffer);
	fclose(pipe);
return 0;
}
