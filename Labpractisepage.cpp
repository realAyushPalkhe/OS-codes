/*

FIFO:
#include <stdio.h>
#include <stdbool.h>
bool is_page_in_memory(int frames[], int frame_count, int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}


void fifo_page_replacement(int pages[], int page_count, int frame_count) {
    int frames[frame_count]; 
    int front = 0;
    int page_faults = 0; 

    
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    printf("Page Reference\tFrames (After Insertion)\n");

    
    for (int i = 0; i < page_count; i++) {
        int page = pages[i];

        
        if (!is_page_in_memory(frames, frame_count, page)) {
            
            frames[front] = page; 
            front = (front + 1) % frame_count; 
            page_faults++; 
        }

        
        printf("%d\t\t", page);
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
 }

    printf("\nTotal Page Faults: %d\n", page_faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int page_count = sizeof(pages) / sizeof(pages[0]);
    int frame_count = 3; 

    printf("Pages: ");
    for (int i = 0; i < page_count; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n\n");

    fifo_page_replacement(pages, page_count, frame_count);

    return 0;
}
*/

/*
LRU:

#include<stdio.h>

int lru(int time[],int nf){
    int i,minimum=time[0],loc=0;
    for(i=0;i<nf;i++){
        if(time[i]<minimum){
            minimum=time[i];
            loc=i;
        }
    }
    return loc;
}

int main(){
    int nf,np,frames[10],pages[30],counter=0,time[10];
    int i,j,flag,faults=0,loc;
    printf("Enter number of frames: ");
    scanf("%d",&nf);
    printf("Enter the number of pages: ");
    scanf("%d",&np);
    printf("Enter reference string: ");
    for(i=0;i<np;i++){
        scanf("%d",&pages[i]);
    }
    for(i=0;i<nf;i++){
        frames[i]=-1;
    }
    for(i=0;i<np;i++){
        flag=0;
        for(j=0;j<nf;j++){
            if(frames[j]==pages[i]){
                counter++;
                time[j]=counter;
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(j=0;j<nf;j++){
                if(frames[j]==-1){
                    counter++;
                    faults++;
                    frames[j]=pages[i];
                    time[j]=counter;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            loc=lru(time,nf);
            counter++;
            faults++;
            frames[loc]=pages[i];
            time[loc]=counter;
        }
        printf("\nFrames after accessing page %d: ",pages[i]);
        for(j=0;j<nf;j++){
            if(frames[j]!=-1){
            printf("| %d ",frames[j]);
            }
            else{
                printf("|  ");
            }
        }
        printf("|  ");
        printf("\n--------------------------");
    }
    printf("\n Total page faults= %d",faults);
    return 0;
}
*/

/*
Optimal:
#include<stdio.h>
#include<stdlib.h>
int np,nf,pages[30],frames[10],faults=0;
int findOptimalPage(int page[],int frames[],int index,int nf){
    int farthest=-1;
    int farIndex=-1;
    for(int i=0;i<nf;i++){
        int j;
        for(j=index;j<np;j++){
            if(frames[i]==page[j]){
                if(j>farthest){
                    farthest=j;
                    farIndex=i;
                }
                break;
            }
        }
        if(j==np){
            return i;
        }
    }
    if(farIndex==-1){
        return 0;
    }
    return farIndex;
}

int main(){
    int flag,i,j;
    printf("Enter the number of frames:\n"); 
    scanf("%d",&nf);
    for(i=0;i<nf;i++){
        frames[i]=-1;
    }
    printf("Enter the number of pages:\n");
    scanf("%d",&np);
    printf("Enter the reference strings:\n");
    for(i=0;i<np;i++){
        scanf("%d",&pages[i]);
    }
    printf("\n");
    for(i=0;i<np;i++){
        flag=0;
        int page=pages[i];
        for(j=0;j<nf;j++){
            if(frames[j]==pages[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            int loc;
            for(j=0;j<nf;j++){
                if(frames[j]==-1){
                    loc=j;
                    break;
                }
            }
            if(j==nf){
                loc=findOptimalPage(pages,frames,i+1,nf);
            }
            frames[loc]=page;
            faults++;
        }
        
        printf("\nFrames after accessing page %d: ",pages[i]);
        for(j=0;j<nf;j++){
            if(frames[j]!=-1){
            printf("| %d ",frames[j]);
            }
            else{
                printf("|  ");
            }
        }
        printf("|  ");
        printf("\n--------------------------");
    }
    printf("\nTotal Page Faults: %d\n",faults);
    return 0;
}
*/