#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
        mkdir("airindia",0777);
        int fd=creat("airindia/flight001",0666);
        close(fd);
        DIR * dir=opendir("airindia");
        struct dirent *ptr;
        while((ptr = readdir(dir))){
                printf("%s\n",ptr->d_name);
        }
        closedir(dir);
return 0;
}
