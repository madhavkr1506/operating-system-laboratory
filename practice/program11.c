#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define num_of_reader 5
#define num_of_writer 4
sem_t mutex;
sem_t writemutex;
int globaldata=0;
int readercount=0;

void * readers(void * arg){
	sem_wait(&mutex);
	readercount++;
	if(readercount==1){
		sem_wait(&writemutex);
	}
	sem_post(&mutex);
	printf("readers reads global data %d\n",globaldata);
	sem_wait(&mutex);
	readercount--;
	if(readercount == 0){
		sem_post(&writemutex);
	}
	sem_post(&mutex);
	pthread_exit(NULL);
	sleep(1);
	return NULL;
}
void * writers(void * arg){
	sem_wait(&writemutex);
	globaldata++;
	printf("the writer write global data %d\n",globaldata);
	sem_post(&writemutex);
	pthread_exit(NULL);
	sleep(1);
	return NULL;
}
int main(){
	sem_init(&mutex,0,1);
	sem_init(&writemutex,0,1);
	pthread_t thread1[num_of_reader];
	pthread_t thread2[num_of_writer];
	for(int i=0;i<num_of_reader;i++){
		pthread_create(&thread1[i],NULL,readers,NULL);
	}
	for(int i=0;i<num_of_writer;i++){
		pthread_create(&thread2[i],NULL,writers,NULL);
	}
	for(int i=0;i<num_of_reader;i++){
		pthread_join(thread1[i],NULL);
	}
	for(int i=0;i<num_of_writer;i++){
		pthread_join(thread2[i],NULL);
	}
	printf("program termineted\n");

return 0;
}
