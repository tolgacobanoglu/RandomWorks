#include <stdio.h>

int summation(int);
int powerOfNumber(int,int);
void numberDigitsPrinter(int);
void mainPrinterFunction(int);

int main()
{
    int limit;
    printf("Enter your limit : ");
    scanf("%d",&limit);

    mainPrinterFunction(limit);

    return 0;
}

void mainPrinterFunction(int limit)
{
    for(int number=1;number<limit;number++)
    {
        for(int iterationNumber=1;iterationNumber<limit;iterationNumber++)
        {
            if(powerOfNumber(iterationNumber,2)==number+summation(number))
            {
                printf("%d ",number);
                numberDigitsPrinter(number);
                printf(" %d\n",powerOfNumber(iterationNumber,2));
            }
        }
    }
}

int summation(int number)
{
    int digit, result = 0;
    while(number > 0)
    {
        digit = number % 10;
        result  = result  + digit;
        number = number / 10;
    }
    return result ;
}

int powerOfNumber(int floor,int power) // power function
{
    int result=1;

    for(int i=1;i<=power;i++)
    {
        result=floor*result;
    }
        return result;
}

void numberDigitsPrinter(int number) // printing numbers in digits
{
    int digit=0;
    printf("%d",number%10);

    while (number > 0)
    {
        if(digit>0)
        {
           printf("-%d",number%10);
        }
        number = number/10;
        digit++;
    }
}

