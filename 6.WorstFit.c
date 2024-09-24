#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    // Block allocations for processes
    int allocation[n];

    // Initially allocate -1 to all allocations to indicate that no block has been allocated
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Loop through each process to find the worst block (largest block) for each process
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                // If the block is larger than the current process and is the worst fit
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // If we found a block for this process
        if (worstIdx != -1) {
            // Allocate the block worstIdx to process i
            allocation[i] = worstIdx;

            // Reduce available memory in this block
            blockSize[worstIdx] -= processSize[i];
        }
    }

    // Now printing the allocation array in the desired format
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);  // Block numbers start from 1
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blockSize, m, processSize, n);

    return 0;
}

