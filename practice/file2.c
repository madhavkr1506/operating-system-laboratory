#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char buffer[100];
	int a=open("file1.txt",O_RDWR);
	lseek(a,4,SEEK_SET);
	int b=read(a,buffer,100);
	lseek(a,4,SEEK_SET);
	write(a,"hello",5);
	write(a,buffer,b);
	close(a);
return 0;
}

