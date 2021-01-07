#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for sleep function

/*
-temperature+=rand()%5; // create temperature with 35 Celsius and rand will be add a random number between 0-5 if 36.5> program never run
-the password is --" 35 "--,if cashier enter the --" 35 "-- ,ordering will be finished,it is the exit option
-option : coffee
-size : if user don't enter between 1 or 3,it will be just 1
-extraEspresso : price is 2.25
-milkType : coffee starting with normal milk
-extraEspressoNumber : normal coffee ingredients : just original number espresso
-cream :normally there are no cream on coffee
 */

void exitOption(int);// to close program
void welcomeMessage();
void temperatureAskingMeasuringMessage();
void readingValueOfTemperature(int);
void highTemperature(int);
void coffeeMenu();
float coffeeType(int);
void iceOrHot();
void sizeMessage();
float coffeeSize(int);
void milkMessage();
float milkType(int);
void stateOfMilk();
void espressoMessage();
float extraEspresso(int);
void creamMessage();
float creamInCoffee(int);
void preparingOrder();
void readyToGo();
int testOfCoffeeOrderNumber(int);
void coffeeNumber();

int main()
{

    float price,totalPrice=0;
    int option,size=1,hotOrIce,milk=1,extraEspressoNumber=0,cream=0,temperature=35,milkStates=1,coffeeOrderNumber,i=1;
    temperature+=rand()%6; // if program doesn't work make this statement comment line because rand is giving random number 0-6 your temperature might be 35-41 Celsisus


    welcomeMessage();
    temperatureAskingMeasuringMessage();
    readingValueOfTemperature(temperature);
    highTemperature(temperature);
    coffeeNumber();
    scanf("%d",&coffeeOrderNumber);
    exitOption(coffeeOrderNumber);
    testOfCoffeeOrderNumber(coffeeOrderNumber);

    while(coffeeOrderNumber>=i)
    {
        coffeeMenu();
        scanf("%d",&option);
        exitOption(option);
        iceOrHot();
        scanf("%d",&hotOrIce);
        exitOption(hotOrIce);
        sizeMessage();
        scanf("%d",&size);
        exitOption(size);
        milkMessage();
        scanf("%d",&milk);
        exitOption(milk);
        stateOfMilk();
        scanf("%d",&milkStates);
        exitOption(milkStates);
        espressoMessage();
        scanf("%d",&extraEspressoNumber);
        exitOption(extraEspressoNumber);
        creamMessage();
        scanf("%d",&cream);
        exitOption(cream);
        price=coffeeType(option) + milkType(milk)+coffeeSize(size)+extraEspresso(extraEspressoNumber)+creamInCoffee(cream);
        totalPrice+=price;
        i++;
    }

    printf("Price is : %.2f\n",totalPrice);

    sleep(10);
    preparingOrder();
    sleep(10);
    readyToGo();


    return 0;
}

void exitOption(int number)
{
    if(number==35)
    {
        exit(0);
    }
}

void welcomeMessage()
{
    printf("*  Welcome to Starbucks   *\n");
}

void temperatureAskingMeasuringMessage()
{
    printf("Could I measure your temperature ?\n");
}

void readingValueOfTemperature(int temperature)
{
    printf("Your temperature is : %d Celsius\n",temperature);
}

void highTemperature(int temperature)
{
    if(temperature>36.5)
    {
        printf("Take care yourself,your temperature is higher than 36.5,we can not accept you to enter !");
        exit(0);
    }

}

void coffeeMenu()
{
    printf("What would you like to drink ?");
    printf("\n1.Latte\n2.Mocha\n3.White Chocolate Mocha\n4.Americano\n5.Filter Coffee\n6.Cappuccino\n7.Flat White\n");
    printf("Please enter your coffee choice :");
}

float coffeeType(int option)
{

    if(option == 1)//latte
    {
        return 11.50;
    }
    else if(option == 2)//mocha
    {
        return    14.25;
    }
    else if(option == 3)//white chocolate mocha
    {
        return 15.25;
    }
    else if(option == 4)//americano
    {
        return 11.00;
    }
    else if(option == 5)//filter coffee
    {
        return 8.50;
    }
    else if(option == 6)//cappuccino
    {
        return 11.50;
    }
    else if(option == 7)//flat white
    {
        return 12.75;
    }

}

void iceOrHot()
{
    printf("Would you like your coffee 1.Ice or 2.Hot :");
}

void sizeMessage()
{
    printf("What size would you like your drink ?\n");
    printf("1.Tall 2.Grande 3.Venti :");
}

float coffeeSize(int size)
{
    if(size==2)
    {
        return 2.00;
    }
    else if(size==3)
    {
        return 4.00;
    }
    else
    {
        return 0.00;
    }
}

void milkMessage()
{
    printf("Which type of milk do you prefer ?\n");
    printf("1.Normal milk\n2.Lactose-free milk\n3.Soy milk\n4.Almond milk\n5.Coconut milk\n6.Fat-free milk\n");
    printf("Enter your milk choice : ");
}

float milkType(int milk)
{
    if(milk==1)
    {
        return 0.00;
    }
    else if(milk==2)
    {
        return 1.00;
    }
    else if(milk==3)
    {
        return 2.00;
    }
    else if(milk==4)
    {
        return 3.00;
    }
    else if(milk==5)
    {
        return 3.00;
    }
    else if(milk==6)
    {
        return 2.00;
    }
    else
    {
        return 0.00;
    }
}

void stateOfMilk()
{
    printf("1.Normal\n2.Steamed Milk\n3.Milk Foam\n");
    printf("In which state do you would like the milk in the coffee:\n");
}

void espressoMessage()
{
    printf("How many extra shots of espresso do you want : ");
}

float extraEspresso(int number)
{
    float price=number*2.25;
    return price;
}

void creamMessage()
{
    printf("Do you want cream on your coffee ?\n1.Yes 2.No : ");
}

float creamInCoffee(int exist)
{
    if(exist==1)
    {
        return 2.00;
    }
    else
    {
        return 0.00;
    }
}
void preparingOrder()
{
    printf("Your order is being prepared, the estimated waiting time is a minute.\n");
}

void readyToGo()
{
    printf("Your coffee is ready.\nBon appetit !");
}

int testOfCoffeeOrderNumber(int orderNumber)
{
    if(orderNumber>3||orderNumber<0)
    {
        while (orderNumber > 3 || orderNumber<=0)
        {
            printf("You can order 3 or less coffee,please reorder valid quantity :");
            scanf("%d",&orderNumber);
        }
    }
    return orderNumber;
}

void coffeeNumber()
{
    printf("How many coffee would you like to order :");
}