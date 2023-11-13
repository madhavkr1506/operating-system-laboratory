#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
FILE *pipe;
char buffer[50];
sprintf(buffer,"good morning");
pipe=popen("wc -c","w");
fwrite(buffer,sizeof(char),strlen(buffer),pipe);
printf("%s",buffer);
pclose(pipe);
}


