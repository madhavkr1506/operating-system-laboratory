#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

int sharedData = 0; // Shared data
int readersCount = 0; // Count of active readers
sem_t mutex; // Controls access to sharedData
sem_t writeMutex; // Controls access for writers

void* reader(void* arg);
void* writer(void* arg);

int main() {
    sem_init(&mutex, 0, 1);      // Initialize mutex semaphore
    sem_init(&writeMutex, 0, 1); // Initialize writeMutex semaphore

    pthread_t readerThreads[NUM_READERS];
    pthread_t writerThreads[NUM_WRITERS];

    // Create reader threads
    for (int i = 0; i < NUM_READERS; ++i) {
        pthread_create(&readerThreads[i], NULL, reader, NULL);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; ++i) {
        pthread_create(&writerThreads[i], NULL, writer, NULL);
    }

    // Join reader threads
    for (int i = 0; i < NUM_READERS; ++i) {
        pthread_join(readerThreads[i], NULL);
    }

    // Join writer threads
    for (int i = 0; i < NUM_WRITERS; ++i) {
        pthread_join(writerThreads[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&writeMutex);

    printf("Program terminated.\n");

    return 0;
}

void* reader(void* arg) {
    sem_wait(&mutex);
    readersCount++;
    if (readersCount == 1) {
        sem_wait(&writeMutex);
    }
    sem_post(&mutex);

    // Read the shared data
    printf("Reader reads: %d\n", sharedData);

    sem_wait(&mutex);
    readersCount--;
    if (readersCount == 0) {
        sem_post(&writeMutex);
    }
    sem_post(&mutex);

    // Sleep to simulate some processing
    usleep(100000);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    sem_wait(&writeMutex);

    // Write to the shared data
    sharedData++;
    printf("Writer writes: %d\n", sharedData);

    sem_post(&writeMutex);

    // Sleep to simulate some processing
    usleep(200000);

    pthread_exit(NULL);
}

