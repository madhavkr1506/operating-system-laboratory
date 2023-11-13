#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int shared = 1; // Shared variable
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for synchronization

void *fun1(void *arg);
void *fun2(void *arg);

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared);

    return 0;
}

void *fun1(void *arg) {
    int x;
    pthread_mutex_lock(&mutex); // Lock the mutex to protect the shared variable
    x = shared; // Thread one reads the value of the shared variable
    printf("Thread1 reads the value of shared variable as %d\n", x);
    x++; // Thread one increments its value
    printf("Local updation by Thread1: %d\n", x);
    sleep(1); // Thread one is preempted by thread 2
    shared = x; // Thread one updates the value of the shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    pthread_mutex_unlock(&mutex); // Unlock the mutex when done
}

void *fun2(void *arg) {
    int y;
    pthread_mutex_lock(&mutex); // Lock the mutex to protect the shared variable
    y = shared; // Thread two reads the value of the shared variable
    printf("Thread2 reads the value as %d\n", y);
    y--; // Thread two decrements its value
    printf("Local updation by Thread2: %d\n", y);
    sleep(1); // Thread two is preempted by thread 1
    shared = y; // Thread two updates the value of the shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    pthread_mutex_unlock(&mutex); // Unlock the mutex when done
}
