#include<stdio.h>
#include<pthread.h>
int num;
int arr[100];
void * average(void * arg){
	float sum=0.0;
	int count=0;
	for(int i=0;i<num;i++){
		sum+=arr[i];
		count++;
	}
	float avge=sum/count;
	printf("the average value of the array is %.2f\n",avge);
	return NULL;
}
void * maximum(void * arg){
	int maxi=arr[0];
	for(int i=0;i<num;i++){
		if(arr[i] > maxi){
			maxi=arr[i];
		}
	}
	printf("the maximum value of the array id %d\n",maxi);
	return NULL;
}
void * minimum(void * arg){
	int mini=arr[0];
	for(int i=0;i<num;i++){
		if(arr[i] < mini){
			mini=arr[i];
		}
	}
	printf("the minimum value of the array is %d\n",mini);
	return NULL;
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
	pthread_create(&thread1,NULL,average,&avg);
	pthread_create(&thread2,NULL,maximum,&maxi);
	pthread_create(&thread3,NULL,minimum,&mini);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
return 0;
}
