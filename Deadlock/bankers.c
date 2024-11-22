#include <stdio.h>
#include <stdbool.h>
#define MAXIMUM 10

int allocation[MAXIMUM][MAXIMUM], available[MAXIMUM], max[MAXIMUM][MAXIMUM], need[MAXIMUM][MAXIMUM], numProcesses, numResources;

void printMatrices() {
    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for (int i = 0; i < numResources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

void bankers(){
    int safeSequence[numProcesses];
    bool finished[numProcesses];
    
    for (int i = 0; i < numProcesses; i++) {
        finished[i] = false;
    }

    // Generate need matrix
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printMatrices();

    int count = 0; // Count of processes in the safe sequence

    while (count < numProcesses) {
        bool found = false;

        for (int i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                bool canAllocate = true;

                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < numResources; j++) {
                        available[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finished[i] = true;
                    found = true;
                    printMatrices();
                }
            }
        }

        if (!found) {
            printf("System is in an unsafe state.\n");
            return;
        }
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
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

    printf("Enter maximum matrix: \n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources: \n");
    for (int i = 0; i < numResources; i++) {
        scanf("%d", &available[i]);
    }
}

int main(){
    input();

    bankers();

    return 0;
}
