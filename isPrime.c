#include <stdio.h>
// This program will check whether an entered interger is prime or not
void isPrime();
int main()
{
    isPrime();
    return 0;
}
void isPrime()
{
    int number;
    printf("Enter a number:");
    scanf("%d", &number);

    if (number == 2 || number == 3 || number == 7)
    {
        printf("%d is Prime Number\n", number);
    }
    else if (number % 2 != 0 && number % 3 != 0 && number % 7 != 0 && number != 1)
    {
        printf("%d is Prime Number\n", number);
    }
    else
        printf("%d is not a prime number\n", number);
}