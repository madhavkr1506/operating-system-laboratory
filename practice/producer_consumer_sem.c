#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<sys/types.h>
#include<fcntl.h>
#include<pthread.h>
struct node{
	int size;
	int top;
	int * arr;
	sem_t lock;
};
int isempty(struct node * ptr){
	if(ptr->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(struct node * ptr){
	if(ptr->top == ptr->size - 1){
		return 1;
	}
	else{
		return 0;
	}
}
void push(struct node * ptr,int data){
	sem_wait(&ptr->lock);
	if(isfull(ptr)){
		printf("stack is full\n");
	}
	else{
		ptr->top++;
		ptr->arr[ptr->top]=data;
		printf("pushing element %d\n",data);
	}
	sem_post(&ptr->lock);

}
int pop(struct node * ptr){
	sem_wait(&ptr->lock);
	if(isempty(ptr)){
		printf("stack is empty\n");
		sem_post(&ptr->lock);
	}
	else{
		int val=ptr->arr[ptr->top];
		printf("poping element %d\n",val);
		ptr->top--;
		sem_post(&ptr->lock);
		return val;
	}
}

void * push_thread(void * arg){
	struct node * ptr=(struct node *)arg;
	int value;
	scanf("%d",&value);
	push(ptr,value);
	return NULL;
}
void * pop_thread(void * arg){
	struct node * ptr=(struct node *)arg;
	int value=pop(ptr);
	return NULL;
}
int main(){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->size=10;
	p->top=-1;
	p->arr=(int *)malloc(p->size * sizeof(int));
	sem_init(&p->lock,0,1);
	pthread_t thread1,thread2;
	int choice;
	while(1){
		scanf("%d",&choice);
		switch(choice){
			case 1 :
			pthread_create(&thread1,NULL,push_thread,(void*)p);
			pthread_join(thread1,NULL);
			break;
			case 2 :
			pthread_create(&thread2,NULL,pop_thread,(void*)p);
			pthread_join(thread2,NULL);
			break;
			default :
			return 0;

		}
	}
return 0;
}









