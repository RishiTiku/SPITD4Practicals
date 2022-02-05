/*Write a function which takes a range as input. Print all the numbers in the range with ‘*’ in front of prime numbers only.
Example:
Print a table as follows
1* 2* 3* 4 5* ... 10
11* 12 13* 14 15 ... 20
upto 100. All primes are starred. */

#include <stdio.h>

int isPrime(int);

void main()
{
    int a, b;
    printf("Enter 2 numbers for ranges. \n");
    scanf("%d %d",&a,&b);
    if(a==b)
    {    
        printf("Cannot have Equal numbers.\n");
        return;
    }
    else if(a>b) 
    {//Swap the two numbers so a has the lower limit always
        a = a + b;
        b = a - b;
        a = a - b;
    }
    //now a<b always
    
    for(int i = a; i<=b; i++)
    {
        printf("%d ",i);
        if(isPrime(i))
            printf("*  ");
        if((i-a+1)%10==0)
            printf("\n");
    }

}

int isPrime(int a)
{
    if(a<=1)
        return 0;
    for(int i = 2; i*i<=a; i++)
        if(a%i == 0)
            return 0;
    return 1;
}