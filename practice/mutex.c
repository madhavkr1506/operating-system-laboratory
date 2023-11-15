#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
int globaldata=1;
pthread_mutex_t locker=PTHREAD_MUTEX_INITIALIZER;
void * reader(void * arg){
	int a;
	pthread_mutex_lock(&locker);
	a=globaldata;
	a++;
	printf("local update by a %d\n",a);
	sleep(1);
	globaldata=a;
	printf("updated value by a %d\n",globaldata);
	pthread_mutex_unlock(&locker);
}
void * writer(void * arg){
	int b;
	pthread_mutex_lock(&locker);
	b=globaldata;
	b--;
	printf("local update by b %d\n",b);
	sleep(1);
	globaldata=b;
	printf("updated value by b %d\n",globaldata);
	pthread_mutex_unlock(&locker);
}
int main(){
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,reader,NULL);
	pthread_create(&thread2,NULL,writer,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("final globaldata %d\n",globaldata);
return 0;
}
