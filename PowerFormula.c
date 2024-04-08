#include<stdio.h>
void power(int number, int power);
int main()
{
    int n ,p;
    printf("Enter number:");
    scanf("%d",&n);
    printf("Enter Power:");
    scanf("%d",&p);
    power(n,p);
    
    return 0;
}
void power(int number, int power)
{
    int i,output;
    output = number;
    for ( i = 1; i < power; i++)
    {
        output = output * number;
    }
    printf("The %d ^ %d = %d",number,power, output);
    
}
