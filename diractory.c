#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
int main(){
	char * path_desk="/home/kali/Desktop";
	char * dir_name="Create_world";
	char new_path_desk[200];
	strcpy(new_path_desk,path_desk);
	strcat(new_path_desk,"/");
	strcat(new_path_desk,dir_name);
	mkdir(new_path_desk,0777);
	printf("new directory has been created %s\n",new_path_desk);
	chdir(new_path_desk);
	char * file_name="earth1";
	int fd=creat(file_name,0666);
	printf("the file has been created %s/%s\n",new_path_desk,file_name);
	close(fd);
	printf("the content in the directory is \n");
	DIR * dir=opendir(".");
	struct dirent *entry;
	while((entry=readdir(dir))){
		printf("%s\n",entry->d_name);
	}
	closedir(dir);
return 0;
}
