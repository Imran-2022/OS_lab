#include<stdio.h>
#include<limits.h>

struct Process
{
    int num; // process number
    int arrival; // process arrival time
    int burst; // process burst time.
    int priority; //priority of the process.
    int completion; // process completion time.
    int turnaround; // turnaround time
    int waiting; // waiting time.
    int response; //response time
    // in non-preemptive scheduling, the response time is often equal to the waiting time because the process does not get interrupted once it starts executing.
};

// sort the process1 accroding to arrival time first ...!

void sort(struct Process process1[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(process1[i].arrival>process1[j].arrival){
                struct Process temp=process1[j];
                process1[j]=process1[i];
                process1[i]=temp;
            }
        }
    }
}

void timeCalculation(struct Process process1[],int size)
{
    int time =0;
    int completed=0;
    int isCompleted[size];
    for(int i=0;i<size;i++)isCompleted[i]=0;

    for (int i=0;i<size;i++){
         int idx=-1;
        int highPriority =INT_MAX;

        for(int j=0;j<size;j++){
            if(process1[j].priority<highPriority && isCompleted[j]==0){
                idx=j;
                highPriority=process1[j].priority;
            }else if(process1[j].priority==highPriority && process1[j].arrival<process1[idx].arrival)
            {
                idx=j;
            }
        }
        if(idx!=-1)
        {

            //time = (time < process1[idx].arrival) ? process1[idx].arrival : time;
            time += process1[idx].burst;
            process1[idx].completion = time;
            process1[idx].turnaround= process1[idx].completion-process1[idx].arrival;
            process1[idx].waiting=process1[idx].turnaround-process1[idx].burst;
            process1[idx].response=process1[idx].waiting; // as we know , for non-preemptive , respose time equal to waiting time.
            isCompleted[idx]=-1;
            time=process1[idx].completion;
            isCompleted[idx] = 1; // Mark process as completed
            completed++;
        }else
        {
            time++;
        }
    }
}


void printRes(struct Process process1[],int size)
{
    for(int i=0;i<size;i++){
        printf("%d\t%d\t%d\t%d\t\n",process1[i].num,process1[i].completion,process1[i].turnaround,process1[i].waiting);
    }
}


int main()
{
    struct Process processes[] = {
        {1, 0, 3, 2},  // Process 1 arrives at time 0, burst 3, priority 2
        {2, 2, 5, 6},  // Process 2 arrives at time 1, burst 4, priority 1
        {3, 1, 4, 3},  // Process 3 arrives at time 2, burst 2, priority 3
        {4, 4, 2, 5},   // Process 4 arrives at time 3, burst 1, priority 4
        {5, 6, 9, 7},
        {6, 5, 4, 4},
        {7, 7, 10, 10}
    };

    int sz = sizeof(processes) / sizeof(processes[0]);

    //sort(processes,sz);

    timeCalculation(processes,sz);

    printRes(processes,sz);

    return 0;
}
