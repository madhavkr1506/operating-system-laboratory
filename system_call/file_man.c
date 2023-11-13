#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a,b,c,d,e,f;
	char buffer[100],buffer2[100];
	a=open("file1",O_RDWR);
	printf("file descriptor is %d\n",a);
	b=read(0,buffer,10);
	c=write(a,buffer,b);
	printf("Value of b: %d, c: %d\n",b,c);
	d=open("file2",O_RDWR);
	printf("file discriptor is %d\n",d);
	e=read(1,buffer2,15);
	f=write(d,buffer2,e);
}
