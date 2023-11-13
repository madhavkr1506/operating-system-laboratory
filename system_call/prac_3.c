#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char buffer[20];
	int i,a,b,c;
	i=open("demo",O_RDWR);
	read(i,buffer,10);
	write(1,buffer,10);
}
