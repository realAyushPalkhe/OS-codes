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
