#include <stdio.h>

int main()
{
    int i=2,theBiggest;
    long long int number=600851475143;

    while(number!=1)
    {
        if(number%i==0)
        {
            printf("%10lu   |%6d\n",number,i);
            number=number/i;
            theBiggest=i;
        }
        else
        {
            i++;
        }
    }

    printf("the biggest divider prime number = %d",theBiggest);

    return 0;
}
