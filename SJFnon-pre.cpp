#include <stdio.h>
#include <limits.h>

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTimeSJFNonPreemptive(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int completed = 0, t = 0, bt_copy[n];

    // Copy burst times to a separate array
    for (int i = 0; i < n; i++) {
        bt_copy[i] = bt[i];
        wt[i] = 0;
    }

    // Store the order of process execution
    int order[n];
    int order_index = 0;

    while (completed < n) {
        int min_index = -1;
        int min_burst = INT_MAX;

        // Find the process with the minimum burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && bt_copy[i] > 0 && bt_copy[i] < min_burst) {
                min_burst = bt_copy[i];
                min_index = i;
            }
        }

        if (min_index != -1) {
            order[order_index++] = min_index; // Store the process index in the order array
            t += bt_copy[min_index];  // Increase time by the burst time of the selected process
            wt[min_index] = t - at[min_index] - bt[min_index];  // Calculate waiting time
            completed++;
            bt_copy[min_index] = 0;  // Mark this process as completed
        } else {
            t++;  // If no process is ready, just increase time
        }
    }

    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes   Burst time   Arrival time   Waiting time   Turn around time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn around time = %.2f\n", (float)total_tat / n);

    // Print Gantt chart
    printf("Gantt Chart:\n");
    printf("Time \n");
    for (int i = 0; i < n; i++) {
        printf("| P%d  ", order[i] + 1);
    }
    printf("\n");

    int time = 0;
    for (int i = 0; i < n; i++) {
        time += bt[order[i]];
        printf("     %d ", time);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
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

    findAvgTimeSJFNonPreemptive(processes, n, burst_time, arrival_time);

    return 0;
}