#include <stdio.h>

double factorial(double n);

void main()
{
    double n;

    printf("Enter a Number.\n");
    scanf("%lf",&n);

    printf("The Factorial of given n = %0.0lf is %0.0lf.",n,factorial(n));
}

double factorial(double n)
{
    if(n==1)
        return 1;
    return n * factorial(n-1);
}