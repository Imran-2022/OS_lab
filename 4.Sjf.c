#include<stdio.h>
#include <limits.h>

struct Process
{
    int num;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    int response;
};

void timeCalculation(struct Process process1[],int size)
{
    int time=0;
    int completion=0;
    int remaining[size];
    for(int i=0;i<size;i++)remaining[i]=process1[i].burst;

    while(completion<size)
    {
        int idx=-1;
        int highBurst=INT_MAX;
        for(int i=0;i<size;i++){
            if(process1[i].arrival <= time  && process1[i].burst<highBurst && remaining[i]!=0){
                idx=i;
                highBurst=process1[i].burst;
            }else{
                if(process1[i].arrival <= time && process1[i].burst==highBurst && process1[i].arrival<process1[idx].arrival){
                    idx=i;
                }
            }
        }
        if(idx!=-1){
            time +=process1[idx].burst;
            process1[idx].completion = time;
            process1[idx].turnaround=process1[idx].completion-process1[idx].arrival;
            process1[idx].waiting=process1[idx].turnaround-process1[idx].burst;
            process1[idx].response=process1[idx].waiting;

            completion++;
            remaining[idx]=0;
        }
        else {
            time++;
        }
    }
}


void printRes(struct Process process1[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("\t%d\t%d\t%d\t%d\n",process1[i].num,process1[i].completion,process1[i].turnaround,process1[i].waiting);
    }
}

int main()
{
    struct Process process1[] = {
        {1, 1, 3}, {2, 2, 4}, {3, 1, 2}, {4, 4, 4}
    };

    int size=sizeof(process1)/sizeof(process1[0]);
    timeCalculation(process1,size);
    printRes(process1,size);

    return 0;
}
