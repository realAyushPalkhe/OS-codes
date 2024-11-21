#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include<unistd.h>
sem_t rw_mutex;
sem_t mutex;
int read_count = 0;

void* reader(void* arg) {
    int f = *(int*)arg;
    while(1){
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&rw_mutex);
    sem_post(&mutex);

    printf("Reader %d is reading\n", f);
    usleep(500000);
    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
        sem_post(&rw_mutex);
    sem_post(&mutex);
    usleep(500000);
    }
    //return NULL;
}

void* writer(void* arg) {
    int f = *(int*)arg;
    while(1){
    sem_wait(&rw_mutex);

    printf("Writer %d is writing\n", f);
    usleep(500000);
    sem_post(&rw_mutex);
    usleep(500000);
    }
    //return NULL;
}

int main() {
    pthread_t r[5], w[5];
    int ids[5];

    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        ids[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &ids[i]);
        pthread_create(&w[i], NULL, writer, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}
