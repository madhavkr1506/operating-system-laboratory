#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a,b,c,d,e;
	char buffer[100];
	//a=open("demo",O_RDWR);
	a=open("demo",O_WRONLY | O_APPEND);
	b=read(0,buffer,100);
	c=write(a,buffer,50);
	write(1,buffer,50);
	printf("value of c: %d, b: %d",c,b);
	//read(a,buffer,10);
	//write(1,buffer,10);
	//lseek(a,10,SEEK_CUR);
	//read(a,buffer,10);
	//write(1,buffer,10);
return 0;
}

