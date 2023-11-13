#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
struct node{
	int size;
	int top;
	int * arr;
	pthread_mutex_t lock;
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
	pthread_mutex_lock(&ptr->lock);
	if(isfull(ptr)){
		printf("stack is full\n");
	}
	else{
		ptr->top++;
		ptr->arr[ptr->top]=data;
		printf("pushing element %d\n",data);
	}
	pthread_mutex_unlock(&ptr->lock);
}
int pop(struct node * ptr){
	pthread_mutex_lock(&ptr->lock);
	if(isempty(ptr)){
		printf("stack is empty\n");
		pthread_mutex_unlock(&ptr->lock);
		return -1;
	}
	else{
		int val=ptr->arr[ptr->top];
		printf("poping element %d\n",val);
		ptr->top--;
		pthread_mutex_unlock(&ptr->lock);
		return val;
	}
}
void * push_thread(void * arg){
	struct node * ptr=(struct node *)arg;
	int ele;
	scanf("%d",&ele);
	push(ptr,ele);
	return NULL;
}
void * pop_thread(void * arg){
	struct node * ptr=(struct node *)arg;
	int value=pop(ptr);
	return NULL;
}
int main(){
	struct node * p=(struct node *)malloc(sizeof(struct node ));
	p->size=10;
	p->top=-1;
	p->arr=(int *)malloc(p->size * sizeof(int));
	pthread_mutex_init(&p->lock,NULL);
	pthread_t thread_push,thread_pop;
	int choice;
	while(1){
		scanf("%d",&choice);
		switch(choice){
			case 1 :
			pthread_create(&thread_push,NULL,push_thread,(void*)p);
			pthread_join(thread_push,NULL);
			break;
			case 2 : 
			pthread_create(&thread_pop,NULL,pop_thread,(void*)p);
			pthread_join(thread_pop,NULL);
			break;
			default :
			exit(0);
		}
	}
return 0;
}












