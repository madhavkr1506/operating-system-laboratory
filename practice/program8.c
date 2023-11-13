#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
struct node
{
int size;
int top;
int * arr;
pthread_mutex_t lock;
};
int isempty(struct node * ptr)
{
	if(ptr->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(struct node * ptr)
{
	if(ptr->top == ptr->size - 1){
		return 1;
	}
	else{
		return 0;
	}
}
void push(struct node * ptr,int data)
{
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
int pop(struct node * ptr)
{
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
	for(int i=0;i<5;i++){
		scanf("%d",&ele);
		push(ptr,ele);
	}
	return NULL;
}

void * pop_thread(void * arg){
	struct node * ptr=(struct node *)arg;
	sleep(5);
	for(int i=0;i<5;i++){
		int value=pop(ptr);
		sleep(5);
	}
	return NULL;
}
int main(){
	struct node * p=(struct node *)malloc(sizeof(struct node ));
	p->size=10;
	p->top=-1;
	p->arr=(int *)malloc(p->size * sizeof(int));
	pthread_mutex_init(&p->lock,NULL);
	pthread_t push_thread1,pop_thread2;
	pthread_create(&push_thread1,NULL,push_thread,(void*)p);
	pthread_create(&pop_thread2,NULL,pop_thread,(void*)p);
	pthread_join(push_thread1,NULL);
	pthread_join(pop_thread2,NULL);
return 0;
}
