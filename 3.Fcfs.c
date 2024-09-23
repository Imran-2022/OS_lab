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

void sort(struct Process process1[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(process1[i].arrival>process1[j].arrival)
            {
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
    for(int i=0;i<size;i++){
        if(time<process1[i].arrival)
        {
            time=process1[i].arrival;
        }
        time+=process1[i].burst;
        process1[i].completion = time;
        process1[i].turnaround=process1[i].completion-process1[i].arrival;
        process1[i].waiting=process1[i].turnaround-process1[i].burst;
        process1[i].response=process1[i].waiting;
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
        {1, 0, 2}, {2, 1, 2}, {3, 5, 3}, {4, 6, 4}
    };


    int size=sizeof(process1)/sizeof(process1[0]);
    sort(process1,size);
    timeCalculation(process1,size);
    printRes(process1,size);

    return 0;
}
