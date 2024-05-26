//     Write a program to generate the Fibonacci sequence up to n terms
//  0 1 2 3 5 8 13 21 34 
#include<stdio.h>
void fib(int);
int main()
{
    int n;
    printf("Enter number to which extent you want fibonacci series:");
    scanf("%d",&n);
    fib(n);
    
    return 0;
}
void fib(int n){
    int a , b, c, d;
    a = 0;
    b = 1;
    for (int i = 2; i <= n; i++) // i = 2 beacuse 1st two terms are defined
    {
        c = a + b;
        d = b;
        b = c;
        a = d;
    }

    printf("the %dth term is %d\n",n,c);
    

}