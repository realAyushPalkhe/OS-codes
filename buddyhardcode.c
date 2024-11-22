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
    // Hardcoded memory block size and process operations
    int memoryBlock = 1024;  // Memory block size is 1024 (must be power of 2)
    int processSizes[] = {300, 120, 50, 180};  // Process sizes to allocate
    int removeProcesses[] = {180, 120};       // Process sizes to deallocate
    int numAllocations = sizeof(processSizes) / sizeof(processSizes[0]);
    int numDeallocations = sizeof(removeProcesses) / sizeof(removeProcesses[0]);

    printf("Memory Block Size: %d\n", memoryBlock);

    // Validate memory block size
    if (!isPowerOf2(memoryBlock)) {
        printf("Error: Memory block size must be a power of 2.\n");
        return 1;
    }

    Block *root = createBlock(memoryBlock);

    // Allocate memory for processes
    for (int i = 0; i < numAllocations; i++) {
        int processSize = nextPowerOf2(processSizes[i]);
        printf("\nAllocating process of size %d (rounded to %d):\n", processSizes[i], processSize);
        if (allocate(root, processSize)) {
            printf("Process successfully allocated.\n");
        } else {
            printf("Failed to allocate memory for process.\n");
        }
    }

    // Deallocate memory for processes
    for (int i = 0; i < numDeallocations; i++) {
        int processSize = nextPowerOf2(removeProcesses[i]);
        printf("\nDeallocating process of size %d (rounded to %d):\n", removeProcesses[i], processSize);
        if (deallocate(root, processSize)) {
            printf("Process successfully removed.\n");
        } else {
            printf("Failed to remove process.\n");
        }
    }

    // Display memory map
    printf("\nMemory Allocation Map:\n");
    displayMemoryMap(root);

    return 0;
}
