// i am trying to solve it without using recursive functions
#include <stdio.h>
int main()
{
    int number;
    printf("Enter number whose you want factorial:");
    scanf("%d", &number);

    // lets suppose user enter 4
    // 4*3*2*1 my goal
    // i will use for loop and use entered number for iteration limit
    int multiplier;
    multiplier = number - 1; // multiplier = 3
    int output = number;     // output = 4

    if (number == 0 || number == 1)
    {
        printf("%d!=%d", number, 1);
    }
    else
    {
        for (int i = 1; i < number; i++) // imporatant note , i = 0 , i<number
        {
            output = output * multiplier; // 4*3,12*2,24*1
            multiplier--;                 // don't let the value of multiplier to reach zero '(i<number)'
        }
        printf("%d!=%d\n", number, output);
    }
    return 0;
}