#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a=open("cap2.txt",O_RDONLY);
	int b=lseek(a,-11,SEEK_END);
	//lseek(a,22,SEEK_CUR);
	char buf[b];
	read(a,buf,10);
	write(1,buf,10);
return 0;
}
