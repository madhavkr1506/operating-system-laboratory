#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
	mkdir("hello",0777);
	mkdir("world",0777);
	int fd=creat("hello/page1",0666);
	int fd2=creat("world/page2",0666);
	char buffer[100];
	scanf("%[^\n]s",&buffer);
	int size=0;
	for(int i=0;i<=100;i++){
		if(buffer[i] == '\0'){
			break;
		}
		size++;
	}
	write(fd,buffer,size);
	write(fd2,buffer,size);

	system("cp -r hello/* world");

	close(fd);
	close(fd2);
return 0;
}
