#include <stdio.h>
#include <stdlib.h>

void clearField(int arr[20][20])
{
    for (int i = 0; i < 20; i=i+1)
    {
        for (int j=0;j<20;j=j+1)
        {
            arr[i][j]=0;
        }
    }
}

void printCleanedField(int arr[20][20])
{
    for (int i = 0; i < 20; i=i+1)
    {
        for (int j=0;j<20;j=j+1)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
}

void putMine(int arr[20][20],int row,int column)//dizinin hangi elemanlarına mayın geleceğini iki farklı dizi ile gönderebiliriz
{
    arr[row][column]=-1;
}

void putMinesPosition(int arr[20][20],int mineNumber)
{
    int i,j;
    while (mineNumber >= 0)
    {
        i=rand()%20;
        j=rand()%20;

        if(arr[i][j]==-1)
        {
            while (arr[i][j]!=-1)
            {
                i=rand()%20;
                j=rand()%20;
            }
        }

        putMine(arr,i,j);
        //arr[i][j]=-1;
        mineNumber-=1;
    }
}

void afterPutMinesPrintField(int arr[20][20])
{
    for (int i = 0; i < 20; i=i+1)
    {
        for (int j=0;j<20;j=j+1)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
}

void printAfterNeighbors(int arr[20][20])
{
    for (int i = 0; i < 20; i=i+1)
    {
        for (int j=0;j<20;j=j+1)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
}

void printField(int arr[20][20])
{
    for (int i = 0; i < 20; i=i+1)
    {
        for (int j=0;j<20;j=j+1)
        {
            if(arr[i][j]==-1)
            {
                printf(" * ");
            }
            else
            {
                printf("%2d ",arr[i][j]);
            }
        }
        printf("\n");
    }
}

void divider(int number)
{
    for(int i=0;i<number;i++)
    {
        printf("-");
    }
    printf("\n");
}

int main() {

    int mineField[20][20];

    clearField(mineField);  //tüm elemanları 0'a çevirmek
    printCleanedField(mineField);   // elemanları 0 olan matrisi yazdırmak ilk görev

    divider(60);

    int mineNumber=(rand()%399)+1;  //kaç tane mayın olacağı belirler

    putMinesPosition(mineField,mineNumber);//putMine fonksiyonu içindedir
    afterPutMinesPrintField(mineField);

    divider(60);

    for (int i = 0; i < 20; i=i+1)//processField()
    {
        for (int j=0;j<20;j=j+1)
        {
            if (mineField[i][j] == -1)
            {
                if(mineField[i - 1][j - 1] != -1)
                {
                    mineField[i - 1][j - 1]+=1;
                }
                if (mineField[i - 1][j] != -1)
                {
                    mineField[i - 1][j]+=1;
                }
                if (mineField[i - 1][j + 1] != -1)
                {
                    mineField[i - 1][j + 1]+=1;
                }
                if (mineField[i][j - 1] != -1)
                {
                    mineField[i][j - 1]+=1;
                }
                if (mineField[i][j + 1] != -1)
                {
                    mineField[i][j + 1]+=1;
                }
                if (mineField[i + 1][j - 1] != -1)
                {
                    mineField[i + 1][j - 1]+=1;
                }
                if(mineField[i + 1][j] != -1)
                {
                    mineField[i + 1][j]+=1;
                }
                if(mineField[i + 1][j + 1] != -1)
                {
                    mineField[i + 1][j + 1]+=1;
                }
            }
        }
    }

    printAfterNeighbors(mineField);
    divider(60);
    printField(mineField);

    return 0;
}


