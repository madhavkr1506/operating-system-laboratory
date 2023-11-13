#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

void *fun1(void *arg);
void *fun2(void *arg);

int shared = 1; // Shared variable
sem_t s; // Semaphore variable

int main() {
    sem_init(&s, 0, 1); // Initialize semaphore variable

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared); // Print the last updated value of the shared variable

    return 0;
}

void *fun1(void *arg) {
    int x;
    sem_wait(&s); // Execute wait operation on semaphore
    x = shared; // Thread 1 reads the value of the shared variable
    printf("Thread1 reads the value as %d\n", x);
    x++; // Thread 1 increments its value
    printf("Local updation by Thread1: %d\n", x);
    sleep(1); // Thread 1 is preempted by thread 2
    shared = x; // Thread 1 updates the value of the shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    sem_post(&s); // Release the semaphore
}

void *fun2(void *arg) {
    int y;
    sem_wait(&s); // Execute wait operation on semaphore
    y = shared; // Thread 2 reads the value of the shared variable
    printf("Thread2 reads the value as %d\n", y);
    y--; // Thread 2 decrements its value
    printf("Local updation by Thread2: %d\n", y);
    sleep(1); // Thread 2 is preempted by thread 1
    shared = y; // Thread 2 updates the value of the shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    sem_post(&s); // Release the semaphore
}
