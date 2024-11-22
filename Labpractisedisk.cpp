
//---------------------FCFS------------------------------------------------
/*
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
*/
//----------------------------SSRTF----------------------------------------------------
/*
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
*/
//----------------------SCAN-------------------------------------------------
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // Include string.h for strcmp

// Comparator function for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void scan(int requests[], int n, int initial_position, int total_tracks, const char* direction) {
    int seek_count = 0;
    int distance, current_track;
    int left[100], right[100];
    int left_size = 0, right_size = 0;
    int seek_sequence[100];
    int sequence_index = 0;

    // Append end values to left or right based on the direction
    if (direction[0] == 'l') {
        left[left_size++] = 0; // If moving left, start from 0
    } else {
        right[right_size++] = total_tracks - 1; // If moving right, go to the end
    }

    // Split requests into left and right arrays
    for (int i = 0; i < n; i++) {
        if (requests[i] < initial_position) {
            left[left_size++] = requests[i];
        } else {
            right[right_size++] = requests[i];
        }
    }

    // Sort the left and right arrays
    qsort(left, left_size, sizeof(int), cmp);
    qsort(right, right_size, sizeof(int), cmp);

    // Print the scan scheduling details
    printf("\nSCAN Disk Scheduling:\n");
    int run = 2;
    while (run--) {
        if (direction[0] == 'l') {
            for (int i = left_size - 1; i >= 0; i--) {
                current_track = left[i];
                seek_sequence[sequence_index++] = current_track;
                distance = abs(current_track - initial_position);
                seek_count += distance;
                printf("%d - %d --> %d\n", initial_position, current_track, distance);
                initial_position = current_track;
            }
            direction = "right";
        } else {
            for (int i = 0; i < right_size; i++) {
                current_track = right[i];
                seek_sequence[sequence_index++] = current_track;
                distance = abs(current_track - initial_position);
                seek_count += distance;
                printf("%d - %d --> %d\n", initial_position, current_track, distance);
                initial_position = current_track;
            }
            direction = "left";
        }
    }

    // Output the seek sequence and total seek time
    printf("Seek Sequence: ");
    for (int i = 0; i < sequence_index; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\nTotal Seek Time: %d\n", seek_count);
    printf("Average Seek Time: %.2f\n", (float)seek_count / n);
}

// Driver code
int main() {
    int n, initial_position, total_tracks;

    printf("Enter the total number of tracks: ");
    scanf("%d", &total_tracks);

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[100];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial disk head position: ");
    scanf("%d", &initial_position);

    // Validate initial position
    if (initial_position < 0 || initial_position >= total_tracks) {
        printf("Invalid initial position!\n");
        return 1;
    }

    char direction[10];
    printf("Enter the direction of movement (left or right): ");
    scanf("%s", direction);

    // Validate direction
    if (strcmp(direction, "left") != 0 && strcmp(direction, "right") != 0) {
        printf("Invalid direction! Please enter 'left' or 'right'.\n");
        return 1;
    }

    scan(requests, n, initial_position, total_tracks, direction);
    return 0;
}
*/
//--------------------------C-SCAN-----------------------------
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void cscan(int requests[], int n, int initial_position, int total_tracks) {
    int seek_count = 0;
    int distance, current_track;
    int left[100], right[100];
    int left_size = 0, right_size = 0;
    int seek_sequence[100];
    int sequence_index = 0;

    // Append end values to left and right based on the current head position
    left[left_size++] = 0; // Start from 0
    right[right_size++] = total_tracks - 1; // End at the last track

    // Split requests into left and right arrays
    for (int i = 0; i < n; i++) {
        if (requests[i] < initial_position) {
            left[left_size++] = requests[i];
        } else {
            right[right_size++] = requests[i];
        }
    }

    // Sort the left and right arrays
    qsort(left, left_size, sizeof(int), cmp);
    qsort(right, right_size, sizeof(int), cmp);

    printf("\nC-SCAN Disk Scheduling:\n");

    // Serve all requests to the right
    for (int i = 0; i < right_size; i++) {
        current_track = right[i];
        seek_sequence[sequence_index++] = current_track;
        distance = abs(current_track - initial_position);
        seek_count += distance;
        printf("%d - %d --> %d\n", initial_position, current_track, distance);
        initial_position = current_track;
    }

    // Jump to the beginning of the disk
    if (initial_position != total_tracks - 1) {
        distance = abs((total_tracks - 1) - initial_position);
        seek_count += distance;
        printf("%d - %d --> %d\n", initial_position, total_tracks - 1, distance);
        initial_position = 0; // Jump to the start
    }

    // Serve all requests to the left
    for (int i = 0; i < left_size; i++) {
        current_track = left[i];
        seek_sequence[sequence_index++] = current_track;
        distance = abs(current_track - initial_position);
        seek_count += distance;
        printf("%d - %d --> %d\n", initial_position, current_track, distance);
        initial_position = current_track;
    }

    // Output the seek sequence and total seek time
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence: ");
    for (int i = 0; i < sequence_index; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\nAverage Seek Time: %.2f\n", (float)seek_count / n);
}

// Driver code
int main() {
    int n, initial_position, total_tracks;

    printf("Enter the total number of tracks: ");
    scanf("%d", &total_tracks);

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[100];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial disk head position: ");
    scanf("%d", &initial_position);

    // Validate initial position
    if (initial_position < 0 || initial_position >= total_tracks) {
        printf("Invalid initial position!\n");
        return 1;
    }

    cscan(requests, n, initial_position, total_tracks);
    return 0;
}
*/
