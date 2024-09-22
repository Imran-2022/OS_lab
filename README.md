### OS Scheduling and Memory Management Algorithms

### Table of Contents

| Category              | Algorithm                                   |
|----------------------|---------------------------------------------|
| Process Scheduling    | 1. FCFS (First-Come, First-Served)        |
|                      | 2. Shortest Job First (SJF)                |
|                      | 3. Round Robin (RR)                         |
|                      | 4. Priority Scheduling                      |
| Memory Management     | 1. First Fit                               |
|                      | 2. Next Fit                                |
|                      | 3. Best Fit                                |
|                      | 4. Worst Fit                               |
|                      | 5. Page Replacement                         |
|                      | └─ 1. FIFO (First-In, First-Out)          |
|                      | └─ 2. Optimal                              |


### Process Scheduling

#### 1. FCFS (First-Come, First-Served)
FCFS is the simplest scheduling algorithm that schedules processes in the order of their arrival. It uses a FIFO queue, meaning that the first process to arrive is the first to be executed.

#### 2. Shortest Job First (SJF)
SJF schedules processes based on the shortest execution time. It can minimize waiting time for short processes but may lead to starvation for longer processes.

#### 3. Round Robin (RR)
Round Robin allocates a fixed time quantum to each process in the ready queue. After the time quantum expires, the process is placed at the end of the queue, allowing other processes to execute.

#### 4. Priority Scheduling
Priority scheduling assigns a priority level to each process. The CPU is allocated to the process with the highest priority. Starvation can occur if lower priority processes are always waiting.

### Memory Management

#### 1. First Fit
First Fit allocates the first block of memory that is large enough to satisfy the request. This approach is fast but can lead to fragmentation.

#### 2. Next Fit
Next Fit is similar to First Fit, but it starts searching from the last allocated block rather than from the beginning of the memory.

#### 3. Best Fit
Best Fit searches the entire list of free memory blocks and allocates the smallest block that fits the request. This can reduce fragmentation but may take longer to find a suitable block.

#### 4. Worst Fit
Worst Fit allocates the largest available memory block to the request. The idea is to leave large enough blocks available for future requests.

#### 5. Page Replacement
Page replacement algorithms are used when a page must be removed from memory to make space for a new page.

##### 1. FIFO (First-In, First-Out)
FIFO replaces the oldest page in memory, similar to a queue structure.

##### 2. Optimal
The Optimal page replacement algorithm replaces the page that will not be used for the longest period in the future, minimizing page faults.

