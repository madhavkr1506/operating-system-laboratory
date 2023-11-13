#include<stdio.h>
#include<dirent.h>
int main(){
	DIR *dp;
	struct dirent *direntpt;
	dp=opendir("system_call_dir");
	if(dp==NULL){
	printf("error");
	}
	while((direntpt=readdir(dp))!=NULL){
	printf("%S \n",direntpt->d_name);
	printf("%ld \n",direntpt->d_ino);
	}
	closedir(dp);
return 0;
}
