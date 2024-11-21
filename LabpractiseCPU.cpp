/*#include <stdio.h>
#include <stdlib.h>

// Priority Preemptive Scheduling
void PriorityPre(int n, int Arrival[], int burst[], int priority[]) {
    int completionT[n], remaining[n], waiting[n], turnaroundtime[n], processed[n];
    int current_time = 0, selected, completed = 0, tat = 0, twt = 0;

    for (int i = 0; i < n; i++) {
        processed[i] = 0;
        remaining[i] = burst[i];
    }

    while (completed < n) {
        int highestpriority = 99;
        selected = -1;

        // Select process with highest priority (lowest priority number)
        for (int i = 0; i < n; i++) {
            if (Arrival[i] <= current_time && remaining[i] > 0 && priority[i] < highestpriority) {
                highestpriority = priority[i];
                selected = i;
            }
        }

        if (selected == -1) {
            current_time++;
        } else {
            remaining[selected]--;
            current_time++;

            if (remaining[selected] == 0) {
                completionT[selected] = current_time;
                turnaroundtime[selected] = completionT[selected] - Arrival[selected];
                waiting[selected] = turnaroundtime[selected] - burst[selected];
                completed++;
                processed[selected] = 1;
            }
        }
    }

    printf("Processes   Burst time   Arrival time   Priority   Waiting time   Turn around time\n");
    for (int i = 0; i < n; i++) {
        twt += waiting[i];
        tat += turnaroundtime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst[i], Arrival[i], priority[i], waiting[i], turnaroundtime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)twt / n);
    printf("Average Turnaround Time: %.2f\n", (float)tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n], priority[n];

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

    printf("Enter priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Priority for Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    PriorityPre(n, arrival_time, burst_time, priority);

    return 0;
}
*/
/*
#include<stdio.h>
#include<stdio.h>

void PriorityNonpre(int Process[],int arrival[],int burst[],int priority[],int n)
{
    int remainingT[n],currentT=0,completed=0,Total_waiting=0,Total_TaT=0,selected,processed[n],waitingT[n],CT[n],tat[n],wt[n];

    for(int i=0;i<n;i++)
    {
        remainingT[i]=burst[i];
        processed[i]=0;
    }

    while(completed<n)
    {
        int highestP=999;
        selected=-1;

        for(int i=0;i<n;i++)
        {
            if(arrival[i]<= currentT && remainingT[i]>0 && priority[i]<highestP)
            {
                highestP=priority[i];
                selected=i;

            }
        }
        if(selected==-1)
        currentT++;
        else
        {
            currentT+=burst[selected];
            CT[selected]=currentT;
            tat[selected]=CT[selected]-arrival[selected];
            wt[selected]=tat[selected]-burst[selected];
            processed[selected]=1;
            completed++;

            
        }
    }
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n], priority[n];
for(int i=0;i<n;i++)
{
    processes[i]=i+1;
}
    for(int i=0;i<n;i++)
    {
        printf("The arrival time for %d",i);
        scanf("%d",&arrival_time[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("The Burst time for %d",i);
        scanf("%d",&burst_time[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("The Priority time for %d",i);
        scanf("%d",&priority[i]);
    }

    PriorityNonpre(processes,arrival_time,burst_time,priority,n);

}
*/
/*
#include<stdio.h>
#include<stdlib.h>

void SJFpre(int process[],int n,int arrial[],int burst[])
{
    int remainT[n],completionT[n],wt[n],tt[n],Tat=0,Twt=0,completed=0,min_index,processes[n],currentT=0;

    for(int i=0;i<n;i++)
    {
        remainT[i]=burst[i];
        processes[i]=0;
    }

    while(completed<n)
    {
        int min=999;
        min_index=-1;
        for(int i=0;i<n;i++)
        {
            if(arrial[i]<=currentT && remainT[i]>0 && min>remainT[i])
            {
                min=remainT[i];
                min_index=i;
            }
        }
        if(min_index==-1)
        currentT++;
        else{
            remainT[min_index]--;
            currentT++;

            if(remainT[min_index]==0)
            {
                completionT[min_index]=currentT;
                tt[min_index]=completionT[min_index]-arrial[min_index];
                wt[min_index]=tt[min_index]-burst[min_index];
                completed++;
                processes[min_index]=1;
            }
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("p%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\t\t \n ",process[i],arrial[i],burst[i],completionT[i],tt[i],wt[i]);
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>

void SJFnonpre(int process[],int n,int arrival[],int burst[])
{
    int remainT[n],currentT=0,completionT[n],wt[n],tt[n],Tat=0,Twt=0,completed;

    for(int i=0;i<n;i++)
    {
        remainT[i]=burst[i];

    }

    while(completed < n)
    {
        int min=999;
        int min_index=-1;

        for(int i=0;i<n;i++)
        {
           if(arrival[i]<=currentT && remainT[i]>0 && min>remainT[i])
           {
            min=remainT[i];
            min_index=i;

           }

        }
        if(min_index==-1)
        currentT++;
        else{
            currentT+=remainT[min_index];
            completionT[min_index]=currentT;
            tt[min_index]=completionT[min_index]-arrival[min_index];
            wt[min_index]=tt[min_index]-burst[min_index];
            completed++;

        }
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>

void FCFS(int process[],int n,int arrival[],int burst[])
{
    int remainT[n],completionT[n],completed=0,wt[n],tt[n],Ttat=0,Twt=0,currentT=0;


    for(int i=0;i<n;i++)
    remainT[i]=burst[i];

    for(int i=0;i<n;i++)
    {
        if(arrival[i]<=currentT && remainT[i]>0)
        {
            currentT+=remainT[i];
            completionT[i]=currentT;
        }
        tt[i]=completionT[i]-arrival[i];
        wt[i]=tt[i]-burst[i];
    }
    // Print results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               process[i], arrival[i], burst[i], completionT[i], tt[i], wt[i]);
    }

    for(int i=0;i<n;i++)
    {
        Ttat+=tt[i];
        Twt+=wt[i];
    }
    // Print averages
    printf("\nAverage Turnaround Time: %.2f\n", (float)Ttat / n);
    printf("Average Waiting Time: %.2f\n", (float)Twt / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], arrival[n], burst[n];
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    FCFS(process, n, arrival, burst);

    return 0;
*/#include <stdio.h>

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
