#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int num;
int arr[100];
void * operationaverage(void * arg){
	int count=0;
	float sum=0.0;
	for(int i=0;i<num;i++){
		sum=sum+arr[i];
		count++;
	}
	float avg=sum/count;
	printf("average is %.2f\n",avg);
}
void * operationmaximum(void * arg){
	int maximum=arr[0];
	for(int i=0;i<num;i++){
		if(arr[i] > maximum){
			maximum=arr[i];
		}
	}
	printf("maximum element is %d\n",maximum);
}
void * operationminimum(void * arg){
        int minimum=arr[0];
        for(int i=0;i<num;i++){
                if(arr[i] < minimum){
                        minimum=arr[i];
                }
        }
        printf("minimum element is %d\n",minimum);
}

int main(){
	pthread_t thread1,thread2,thread3;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	int maxi;
	int mini;
	int avg;
	pthread_create(&thread1,NULL,operationmaximum,&maxi);
	pthread_create(&thread2,NULL,operationminimum,&mini);
	pthread_create(&thread3,NULL,operationaverage,&avg);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
return 0;
}
