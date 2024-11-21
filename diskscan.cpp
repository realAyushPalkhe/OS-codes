#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define DISK_SIZE 200

void SCAN(int arr[], int head, int direction) { // direction: 0 for left, 1 for right
    int seek_count = 0;
    int distance, cur_track;
    int left[SIZE + 1], right[SIZE + 1];
    int seek_sequence[SIZE + 2];
    int seek_times[SIZE + 2]; // Array to store seek times
    int left_count = 0, right_count = 0;
    int seek_index = 0;

    // Append end values to left and right arrays based on the direction
    if (direction == 0) {  // left
        left[left_count++] = 0;
    } else if (direction == 1) {  // right
        right[right_count++] = DISK_SIZE - 1;
    }

    // Split requests into left and right arrays based on head position
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head) {
            left[left_count++] = arr[i];
        } else if (arr[i] > head) {
            right[right_count++] = arr[i];
        }
    }

    // Sort left and right arrays
    for (int i = 0; i < left_count - 1; i++) {
        for (int j = i + 1; j < left_count; j++) {
            if (left[i] > left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    for (int i = 0; i < right_count - 1; i++) {
        for (int j = i + 1; j < right_count; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    // Run two passes of SCAN
    int run = 2;
    while (run--) {
        if (direction == 0) {  // moving left
            for (int i = left_count - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence[seek_index] = cur_track;
                distance = abs(cur_track - head);
                seek_times[seek_index++] = distance;
                seek_count += distance;
                head = cur_track;
            }
            direction = 1;  // switch direction to right
        } else if (direction == 1) {  // moving right
            for (int i = 0; i < right_count; i++) {
                cur_track = right[i];
                seek_sequence[seek_index] = cur_track;
                distance = abs(cur_track - head);
                seek_times[seek_index++] = distance;
                seek_count += distance;
                head = cur_track;
            }
            direction = 0;  // switch direction to left
        }
    }

    // Output the total seek operations
    printf("\nTotal number of seek operations = %d\n", seek_count);

    // Calculate and print the average seek time
    float average_seek_time = (float)seek_count / seek_index;
    printf("Average seek time = %.2f\n", average_seek_time);

    // Gantt Chart in Table Format
    printf("\nGantt Chart (Table Format):\n");
    printf("+----------------+-----------------+-----------------+\n");
    printf("| Disk Position  | Previous Head   | Seek Time       |\n");
    printf("+----------------+-----------------+-----------------+\n");
    for (int i = 0; i < seek_index; i++) {
        printf("| %-14d | %-15d | %-15d |\n", seek_sequence[i], 
               (i == 0 ? head : seek_sequence[i - 1]), seek_times[i]);
    }
    printf("+----------------+-----------------+-----------------+\n");
}

int main() {
    int arr[SIZE] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int direction = 1; // 0 for left, 1 for right

    SCAN(arr, head, direction);

    return 0;
}
