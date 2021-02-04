#include <stdio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, processNumber, total = 0, pos, temp;
    double avg_wt, avg_tat;

    printf("Enter the number of process: ");
    scanf("%d", &processNumber);

    for (i = 0; i < processNumber; i++)
	{
        printf("\nEnter process no,burst time and priority \n");
        scanf("%d", &p[i]);
        scanf("%d", &bt[i]);
        scanf("%d", &pr[i]);
    }

    for (i = 0; i < processNumber; i++) 
	{
        pos = i;
        for (j = i + 1; j < processNumber; j++) 
		{
            if (pr[j] < pr[pos])
            {
            	pos = j;
			}
                
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0; //first process cooldown is zero

    for (i = 1; i < processNumber; i++) 
	{
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = total / (double)processNumber; //average waiting time
    total = 0;

    printf("\npno btime wtime ttime");
    
    for (i = 0; i < processNumber; i++) 
	{
        tat[i] = bt[i] + wt[i]; //calculate turnaround time
        total += tat[i];
        printf("\n%d    %d    %d      %d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = total / (double)processNumber;

    printf("\nThe average waiting time is :%f\n", avg_wt);
    printf("The average turn around time is:%f", avg_tat);
    
    return 0;
}
