#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int num=1;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void * func1(void * arg){
	int a;
	pthread_mutex_lock(&mutex);
	a=num;
	printf("the shared variable of a is %d\n",a);
	a++;
	printf("the local updated value of a is %d\n",a);
	sleep(1);
	num=a;
	printf("the value of num updated by a is %d\n",num);
	pthread_mutex_unlock(&mutex);
}
void * func2(void * arg){
	int b;
	pthread_mutex_lock(&mutex);
	b=num;
	printf("the num variable of b is %d\n",b);
	b--;
	printf("the local updated value of b is %d\n",b);
	sleep(1);
	num=b;
	printf("the value of num updated by b is %d\n",num);
	pthread_mutex_unlock(&mutex);
}
int main(){
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,func1,NULL);
	pthread_create(&thread2,NULL,func2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("the final value of num is %d\n",num);
return 0;
}
