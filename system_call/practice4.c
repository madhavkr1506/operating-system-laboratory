#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a,b,c,d,e;
	char buffer[200];
	a=open("program.txt",O_RDONLY);
	b=open("program.txt",O_RDONLY);
	lseek(a,0,SEEK_CUR);
	read(a,buffer,28);
	write(1,buffer,28);
	//b=lseek(a,0,SEEK_END);
	//lseek(a,0,SEEK_SET);
	//c=read(a,buffer,28);
	//write(1,buffer,28);
	printf("\n");
	lseek(b,55,SEEK_CUR);
	read(b,buffer,75);
	write(1,buffer,75);

return 0;
}
