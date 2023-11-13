#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int a, b;
	char buffer[100];
	a=open("cap21.txt",O_WRONLY | O_APPEND);
	read(0,buffer,100);
	if (buffer[0] == '$') {
		return 0;
	}
	else{
		write(a,buffer,100);
	}
	close(a);
return 0;
}
