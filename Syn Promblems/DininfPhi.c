#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];
pthread_t philosophers[N];

typedef struct {
    int id; // Philosopher ID
} philosopher_arg_t;

void *philosopher(void *arg) {
    philosopher_arg_t *philosopher_arg = (philosopher_arg_t *)arg;
    int id = philosopher_arg->id; // Get the philosopher ID from the argument

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        usleep(500000); // Simulate thinking time

        sem_wait(&forks[id]); // Pick up left fork
        sem_wait(&forks[(id + 1) % N]); // Pick up right fork

        printf("Philosopher %d is eating.\n", id);
        usleep(500000); // Simulate eating time

        sem_post(&forks[id]); // Put down left fork
        sem_post(&forks[(id + 1) % N]); // Put down right fork
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1); // Initialize the semaphores for the forks
    }

    philosopher_arg_t args[N]; // Array to hold philosopher arguments

    for (int i = 0; i < N; i++) {
        args[i].id = i; // Set the philosopher ID
        pthread_create(&philosophers[i], NULL, philosopher, (void *)&args[i]); // Create philosopher threads
    }

    getchar(); // Wait for user input to exit

    for (int i = 0; i < N; i++) {
        sem_destroy(&forks[i]); // Clean up semaphores
    }

    return 0;
}
