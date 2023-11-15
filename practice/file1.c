#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int a=open("file1.txt",O_RDONLY);
	lseek(a,-6,SEEK_END);
	char buffer[10];
	int c=read(a,buffer,6);
	write(1,buffer,c);
return 0;
}
