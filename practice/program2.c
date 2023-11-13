#include<stdio.h>
#include<string.h>
#include<pthread.h>
void * lencalculation(void * arg){
	char * string1=(char *)arg;
	int i;
	for(i=0;string1[i]!='\0';i++);
	printf("the string length is %d\n",i);
	return NULL;
}
int main(){
	pthread_t thread1;
	//char str1[]="Madhav";
	char str1[100];
	fgets(str1,sizeof(str1),stdin);
	str1[strcspn(str1,"\n")]='\0';
	pthread_create(&thread1,NULL,lencalculation,str1);
	pthread_join(thread1,NULL);
return 0;
}
