#include<stdio.h>
#include<pthread.h>
void *thread_creation(void * arg){
	int pthread=*((int *)arg);
	printf("the thread %d is running\n",pthread);
	printf("the thread %d is done\n",pthread);
	return NULL;
}
int main(){
	pthread_t thread1,thread2;
	int thread1_val=1;
	int thread2_val=2;
	pthread_create(&thread1,NULL,thread_creation,&thread1_val);
	pthread_create(&thread2,NULL,thread_creation,&thread2_val);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("both thread have completed execution\n");
return 0;
}




