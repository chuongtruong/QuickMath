#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void generator(int *n1, int *n2, int *n3);
bool timer(clock_t begin, clock_t end);
void levelHlder(int *max, int level, double *timeLimit);

int num1, num2, num3, result, answer;
double timeLimit = 2.0;
int max = 10;

//Handle different level of the game
void levelHlder(int *max, int level, double *timeLimit){
    //if score <= 5, generate number from 0-10
    if(level <= 5){
        *max = 10;
    } else if(level <=10){
        //if score <= 10, generate number from 0-15, give player .5 second extra
        *max = 15;
        *timeLimit = 2.5;
    } else if(level <=15){
        //if score <= 15, generate number from 0-20, give player 1 second extra
        *max = 20;
        *timeLimit = 3.0;
    } else {
        //otherwise, generate number from 0-100, give player 2 second extra
        *max = 100;
        *timeLimit = 4.0;
    }
}

//generate random number function
void generator(int *n1, int *n2, int *n3)
{
    //create random number from 0-10
    *n1 = rand() % max;
    *n2 = rand() % max;

    //case num2 = 0, re-generate num2. Avoid 0 devision;
    while (*n2 == 0)
    {
        *n2 = rand() % 10;
    }

    //create random number from 0-4
    *n3 = rand() % 4;
}

//calculate time taken for an answer.
bool timer(time_t begin, time_t end)
{
    if ((end - begin) <= timeLimit)
    {
        return false;
    }
    return true;
};

void main()
{
    bool isContinue = true;
    int score = 0;
    time_t t;
    srand((unsigned)time(&t));

    while (isContinue)
    {
        levelHlder(&max, score, &timeLimit);
        generator(&num1, &num2, &num3);
        switch (num3)
        {
        case 0:
        {
            printf("%d + %d", num1, num2);
            result = num1 + num2;
            printf(" = ");
            time_t begin = time(NULL);
            scanf("%d", &answer);
            time_t end = time(NULL);

            if (timer(begin, end))
            {
                printf("Time out\n");
                isContinue = false;
                break;
            }
            if (answer != result)
            {
                printf("wrong !! answer is: %d\n", result);
                isContinue = false;
                break;
            }
            else
            {
                score++;
                continue;
            }
        }
        case 1:
        {
            printf("%d - %d", num1, num2);
            result = num1 - num2;
            printf(" = ");
            time_t begin = time(NULL);
            scanf("%d", &answer);
            time_t end = time(NULL);

            if (timer(begin, end))
            {
                printf("Time out\n");
                isContinue = false;
                break;
            }
            if (answer != result)
            {
                printf("wrong !! answer is: %d\n", result);
                isContinue = false;
                break;
            }
            else
            {
                score++;
                continue;
            }
        }

        case 2:
        {
            printf("%d * %d", num1, num2);
            result = num1 * num2;
            printf(" = ");
            time_t begin = time(NULL);
            scanf("%d", &answer);
            time_t end = time(NULL);

            if (timer(begin, end))
            {
                printf("Time out\n");
                isContinue = false;
                break;
            }
            if (answer != result)
            {
                printf("wrong !! answer is: %d\n", result);
                isContinue = false;
                break;
            }
            else
            {
                score++;
                continue;
            }
        }

        case 3:
        {
            printf("%d / %d", num1, num2);
            result = num1 / num2;
            printf(" = ");
            time_t begin = time(NULL);
            scanf("%d", &answer);
            time_t end = time(NULL);

            if (timer(begin, end))
            {
                printf("Time out\n");
                isContinue = false;
                break;
            }
            if (answer != result)
            {
                printf("wrong !! answer is: %d\n", result);
                isContinue = false;
                break;
            }
            else
            {
                score++;
                continue;
            }
        }

        default:
            printf("Some unexpected bugs...\n");
        }
    }
    printf("\nTotal score: %d\n", score);
}



/*

Basic ideas:
    
    +2-4 seconds to solve an operation of 2 numbers
    
    +Very easy one ^^.

    +1 point each.
    
    +4 different levels:

        +[0-10]  - scores <= 5          
        +[0-15]  - 5 <= scores <= 10
        +[0-20]  - 10 <= scores <= 15
        +[0-100] - scores >= 5 points

Rule:

    If a number isn't divisible by other number, answer will be rounded down.
    E.g.
        3/2 = 1.5 -> 1
        9/5 = 1.8 -> Still 1


*/