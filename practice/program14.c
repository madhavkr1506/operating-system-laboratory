#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define no_of_reader 5
#define no_of_writer 6
int readercount=0;
int globalvalue=0;
sem_t mutex;
sem_t writemutex;
pthread_mutex_t read1=PTHREAD_MUTEX_INITIALIZER;
void * readers(void * arg){
    sem_wait(&mutex);
    pthread_mutex_lock(&read1);
    readercount++;
    if(readercount==1){
        sem_wait(&writemutex);
    }
    pthread_mutex_unlock(&read1);
    sem_post(&mutex);
    printf("the reader read the global variable %d\n",globalvalue);
    sem_wait(&mutex);
    pthread_mutex_lock(&read1);
    readercount--;
    if(readercount==0){
        sem_post(&writemutex);
    }
    pthread_mutex_unlock(&read1);
    sem_post(&mutex);
    pthread_exit(NULL);
    return NULL;
}
void * writers(void * arg){
    sem_wait(&writemutex);
    globalvalue++;
    printf("the writer write the globalvalues %d\n",globalvalue);
    sem_post(&writemutex);
    pthread_exit(NULL);
    return NULL;
}
int main(){
    sem_init(&mutex,0,1);
    sem_init(&writemutex,0,1);
    pthread_t thread1[no_of_reader];
    pthread_t thread2[no_of_writer];
    for(int i=0;i<no_of_reader;i++){
        pthread_create(&thread1[i],NULL,readers,NULL);
    }
    for(int i=0;i<no_of_writer;i++){
        pthread_create(&thread2[i],NULL,writers,NULL);
    }
    for(int i=0;i<no_of_reader;i++){
        pthread_join(thread1[i],NULL);
    }
    for(int i=0;i<no_of_writer;i++){
        pthread_join(thread2[i],NULL);
    }

return 0;
}
