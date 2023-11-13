#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define readercount 5
#define writercount 6

int globalvalue=0;
int reader=0;
sem_t readmutex;
sem_t writemutex;
pthread_mutex_t readvariable=PTHREAD_MUTEX_INITIALIZER;

void * reader_thread(void * arg){
	sem_wait(&readmutex);
	pthread_mutex_lock(&readvariable);
	reader++;
	if(reader == 1){
		sem_wait(&writemutex);
	}
	pthread_mutex_unlock(&readvariable);
	sem_post(&readmutex);
	printf("the reader reads the globalvalue %d\n",globalvalue);
	sem_wait(&readmutex);
	pthread_mutex_lock(&readvariable);
	reader--;
	if(reader == 0){
		sem_post(&writemutex);
	}
	pthread_mutex_unlock(&readvariable);
	sem_post(&readmutex);
	pthread_exit(NULL);
	return NULL;
}

void * writer_thread(void * arg){
	sem_wait(&writemutex);
	globalvalue++;
	printf("the writer write the globalvalue %d\n",globalvalue);
	sem_post(&writemutex);
	pthread_exit(NULL);
	return NULL;
}

int main(){
	sem_init(&readmutex,0,1);
	sem_init(&writemutex,0,1);
	pthread_t thread1[readercount];
	pthread_t thread2[writercount];
	for(int i=0;i<readercount;i++){
		pthread_create(&thread1[i],NULL,reader_thread,NULL);
	}
	for(int i=0;i<writercount;i++){
		pthread_create(&thread2[i],NULL,writer_thread,NULL);
	}
	for(int i=0;i<readercount;i++){
		pthread_join(thread1[i],NULL);
	}
	for(int i=0;i<writercount;i++){
		pthread_join(thread2[i],NULL);
	}
	printf("program terminated\n");
return 0;
}
