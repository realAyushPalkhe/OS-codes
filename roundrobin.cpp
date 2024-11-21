#include <stdio.h>

void findAvgTimeRoundRobin(int processes[], int n, int bt[], int at[], int quantum) {
    int wt[n], tat[n], remaining_time[n];
    int total_wt = 0, total_tat = 0;

    // Initialize remaining time and waiting time
    for (int i = 0; i < n; i++) {
        remaining_time[i] = bt[i]; // Copy burst time to remaining time
        wt[i] = 0; // Initialize waiting time
    }

    int t = 0; // Current time
    int completed = 0; // Count of completed processes

    // Process execution loop
    while (completed < n) {
        int found = 0; // Flag to check if any process is found

        for (int i = 0; i < n; i++) {
            // If process is arrived and has remaining time
            if (remaining_time[i] > 0 && at[i] <= t) {
                found = 1; // A process is found

                if (remaining_time[i] > quantum) {
                    // Process is not finished
                    t += quantum; // Increase time by quantum
                    remaining_time[i] -= quantum; // Decrease remaining time
                } else {
                    // Process is finished
                    t += remaining_time[i]; // Increase time by remaining time
                    wt[i] = t - at[i] - bt[i]; // Calculate waiting time
                    remaining_time[i] = 0; // Mark process as completed
                    completed++; // Increase completed process count
                }
            }
        }

        if (!found) {
            t++; // If no process is found, increase time
        }
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Print results
    printf("Processes   Burst time   Arrival time   Waiting time   Turn around time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn around time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Process IDs starting from 1
    }

    printf("Enter arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time for Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findAvgTimeRoundRobin(processes, n, burst_time, arrival_time, quantum);

    return 0;
}
