#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a,b;
	char buffer[4096];
	ssize_t c;
	off_t fs;
	a=open("hello1.txt",O_RDONLY);
	if (a == -1) return 1;
	fs=lseek(a,0,SEEK_END);
	lseek(a,0,SEEK_SET);
	b=open("world1.txt",O_CREAT | O_WRONLY, 0644);
	if (b == -1) return 1;
	lseek(a,fs/2,SEEK_SET);
	while ((c=read(a,buffer,sizeof(buffer))) > 0) {
		write(b,buffer,c);
	}
	close(a);
	close(b);
	printf("file successfully copied (second half)");
return 0;
}
