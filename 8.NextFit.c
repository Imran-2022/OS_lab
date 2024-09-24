#include <stdio.h>

void nextFit(int blockSize[], int m, int processSize[], int n) {
    // Block allocations for processes
    int allocation[n];

    // Initially allocate the index of -1 to all allocation blocks
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Pointer to keep track of where the last allocation was made
    int j = 0;

    // Fetching the process and allocating block
    for (int i = 0; i < n; i++) {
        int count = 0;  // Counter to keep track of how many blocks have been visited
        while (count < m) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;

                // Reduce available memory in this block.
                blockSize[j] -= processSize[i];

                // Move to the next block for future allocation
                break;
            }
            // Move to the next block (wrapping around using mod m)
            j = (j + 1) % m;
            count++;
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
    int processSize[] = {212, 417, 400, 100};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    nextFit(blockSize, m, processSize, n);

    return 0;
}
