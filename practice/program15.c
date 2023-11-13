#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char buffer[100];
	int a=open("file1.txt",O_RDWR | O_APPEND);
	// read from file and print it on console
	//read(a,buffer,100);
	//write(1,buffer,100);
	// take input from console and write into the file);
	//read(1,buffer,100);
	//write(a,buffer,100);
	// take input from the console and print same on the console;
	//read(1,buffer,100);
	//write(1,buffer,100);
	// take input from console and write into file and print into console
	read(0,buffer,100);
	write(a,buffer,100);
	write(1,buffer,100);
	
return 0;
}
