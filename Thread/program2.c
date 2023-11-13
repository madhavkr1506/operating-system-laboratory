#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *addingstring(void * arg){
	char * string1=(char *)arg;
	char * string2=(char *)(arg + strlen(string1) + 1);
	char result[100];
	strcpy(result,string1);
	strcat(result,string2);
	printf("string concatination %s\n",result);
	return NULL;
}
int main(){
	pthread_t thread1;
	char str1[]="madhav ";
	char str2[]="kumar ";
	char stringconcat[100];
	strcpy(stringconcat,str1);
	strcat(stringconcat,str2);
	pthread_create(&thread1,NULL,addingstring,stringconcat);
	pthread_join(thread1,NULL);
	printf("concatination of string %s",stringconcat);
return 0;
}
