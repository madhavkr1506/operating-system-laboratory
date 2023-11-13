#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a=open("program.txt",O_RDONLY);
	int filesize=lseek(a,0,SEEK_END);
	int first_term=filesize-50;
	char buf1[first_term];
	lseek(a,0,SEEK_SET);
	read(a,buf1,first_term);
	write(1,buf1,first_term);
	printf("\n");
	int pos=first_term+27;
	int sec_term=filesize-pos;
	char buf2[sec_term];
	lseek(a,pos,SEEK_SET);
	read(a,buf2,sec_term);
	write(1,buf2,sec_term);
return 0;
}
