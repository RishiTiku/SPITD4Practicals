/*Write a function to find the sum of the proper divisors of a given number ‘n’.
The proper divisors of a number ‘n’ are the numbers less than n that divide it evenly.
They do not include n itself. 
e.g. n=12 sum =1+2+3+4+6=16
*/

#include <stdio.h>

int sumProper(int);//returns sum of proper divisors

void main()
{
    int a;
    printf("Enter a number.\n");
    scanf("%d", &a);
    printf("%d is the sum of divisors of the given number.\n",sumProper(a));
}

int sumProper(int a)
{
    int sum = 0, i;
    for(i = 1; i<=a/2; i++)
        if(a%i==0)
            sum+=i;
    return sum;
}