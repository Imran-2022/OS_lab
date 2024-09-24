
#include<stdio.h>
#define Frame_number 3


int Optimal(int pages[],int sz)
{
    int frames[sz];
    for(int i=0;i<sz;i++)frames[i]=-1;
    int page_fault=0;
    int victim=0;

    for(int i=0;i<sz;i++){
        int isFound=0;
        for(int ii=0;ii<Frame_number;ii++){
            if(frames[ii]==pages[i]){
                isFound=1;
                break;
            }
        }
        if(!isFound){
            int has_free_space=0;
            for(int iii=0;iii<Frame_number;iii++){
                if(frames[iii]==-1){
                    has_free_space=1;
                    frames[iii]=pages[i];
                    page_fault++;
                    break;
                }
            }
            if(!has_free_space){

               int nextUse[Frame_number];
               for(int j=0;j<Frame_number;j++){
                nextUse[j]=sz+1;
               }
               for(int j=0;j<Frame_number;j++){
                for(int jj=i+1;jj<sz;jj++){
                    if(pages[jj]==frames[j]){
                        nextUse[j]=jj;
                        break;
                    }
                }
               }
               int victim=0;

               for(int j=0;j<Frame_number;j++){
                if(nextUse[j]>nextUse[victim]){
                    victim=j;
                }
               }
               frames[victim]=pages[i];
               page_fault++;


            }
        }
    }
    return page_fault;
}


int main()
{

    int pages[]={6,7,8,9,6,7,1,6,7,8,9,1,7,9,6};
    int sz=sizeof(pages)/sizeof(pages[0]);
    printf("\n Number of page Fault = %d\n",Optimal(pages,sz));

    return 0;

}
