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
int main(){
	pthread_t thread1;
	//char str1[]="madhav";
	char str2[100];
	fgets(str2,sizeof(str2),stdin);
	str2[strcspn(str2,"\n")]='\0';
	//scanf("%s",str2);

	pthread_create(&thread1,NULL,calLength,str2);
	pthread_join(thread1,NULL);

return 0;
}
