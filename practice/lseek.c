#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a=open("file1.txt",O_RDONLY);
	//int size=lseek(a,0,SEEK_END);
	int b=lseek(a,0,SEEK_SET);
	char buf1[b];
	read(a,buf1,5);
	write(1,buf1,5);
	close(a);
	int k=open("file1.txt",O_RDONLY);
	int m=lseek(k,10,SEEK_CUR);
	char buf3[m];
	read(k,buf3,5);
	write(1,buf3,5);
	int c=lseek(k,-6,SEEK_END);
	char buf2[c];
	read(k,buf2,5);
	write(1,buf2,5);
return 0;
}
