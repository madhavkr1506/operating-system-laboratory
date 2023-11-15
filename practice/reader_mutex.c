#include<stdio.h>
#include<pthread.h>
int share_data=0;
int read_count=0;
pthread_mutex_t read_mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t write_mutex=PTHREAD_MUTEX_INITIALIZER;
void *reader(void * arg){
	pthread_mutex_lock(&read_mutex);
	read_count++;
	if(read_count == 1){
		pthread_mutex_lock(&write_mutex);
	}
	pthread_mutex_unlock(&read_mutex);
	printf("reader read the data %d\n",share_data);
	pthread_mutex_lock(&read_mutex);
	read_count--;
	if(read_count == 0){
		pthread_mutex_unlock(&write_mutex);
	}
	pthread_mutex_unlock(&read_mutex);
	pthread_exit(NULL);
	return NULL;
}
void *writer(void * arg){
	pthread_mutex_lock(&write_mutex);
	share_data++;
	printf("the writer writes the data %d\n",share_data);
	pthread_mutex_unlock(&write_mutex);
	pthread_exit(NULL);
	return NULL;
}
int main(){
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
