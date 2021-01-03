#include <stdio.h>
#include <stdlib.h>// for rand function
#include <stdbool.h>  //for boolean
#include<time.h> // for in srand function parameter time function
#include <unistd.h> //for sleep function

int arrayFiller(int[],int);
int randomPosition();
int absolute(int);
int identifierPrimeNumber(int);
int squareRoot(int);
void journeyAnalyseInformation(int,unsigned long long int);

int main() {

    int city[1000];
    int i,journeyNumber=1,currentLocation,previousLocation,nextLocation,emptyCityCounter=0;
    unsigned long long int totalGolds=0;
    /*
     * city[1000] : cities
     * totalGolds=0 : count the collected golds
     * journeyNumber=0 : The number of cities visited
     * currentLocation : current city index
     * previousLocation : ex city index
     * nextLocation : traveler where will journey
     * emptyCityCounter=0 :  count the last three visited city has no gold
     */

    srand(time(0));     //to give different values for all run rand function

    for(i=0;i<1000;i++)     //assign values into city,if I dont do it and use just arrayFiller(city,3) I can't use and assign this element
    {
        city[i]=arrayFiller(city,i);
    }

    currentLocation=randomPosition();
    previousLocation=0;

    while(emptyCityCounter!=3)
    {
        totalGolds+=city[currentLocation];    //collect golds

        if(city[currentLocation]>1)//if there are golds different 0 and 1 in textbox will be "golds",if it is 1 or 0 it must be gold.This one is just for gold or golds.Idont want to do gold(s):D
        {
            printf("%d. Journey from P(%d) to P(%d).In this city,there're %d golds.",journeyNumber,previousLocation,currentLocation,city[currentLocation]);
        }
        else
        {
            printf("%d. Journey from P(%d) to P(%d).In this city,there's %d gold.",journeyNumber,previousLocation,currentLocation,city[currentLocation]);
        }

        if (identifierPrimeNumber(totalGolds)==false)
        {
            totalGolds*=3;
            printf("PRIME!");
        }
        else if(squareRoot(totalGolds)==true)
        {
            totalGolds*=2;
            printf("PERFECT!");
        }
        else
        {
            totalGolds+=0;
        }

        printf("Total golds in pouch : %llu\n",totalGolds);

        journeyNumber+=1;   //journey counter

        if(city[currentLocation]==0)    //counter for the finish game
        {
            emptyCityCounter+=1;
        }
        else
        {
            emptyCityCounter=0;
        }

        if(city[currentLocation]%2==0)  //for next journey
        {
            nextLocation=absolute((currentLocation+previousLocation+city[currentLocation])%1000);
        }
        else
        {
            nextLocation=absolute((currentLocation+previousLocation-city[currentLocation])%1000);
        }

        city[currentLocation]=0;      //no gold is left at that city
        previousLocation=currentLocation;
        currentLocation=nextLocation;
        sleep(1); // make it more reality game
    }

    journeyAnalyseInformation(journeyNumber-1,totalGolds);
    return 0;
}

int arrayFiller(int array[],int n)  //that fills an integer array of size 1000 with random positive integers between 1 and 10, n is I want to be equals them by one by in main.
{
    for(int i=0;i<1000;i+=1)
    {
        array[i]=1+rand()%10;
    }

    return array[n];
}

int randomPosition()        //starting from a random position
{
    return rand()%1000;
}

int absolute(int number)
{
    if(number<0)
    {
        return (-1)*(number);
    }
    else
    {
        return number;
    }
}

int identifierPrimeNumber(int number)
{
    bool prime=false;
    int i=2;
    while(number>i)
    {
        if(number%i == 0)
        {
            prime=true;
            break;
        }
        i++;
    }

    return prime;
}

int squareRoot(int number)
{
    bool mark=false;
    for(int i=0;i<number;i+=1)
    {
        if(i*i==number)
        {
            mark=true;
        }
    }
    return mark;
}

void journeyAnalyseInformation(int travelledTimes,unsigned long long int goldBalance)
{
    printf("End of the journey,you travelled %d times and earned %llu golds.",travelledTimes,goldBalance);
}