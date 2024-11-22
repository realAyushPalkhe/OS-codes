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
    return pow(2, ceil(log(n) / log(2)));
}

// Function to allocate memory using the Buddy System
int allocate(Block *block, int size) {
    if (!block->isFree || block->size < size) {
        return 0; // No space to allocate
    }

    // If block size exactly matches the requested size
    if (block->size == size) {
        block->isFree = 0;
        return 1;
    }

    // If block size is larger, split it
    if (!block->left && !block->right) {
        block->left = createBlock(block->size / 2);
        block->right = createBlock(block->size / 2);
    }

    // Try allocating in the left or right buddy
    if (allocate(block->left, size)) {
        return 1;
    }
    return allocate(block->right, size);
}

// Function to remove the process from memory (deallocate)
int deallocate(Block *block, int size) {
    if (block->size == size && !block->isFree) {
        block->isFree = 1;
        return 1;
    }

    if (block->left && deallocate(block->left, size)) {
        return 1;
    }

    if (block->right && deallocate(block->right, size)) {
        return 1;
    }

    return 0;
}

// Function to display memory map (Buddy System)
void displayMemoryMap(Block *block) {
    if (!block) {
        return;
    }

    if (block->isFree) {
        printf("%d --> Free\n", block->size);
    } else {
        printf("%d --> Allocated\n", block->size);
    }

    displayMemoryMap(block->left);
    displayMemoryMap(block->right);
}

// Main function
int main() {
    int memoryBlock, choice, processSize;
    printf("Enter Memory Block Size: ");
    scanf("%d", &memoryBlock);

    // Check if memory block size is a power of 2
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
