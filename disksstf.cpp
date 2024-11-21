#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], path[100], seek_times[100];
    int i, n, TotalHeadMoment = 0, initial, count = 0;

    printf("Enter the number of Requests\n");
    scanf("%d", &n);

    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position\n");
    scanf("%d", &initial);

    // SSTF logic to find the shortest distance first
    while (count != n) {
        int min = 1000, d, index;
        for (i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if (min > d) {
                min = d;
                index = i;
            }
        }

        // Update total head movement and seek times
        TotalHeadMoment += min;
        path[count] = RQ[index];  // Store the selected request in the path array
        seek_times[count] = min; // Store the seek time for this request
        initial = RQ[index];
        RQ[index] = 1000;  // Mark this request as completed
        count++;
    }

    // Output the path for SSTF
    printf("\nPath for SSTF: ");
    for (i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }

    // Output total head movement
    printf("\nTotal head movement is %d\n", TotalHeadMoment);

    // Calculate and print the average seek time
    float average_seek_time = (float)TotalHeadMoment / n;
    printf("Average seek time = %.2f\n", average_seek_time);

    // Gantt Chart in Table Format
    printf("\nGantt Chart (Table Format):\n");
    printf("+----------------+-----------------+-----------------+\n");
    printf("| Disk Position  | Previous Head   | Seek Time       |\n");
    printf("+----------------+-----------------+-----------------+\n");
    for (i = 0; i < n; i++) {
        printf("| %-14d | %-15d | %-15d |\n", path[i], (i == 0 ? initial : path[i - 1]), seek_times[i]);
    }
    printf("+----------------+-----------------+-----------------+\n");

    return 0;
}
