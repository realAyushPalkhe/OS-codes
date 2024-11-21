#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int is_completed;
};

void calculateTimes(struct Process p[], int n) {
    int completed = 0, current_time = 0;

    while (completed < n) {
        int min_index = -1, min_priority = 9999;
        
        // Find the process with the highest priority (lowest number)
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !p[i].is_completed && p[i].priority < min_priority) {
                min_priority = p[i].priority;
                min_index = i;
            }
        }

        if (min_index == -1) {
            // No process is ready to run, increment time
            current_time++;
        } else {
            // Execute the selected process
            current_time += p[min_index].burst_time; // Increment current time by burst time
            p[min_index].completion_time = current_time;
            p[min_index].turnaround_time = p[min_index].completion_time - p[min_index].arrival_time;
            p[min_index].waiting_time = p[min_index].turnaround_time - p[min_index].burst_time;
            p[min_index].is_completed = 1;
            completed++;
        }
    }
}

void displayChart(struct Process p[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
            p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority,
            p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
}

void displayGanttChart(struct Process p[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) printf("------");
    printf("\n|");
    for (int i = 0; i < n; i++) printf(" P%d |", p[i].pid);
    printf("\n");
    for (int i = 0; i < n; i++) printf("------");
    printf("\n0");
    for (int i = 0; i < n; i++) printf("    %d", p[i].completion_time);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time, burst time, and priority for Process P%d: ", p[i].pid);
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].is_completed = 0;
    }

    calculateTimes(p, n);
    displayChart(p, n);
    displayGanttChart(p, n);

    return 0;
}