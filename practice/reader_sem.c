#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int read_count=0;
int share_data=0;
sem_t readmutex;
sem_t writemutex;
void * reader(void * arg){
	sem_wait(&readmutex);
	read_count++;
	if(read_count == 1){
		sem_wait(&writemutex);
	}
	sem_post(&readmutex);
	printf("the reader reads the value %d\n",share_data);
	sem_wait(&readmutex);
	read_count--;
	if(read_count == 0){
		sem_post(&writemutex);
	}
	sem_post(&readmutex);
	pthread_exit(NULL);
	return NULL;
}
void * writer(void * arg){
	sem_wait(&writemutex);
	share_data++;
	printf("the writer writes the data %d\n",share_data);
	sem_post(&writemutex);
	pthread_exit(NULL);
	return NULL;
}
int main(){
	sem_init(&readmutex,0,1);
	sem_init(&writemutex,0,2);
	pthread_t thread1[3],thread2[4];
	for(int i=0;i<3;i++){
		pthread_create(&thread1[i],NULL,reader,NULL);
	}
	for(int i=0;i<4;i++){
		pthread_create(&thread2[i],NULL,writer,NULL);
	}
	for(int i=0;i<3;i++){
		pthread_join(thread1[i],NULL);
	}
	for(int i=0;i<4;i++){
		pthread_join(thread2[i],NULL);
	}
return 0;
}

