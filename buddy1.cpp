#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024  // Maximum block size

// Struct to hold memory block information
typedef struct Block {
    int size;
    int isFree;
    struct Block *left;
    struct Block *right;
} Block;

// Function to create a block of given size
Block* createBlock(int size) {
    Block *block = (Block *)malloc(sizeof(Block));
    block->size = size;
    block->isFree = 1;
    block->left = block->right = NULL;
    return block;
}

// Function to check if a number is a power of 2
int isPowerOf2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Function to find the nearest power of 2
int nextPowerOf2(int n) {
    if (n <= 0) return 1; // Handle edge case
    return (int)pow(2, ceil(log(n) / log(2)));
}

// Function to allocate memory using the Buddy System
int allocate(Block *block, int size) {
    if (block == NULL) {
        return 0; // Base case for recursion
    }

    // If the block is free and the size fits
    if (block->isFree && block->size >= size) {
        // If the block size is exactly the requested size
        if (block->size == size) {
            block->isFree = 0; // Mark as allocated
            return 1;
        }

        // If the block can be split
        if (!block->left && !block->right) {
            // Split the block into two
            block->left = createBlock(block->size / 2);
            block->right = createBlock(block->size / 2);
        }

        // Try to allocate in the left buddy
        if (allocate(block->left, size)) {
            return 1;
        }

        // If left allocation fails, try the right buddy
        return allocate(block->right, size);
    }

    return 0; // No allocation made
}

// Function to remove the process from memory (deallocate)
int deallocate(Block *block, int size) {
    if (block == NULL) {
        return 0; // Base case for recursion
    }

    if (block->size == size && !block->isFree) {
        block->isFree = 1; // Mark block as free
        return 1;
    }

    // Attempt to deallocate from left and right
    if (deallocate(block->left, size)) {
        return 1;
    }

    return deallocate(block->right, size);
}

// Function to display memory map (Buddy System)
void displayMemoryMap(Block *block) {
    if (!block) {
        return;
    }

    // Displaying block status
    printf("%d --> %s\n", block->size, block->isFree ? "Free" : "Allocated");

    displayMemoryMap(block->left);
    displayMemoryMap(block->right);
}

// Main function
int main() {
    int memoryBlock, choice, processSize;
    printf("Memory Block: ");
    scanf("%d", &memoryBlock);

    // Ensure the initial memory block is a power of 2
    if (!isPowerOf2(memoryBlock)) {
        printf("Error: Memory block size must be a power of 2.\n");
        return 1;
    }

    Block *root = createBlock(memoryBlock);

    while (1) {
        printf("\nEnter choice:\n1. Allocate memory for process\n2. Remove process from memory\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of process: ");
                scanf("%d", &processSize);
                processSize = nextPowerOf2(processSize);
                if (allocate(root, processSize)) {
                    printf("Process successfully allocated\n");
                } else {
                    printf("Failed to allocate memory\n");
                }
                break;

            case 2:
                printf("Enter the size of process to remove: ");
                scanf("%d", &processSize);
                processSize = nextPowerOf2(processSize);
                if (deallocate(root, processSize)) {
                    printf("Process successfully removed\n");
                } else {
                    printf("Failed to remove process\n");
                }
                break;

            case 3:
                printf("\nMemory Allocation Map:\n");
                displayMemoryMap(root);
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
