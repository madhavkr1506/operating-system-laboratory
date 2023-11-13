#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int a, b;
	char buffer;
	a=open("file1",O_WRONLY | O_APPEND);
	while (1) {
		 scanf("%c", &buffer);
		if (buffer == '$') {
			break;
		}
		write(a, &buffer, 1);
	}
	close(a);
return 0;
}
