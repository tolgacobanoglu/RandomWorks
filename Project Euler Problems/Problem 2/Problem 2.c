#include <stdio.h>

int main()
{
    int i=2;
    long long int restrictive=0,sumOfElements=0;
    long fibonacciArray[1000];

    fibonacciArray[0]=1;
    fibonacciArray[1]=2;

    fibonacciArray[2]=fibonacciArray[0]+fibonacciArray[1];

    sumOfElements+=fibonacciArray[1];

    while(restrictive<4000000)
    {
        fibonacciArray[i+1]=fibonacciArray[i]+fibonacciArray[i-1];

        if (fibonacciArray[i+1]%2==0)
        {
            sumOfElements+=fibonacciArray[i+1];
            restrictive=sumOfElements;
        }

        i+=1;
    }

    printf("%lu",sumOfElements);

    return 0;
}
