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
*/
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

struct P {
    int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

void displayGanttChart(int n, struct P p[]) {
    printf("\nGantt Chart:\n");

    // Print top border of Gantt chart
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (p[i].ST[j] != -1) {
            printf("--------");
            j++;
        }
    }
    printf("\n|");

    // Print process IDs in the Gantt chart
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (p[i].ST[j] != -1) {
            printf(" P%d |", p[i].pos);
            j++;
        }
    }
    printf("\n");

    // Print bottom border of Gantt chart
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (p[i].ST[j] != -1) {
            printf("--------");
            j++;
        }
    }
    printf("\n");

    // Print timeline below Gantt chart
    printf("0");
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (p[i].ST[j] != -1) {
            printf("       %d", p[i].ST[j] + quant <= p[i].FT ? p[i].ST[j] + quant : p[i].FT);
            j++;
        }
    }
    printf("\n");
}

int main() {
    int n, i, j;

    // Taking Input
    printf("Enter the no. of processes : ");
    scanf("%d", &n);
    struct P p[n];

    printf("Enter the quantum: ");
    scanf("%d", &quant);

    printf("Enter the process numbers:\n");
    for (i = 0; i < n; i++) scanf("%d", &(p[i].pos));

    printf("Enter the Arrival time of processes:\n");
    for (i = 0; i < n; i++) scanf("%d", &(p[i].AT));

    printf("Enter the Burst time of processes:\n");
    for (i = 0; i < n; i++) scanf("%d", &(p[i].BT));

    // Declaring variables
    int c = n, s[n][20];
    float time = 0, mini = INT_MAX, b[n], a[n];

    // Initializing burst and arrival time arrays
    int index = -1;
    for (i = 0; i < n; i++) {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for (j = 0; j < 20; j++) s[i][j] = -1;
    }

    int tot_wt = 0, tot_tat = 0;
    bool flag = false;

    // Main Round Robin scheduling loop
    while (c != 0) {
        mini = INT_MAX;
        flag = false;

        for (i = 0; i < n; i++) {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0) {
                index = i;
                mini = a[i];
                flag = true;
            }
        }

        if (!flag) {
            time++;
            continue;
        }

        j = 0;
        while (s[index][j] != -1) j++;

        if (s[index][j] == -1) {
            s[index][j] = time;
            p[index].ST[j] = time;
        }

        if (b[index] <= quant) {
            time += b[index];
            b[index] = 0;
        } else {
            time += quant;
            b[index] -= quant;
        }

        if (b[index] > 0) a[index] = time + 0.1;

        if (b[index] == 0) {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    }

    // Display Gantt Chart
    displayGanttChart(n, p);

    // Printing process table
    printf("\nProcess\tArrival Time\tBurst Time\tStart Times\t\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t", p[i].pos, p[i].AT, p[i].BT);

        j = 0;
        while (s[i][j] != -1) {
            printf("%d ", p[i].ST[j]);
            j++;
        }
        printf("\t\t%d\t\t%d\t\t%d\n", p[i].FT, p[i].WT, p[i].TAT);
    }

    // Calculating and printing average wait time and turnaround time
    double avg_wt = tot_wt / (double)n;
    double avg_tat = tot_tat / (double)n;
    printf("\nThe average waiting time is: %.2lf\n", avg_wt);
    printf("The average turnaround time is: %.2lf\n", avg_tat);

    return 0;
}
