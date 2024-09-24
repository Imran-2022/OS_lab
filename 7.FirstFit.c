#include<stdio.h>


void firstFit(int blockSize[],int m,int processSize[],int n)
{

    int allocation[n];
	for(int i = 0; i < n; i++)allocation[i] = -1;

	for (int i = 0; i < n; i++)	 //here, n -> number of processes
	{
		for (int j = 0; j < m; j++)	 //here, m -> number of blocks
		{
			if (blockSize[j] >= processSize[i])
			{
				// allocating block j to the ith process
				allocation[i] = j;

				// Reduce available memory in this block.
				blockSize[j] -= processSize[i];

				break; //go to the next process in the queue
			}
		}
	}

    // Output the allocation table
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

int main()
{
    int blockSize[]={100,500,200,300,600};
    int processSize[]={212,417,112,426};
    int m=sizeof(blockSize)/sizeof(blockSize[0]);
    int n=sizeof(processSize)/sizeof(processSize[0]);
    firstFit(blockSize,m,processSize,n);
    return 0;
}
