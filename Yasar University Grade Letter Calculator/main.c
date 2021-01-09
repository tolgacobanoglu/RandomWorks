#include <stdio.h>

void letterCalculator(int);

int main()
{
    int grade;
    printf("Enter your grade you want calculated :");
    scanf("%d",&grade);
    letterCalculator(grade);
    return 0;
}

void letterCalculator(int grade)
{
        if(grade>=95&&grade<=100)
    {
        printf("Grade : %d , Letter Grade : A",grade);
    }
    else if(grade>=90&&grade<=94)
    {
        printf("Grade : %d , Letter Grade : A-",grade);
    }
    else if(grade>=85&&grade<=89)
    {
        printf("Grade : %d , Letter Grade : B+",grade);
    }
    else if(grade>=80&&grade<=84)
    {
        printf("Grade : %d , Letter Grade : B",grade);
    }
    else if(grade>=75&&grade<=79)
    {
        printf("Grade : %d , Letter Grade : B-",grade);
    }
    else if(grade>=70&&grade<=74)
    {
        printf("Grade : %d , Letter Grade : C+",grade);
    }
    else if(grade>=65&&grade<=69)
    {
        printf("Grade : %d , Letter Grade : C",grade);
    }
    else if(grade>=60&&grade<=64)
    {
        printf("Grade : %d , Letter Grade : C-",grade);
    }
    else if(grade>=55&&grade<=59)
    {
        printf("Grade : %d , Letter Grade : D+",grade);
    }
    else if(grade>=50&&grade<=54)
    {
        printf("Grade : %d , Letter Grade : D",grade);
    }
    else if(grade>=0&&grade<50)
    {
        printf("Grade : %d , Letter Grade : F",grade);
    }
    else
    {
        printf("Grade %d is not valid. The grade must be between 0 and 100!!!",grade);
    }
}
