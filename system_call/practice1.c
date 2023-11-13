#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int a;
	char buffer;
	a = open("input.txt",  O_RDONLY);
	if (a == -1) {
		printf("Error opening input file");
		return 1;
	}
	while (read(a, &buffer, 1) > 0) {
		write(STDOUT_FILENO, &buffer, 1);
	}
	close(a);
	return 0;
} 
