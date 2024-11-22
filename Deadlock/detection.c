#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int allocation[MAX][MAX], request[MAX][MAX], avail[MAX], completed[MAX], numProcesses, numResources;

void printMatrices() {
    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nRequest Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", request[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for (int i = 0; i < numResources; i++) {
        printf("%d ", avail[i]);
    }
    printf("\n");
}

bool deadlock() {
    int finish[MAX], safeSequence[MAX], work[MAX], k = 0, found;

    for (int i = 0; i < numResources; i++) {
        work[i] = avail[i];
    }

    for (int i = 0; i < numProcesses; i++) {
        finish[i] = false;
    }

    printMatrices();

    for (int iterations = 0; iterations < numProcesses; iterations++) {
        found = 0;

        for (int i = 0; i < numProcesses; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < numResources; j++) {
                    if (request[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == numResources) {
                    printf("=========================\nProcess %d is being executed.\n", i + 1);

                    printf("Available resources before execution of Process %d: ", i + 1);
                    for (int y = 0; y < numResources; y++) {
                        printf("%d ", work[y]);
                    }
                    printf("\n");

                    for (int y = 0; y < numResources; y++) {
                        work[y] += allocation[i][y];
                    }

                    safeSequence[k++] = i;
                    finish[i] = 1;
                    found = 1;

                    printf("Resources after execution of Process %d:\n", i + 1);
                    printf("Allocation matrix:\n");
                    for (int x = 0; x < numProcesses; x++) {
                        for (int y = 0; y < numResources; y++) {
                            printf("%d ", allocation[x][y]);
                        }
                        printf("\n");
                    }

                    printf("Request matrix:\n");
                    for (int x = 0; x < numProcesses; x++) {
                        for (int y = 0; y < numResources; y++) {
                            printf("%d ", request[x][y]);
                        }
                        printf("\n");
                    }

                    printf("Available resources after execution: ");
                    for (int y = 0; y < numResources; y++) {
                        printf("%d ", work[y]);
                    }
                    printf("\n");
                }
            }
        }

        if (!found) {
            printf("\nNo more processes can execute in this iteration.\n");
            break;
        }
    }

    int deadlockDetected = 0;
    for (int i = 0; i < numProcesses; i++) {
        if (!finish[i]) {
            deadlockDetected = 1;
            printf("\nProcess %d could not be executed, it is waiting for resources.\n", i + 1);
        }
    }

    if (deadlockDetected) {
        return false;
    } 
    else {
        printf("\nAll processes finished executing, system is in a safe state.\n");
        return true; 
    }
}

void input() {
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    
    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    printf("Enter allocation matrix: \n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter request matrix: \n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter available resources: \n");
    for (int i = 0; i < numResources; i++) {
        scanf("%d", &avail[i]);
    }
}

int main() {
    input();
    
    if (deadlock()) {
        printf("\nSystem is in a safe state, no deadlock detected.\n");
    } 
    else {
        printf("\nDeadlock detected in the system.\n");
    }

    return 0;
}
