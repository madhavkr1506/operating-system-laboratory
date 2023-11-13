#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char buf[1024];
	ssize_t bytes_read;
	int fd_one=open("third_file",O_RDONLY);
	int fd_two=open("fourth_file",O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while ((bytes_read=read(fd_one,buf,sizeof(buf)))>0){
	ssize_t bytes_to_copy=bytes_read / 2;
	write(fd_two,buf,bytes_to_copy);
	break;
	}
	printf("Successful copy of first half content.\n");
	close(fd_one);
	close(fd_two);
return 0;
}
