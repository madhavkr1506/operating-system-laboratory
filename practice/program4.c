//wap to create implement ipc using popen and pclose
//wap to create two thread one thread will welocme to lpu and count char

#include<stdio.h>
#include<string.h>
#include<pthread.h>
void * calLength(void * arg){
	char * string1=(char *)arg;
	int i;
	int count=0;
	for(i=0;string1[i] != '\0';i++){
		count++;
	}
	printf("length of the string is %d\n",count);

	return NULL;
}
void * display(void * arg){
	char * string2=(char*)arg;
	printf("%s\n",string2);
	return NULL;
}
int main(){
	pthread_t thread1,thread2;
	char str2[100]="welcome to lpu";
	//pthread_create(&thread1,NULL,calLength,str2);
	pthread_create(&thread2,NULL,display,str2);
	pthread_create(&thread1,NULL,calLength,str2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

return 0;
}

