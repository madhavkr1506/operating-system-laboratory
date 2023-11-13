#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct node{
	int s;
	int top;
	int * arr;
	pthread_mutex_t lock;
};
int isempty(struct node * ptr){
	if(ptr->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(struct node * ptr){
	if(ptr->top==ptr->s-1){
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
	}
	else{
		int val=ptr->arr[ptr->top];
		printf("poping element %d\n",val);
		ptr->top--;
		pthread_mutex_unlock(&ptr->lock);
		return val;
	}
}
void * thread_function(void * arg){
	struct node * ptr=(struct node *)arg;
	push(ptr,56);
	pop(ptr);
	return NULL;
}
int main(){
	struct node * p=(struct node *)malloc(sizeof(struct node));
	p->s=10;
	p->top=-1;
	p->arr=(int *)malloc(p->s * sizeof(int));
	pthread_mutex_init(&p->lock,NULL);
	pthread_t thread1;
	pthread_create(&thread1,NULL,thread_function,(void *)p);
	int num;
	while(1){
		scanf("%d",&num);
		switch(num){
			case 1 :
			int ele;
			scanf("%d",&ele);
			push(p,ele);
			break;
			case 2 :
			pop(p);
			break;
			default :
			return 0;
		}
	}
	pthread_join(thread1,NULL);
return 0;
}
