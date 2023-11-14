#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	mkdir("/home/kali/Desktop/Packet",0777);
	printf("the  directory has been created \n");
	chdir("/home/kali/Desktop/Packet");
	int fd=creat("Mars1.txt",0666);
	printf("file has been created\n");
	close(fd);
	DIR * dir=opendir(".");
	struct dirent * entry;
	while((entry=readdir(dir))){
		printf("%s\n",entry->d_name);
	}
	mkdir("/home/kali/Desktop/Enough",0777);
	system("cp -r /home/kali/Desktop/Packet/*  /home/kali/Desktop/Enough/");
	closedir(dir);
return 0;
}
