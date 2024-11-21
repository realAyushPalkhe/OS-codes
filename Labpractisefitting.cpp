/*#include<stdio.h>
#include<stdio.h>

void firstfit(int blockSize[],int processSize[] ,int n)
{
    int allocation[5];
    for(int i=0;i<5;i++)
    {
        allocation[i]=0;

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(processSize[i]<=blockSize[j] && allocation[i]==0)
            {
                allocation[i]=j;
                blockSize[j]=blockSize[j]-processSize[i];
                break;
            }
            
        }
    }

    for(int i=0;i<n;i++)
    {
        if(allocation[i]!=0)
        printf("%d---%d\n",i+1,allocation[i]+1);
        else
        printf("%d not allocated",i+1);
    }
}

int main()
{
    int n=4;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    firstfit(blockSize,processSize,n);
}
*/
/*
#include<stdio.h>
#include<stdio.h>

void nextfit(int blockSize[],int processSize[] ,int n)
{
    int allocation[5];
    for(int i=0;i<5;i++)
    {
        allocation[i]=0;

    }

    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j<5)
        {
            if(processSize[i]<=blockSize[j] && allocation[i]==0)
            {
                allocation[i]=j;
                blockSize[j]=blockSize[j]-processSize[i];
                break;
            }
            j++;
            
        }
        j=j+1;
    }

    for(int i=0;i<n;i++)
    {
        if(allocation[i]!=0)
        printf("%d---%d\n",i+1,allocation[i]+1);
        else if(allocation[i]==0)
        printf("%d not allocated\n",i+1);
        else
        printf("Fault..\n");
    }
}
int main()
{
    int n=4;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    nextfit(blockSize,processSize,n);
}
*/
/*#include<stdio.h>
#include<stdio.h>

void Bestfit(int blockSize[],int processSize[] ,int n)
{
    int allocation[5];
    for(int i=0;i<5;i++)
    {
        allocation[i]=0;

    }
    


    for(int i=0;i<n;i++)
    {
        int bestindex=-1;
        for(int j=0;j<5;j++)
        {
            if(processSize[i]<=blockSize[j] )
            {
                if(bestindex==-1)
                bestindex=j;
                else if (blockSize[bestindex]>blockSize[j])
                bestindex=j;
            }
            
        }
        if(bestindex!=-1)
    {
        allocation[i]=bestindex;
        blockSize[bestindex]=blockSize[bestindex]-processSize[i];
    }
    }
    

    for(int i=0;i<n;i++)
    {
        if(allocation[i]!=0)
        printf("%d---%d\n",i+1,allocation[i]+1);
        else
        printf("%d not allocated",i+1);
    }
}

int main()
{
    int n=4;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    Bestfit(blockSize,processSize,n);
}
*/
/*#include<stdio.h>
#include<stdio.h>

void Worstfit(int blockSize[],int processSize[] ,int n)
{
    int allocation[5];
    for(int i=0;i<5;i++)
    {
        allocation[i]=0;

    }
    


    for(int i=0;i<n;i++)
    {
        int bestindex=-1;
        for(int j=0;j<5;j++)
        {
            if(processSize[i]<=blockSize[j] )
            {
                if(bestindex==-1)
                bestindex=j;
                else if (blockSize[bestindex]<blockSize[j])
                bestindex=j;
            }
            
        }
        if(bestindex!=-1)
    {
        allocation[i]=bestindex;
        blockSize[bestindex]=blockSize[bestindex]-processSize[i];
    }
    }
    

    for(int i=0;i<n;i++)
    {
        if(allocation[i]!=0)
        printf("%d---%d\n",i+1,allocation[i]+1);
        else
        printf("%d not allocated",i+1);
    }
}

int main()
{
    int n=4;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    Worstfit(blockSize,processSize,n);
}
*/