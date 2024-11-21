#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("\nEnter the number of disk requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the disk request positions: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int head;
    printf("\nEnter the current head position: ");
    scanf("%d", &head);

    int seek = 0;
    int seek_times[n]; // Array to store seek times for each movement

    // Calculate seek times
    seek_times[0] = abs(head - arr[0]);
    seek += seek_times[0];
    for (int i = 1; i < n; i++)
    {
        seek_times[i] = abs(arr[i] - arr[i - 1]);
        seek += seek_times[i];
    }

    // Calculate average seek time
    float average_seek_time = (float)seek / n;

    // Print head movement details
    printf("\nHead movement details:\n");
    printf("Head moved from %d to %d with seek time %d\n", head, arr[0], seek_times[0]);
    for (int i = 1; i < n; i++)
    {
        printf("Head moved from %d to %d with seek time %d\n", arr[i - 1], arr[i], seek_times[i]);
    }
    printf("\nTotal seek time = %d", seek);
    printf("\nAverage seek time = %.2f\n", average_seek_time);

    // Gantt Chart in Table Format
    printf("\nGantt Chart (Table Format):\n");
    printf("+----------------+-----------------+-----------------+\n");
    printf("| Disk Position  | Previous Head   | Seek Time       |\n");
    printf("+----------------+-----------------+-----------------+\n");
    printf("| %-14d | %-15d | %-15d |\n", arr[0], head, seek_times[0]);
    for (int i = 1; i < n; i++)
    {
        printf("| %-14d | %-15d | %-15d |\n", arr[i], arr[i - 1], seek_times[i]);
    }
    printf("+----------------+-----------------+-----------------+\n");

    return 0;
}
