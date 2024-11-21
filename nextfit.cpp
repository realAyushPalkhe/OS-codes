#include <stdio.h>

struct Process {
    int pid;
    int size;
    int allocated_block;
};

struct Block {
    int bid;
    int size;
    int original_size; // Added to store the original block size
};

void nextFit(struct Process processes[], int p_count, struct Block blocks[], int b_count) {
    int last_index = 0; // Tracks the last block where a process was allocated

    for (int i = 0; i < p_count; i++) {
        int allocated = 0; // To check if a block was allocated for this process

        for (int j = 0; j < b_count; j++) {
            int current_index = (last_index + j) % b_count; // Circularly iterate over blocks

            if (blocks[current_index].size >= processes[i].size) {
                // Allocate the process to the current block
                processes[i].allocated_block = blocks[current_index].bid;
                blocks[current_index].size -= processes[i].size;
                last_index = current_index + 1; // Update last allocated position to next block
                allocated = 1;
                break;
            }
        }

        if (!allocated) {
            processes[i].allocated_block = -1; // No suitable block found
        }
    }
}

void displayAllocation(struct Process processes[], int p_count, struct Block blocks[], int b_count) {
    printf("\nProcess\tSize\tAllocated Block\tOriginal Block Size\tRemaining Block Size\n");
    for (int i = 0; i < p_count; i++) {
        if (processes[i].allocated_block != -1) {
            int block_index = processes[i].allocated_block - 1; // Convert block ID to index
            printf("P%d\t%d\tBlock %d\t\t%d\t\t\t%d\n", 
                   processes[i].pid, 
                   processes[i].size, 
                   processes[i].allocated_block,
                   blocks[block_index].original_size, 
                   blocks[block_index].size);
        } else {
            printf("P%d\t%d\tNot Allocated\t\t-\t\t\t-\n", 
                   processes[i].pid, 
                   processes[i].size);
        }
    }
}

int main() {
    int p_count, b_count;

    printf("Enter the number of processes: ");
    scanf("%d", &p_count);
    struct Process processes[p_count];

    for (int i = 0; i < p_count; i++) {
        processes[i].pid = i + 1;
        printf("Enter size for Process P%d: ", processes[i].pid);
        scanf("%d", &processes[i].size);
        processes[i].allocated_block = -1; // Initialize as not allocated
    }

    printf("Enter the number of blocks: ");
    scanf("%d", &b_count);
    struct Block blocks[b_count];

    for (int i = 0; i < b_count; i++) {
        blocks[i].bid = i + 1;
        printf("Enter size for Block %d: ", blocks[i].bid);
        scanf("%d", &blocks[i].size);
        blocks[i].original_size = blocks[i].size; // Store the original size
    }

    nextFit(processes, p_count, blocks, b_count);
    displayAllocation(processes, p_count, blocks, b_count);

    return 0;
}