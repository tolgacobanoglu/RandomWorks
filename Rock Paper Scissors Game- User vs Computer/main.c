#include <stdio.h>
#include <stdlib.h> // for rand function
#include <time.h> //for in srand function time(0)
#include <unistd.h>//for sleep function

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int userScore=0,computerScore=0;

void welcomeMessage();
void startMessage();
void userMovesMessage();
void computerMovesMessage(int);
int userMovesChecker(int);
void moveComparer(int,int);
void winnerExplanatory(int);
void liveScore();

int main()
{
    int userMoveNumber,computerMoveNumber;

    srand(time(0));

    welcomeMessage();
    startMessage();
    while (userScore < 3 && computerScore < 3)
    {
        userMovesMessage();
        scanf("%d",&userMoveNumber);
        userMoveNumber=userMovesChecker(userMoveNumber);
        computerMoveNumber=1+rand()%2;
        computerMovesMessage(computerMoveNumber);
        moveComparer(userMoveNumber, computerMoveNumber);
        liveScore();
        sleep(1);//make this game more reality
    }

    winnerExplanatory(userScore);

    return 0;
}

void welcomeMessage()
{
    printf("**** Welcome Rock Paper Scissors Game ****\n                (3 Wins !)\n");
}

void startMessage()
{
    printf("   LETS START THE GAME WITH PLAYER  COMPUTER  VS.  YOU \n");
}

void userMovesMessage()
{
    printf("Your turn,Choose your move\n");
    printf("1.Rock\n");
    printf("2.Paper\n");
    printf("3.Scissors\n");
    printf("Your pick :");
}

void computerMovesMessage(int moveNumber)
{
    printf("Computer pick :%d\n",moveNumber);
}

int userMovesChecker(int moveNumber)
{
    while(moveNumber>3 || moveNumber<1)
    {
        printf("Enter valid move please :");
        scanf("%d",&moveNumber);
    }
    return moveNumber;
}

void moveComparer(int firstPlayers,int secondPlayers)
{
    if(firstPlayers==ROCK && secondPlayers==PAPER)
    {
        computerScore+=1;
    }
    else if(firstPlayers==ROCK && secondPlayers==SCISSORS)
    {
            userScore+=1;
    }
    else if(firstPlayers==PAPER && secondPlayers==ROCK)
    {
        userScore+=1;
    }
    else if(firstPlayers==PAPER && secondPlayers==SCISSORS)
    {
        computerScore+=1;
    }
    else if(firstPlayers==SCISSORS && secondPlayers==PAPER)
    {
        userScore+=1;
    }
    else if(firstPlayers==SCISSORS && secondPlayers==ROCK)
    {
        computerScore+=1;
    }
    else
    {
        userScore+=0;
    }
}

void winnerExplanatory(int firstsScore)
{
    if(firstsScore==3)
    {
        printf("YOU WIN !!!");
    }
    else
    {
        printf("COMPUTER WIN !!!");
    }
}

void liveScore()
{
    printf("User Score %d - %d Computer Score\n",userScore,computerScore);
}