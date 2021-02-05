#include <stdio.h>

struct file
{
    char fname[10];
    int start, length, block[10];;
}

f[10];

void main()
{
    int i, j, n;

    printf("Enter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter file name: ");
        scanf("%s",&f[i].fname);
        printf("Enter starting block:");
        scanf("%d", &f[i].start);
        printf("Enter no.of blocks:");
        scanf("%d", &f[i].length);
        printf("Enter block numbers:");
        f[i].block[0] = f[i].start;

        for (j = 1; j <= f[i].length; j++)
        {
            scanf("%d", &f[i].block[j]);
        }
    }

    printf("File\tstart\tsize\tblock\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].length);
        for (j = 1; j <= f[i].length - 1; j++)
        {
            printf("%d--->", f[i].block[j]);
        }
        printf("%d\n", f[i].block[j]);
    }
}
