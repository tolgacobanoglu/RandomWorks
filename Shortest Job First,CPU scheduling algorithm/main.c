#include<stdio.h>

struct process
{
int id,wait,ser,tottime;
}

p[20];

struct process tmp;//swap variable for bubble sort algorithm

int main()
{
    int i,n,j,totalwait=0,totalser=0,avturn,avwait;
    printf("enter number of process\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("enter process_id\n");
        scanf("%d",&p[i].id);
        printf("enter process service time\n");
        scanf("%d",&p[i].ser);
    }

    for(i=0;i<n;i++) // bubble sort algorithm
    {
        for(j=i+1;j<=n;j++)
        {
            if(p[i].ser>p[j].ser)
            {
                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }

    p[1].wait=0;//make first process wait time 0
    p[1].tottime=p[1].ser;

    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            p[i].wait=p[i].wait+p[j].ser;
        }
    totalwait=totalwait+p[i].wait;
    p[i].tottime=p[i].wait+p[i].ser;
    totalser=totalser+p[i].tottime;
    }

    avturn=totalser/n;
    avwait=totalwait/n;

    printf("Id\tservice\twait\ttotal");

    for(i=1;i<=n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\n",p[i].id,p[i].ser,p[i].wait,p[i].tottime);
    }
    // for outputs
    printf("total waiting time : %d\n",totalwait);
    printf("average waiting time : %d\n",avwait);
    printf("total turnaround time : %d\n",totalser);
    printf("average turnaround time : %d",avturn);

}
