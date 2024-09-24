#include<stdio.h>

struct Process
{
    int num; // process number
    int arrival; // process arrival time
    int burst; // process burst time
    int remaining; // remaining time for the process to complete
    int completion; // process completion time
    int turnaround; // turnaround time
    int waiting; // waiting time
    int response; // response time
    int start; // when process first starts
    int isStarted; // flag to check if process has started
};

// Function to calculate times using Round Robin Scheduling
void timeCalculation(struct Process process1[], int size, int quantum)
{
    int time = 0; // system time
    int completed = 0; // number of processes completed
    int isCompleted[size]; // array to track completed processes
    for (int i = 0; i < size; i++) {
        isCompleted[i] = 0;
        process1[i].remaining = process1[i].burst; // initialize remaining time with burst time
        process1[i].isStarted = 0;
    }

    while (completed < size) {
        int executed = 0; // to track if any process is executed in this cycle

        for (int i = 0; i < size; i++) {
            if (process1[i].arrival <= time && isCompleted[i] == 0) { // check if process has arrived and is not completed
                executed = 1;
                if (!process1[i].isStarted) {
                    process1[i].start = time; // start time of the process
                    process1[i].response = process1[i].start - process1[i].arrival; // response time
                    process1[i].isStarted = 1;
                }

                if (process1[i].remaining > quantum) {
                    time += quantum;
                    process1[i].remaining -= quantum;
                } else {
                    time += process1[i].remaining;
                    process1[i].remaining = 0;
                    process1[i].completion = time;
                    process1[i].turnaround = process1[i].completion - process1[i].arrival;
                    process1[i].waiting = process1[i].turnaround - process1[i].burst;
                    isCompleted[i] = 1; // mark process as completed
                    completed++;
                }
            }
        }

        if (executed == 0) { // no process to execute, so increment time
            time++;
        }
    }
}

// Function to print results
void printRes(struct Process process1[], int size)
{
    printf("P#\tCompl\tTAT\tWT\tResp\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", process1[i].num, process1[i].completion, process1[i].turnaround, process1[i].waiting, process1[i].response);
    }
}

int main()
{
    struct Process processes[] = {
        {1, 0, 3},  // Process 1 arrives at time 0, burst 3
        {2, 2, 5},  // Process 2 arrives at time 2, burst 5
        {3, 1, 4},  // Process 3 arrives at time 1, burst 4
        {4, 4, 2},  // Process 4 arrives at time 4, burst 2
        {5, 6, 9},  // Process 5 arrives at time 6, burst 9
        {6, 5, 4},  // Process 6 arrives at time 5, burst 4
        {7, 7, 10}  // Process 7 arrives at time 7, burst 10
    };

    int sz = sizeof(processes) / sizeof(processes[0]);
    int quantum = 3; // Time Quantum

    timeCalculation(processes, sz, quantum);

    printRes(processes, sz);

    return 0;
}
