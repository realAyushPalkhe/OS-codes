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
