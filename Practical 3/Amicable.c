/*Write a function which takes as parameters two positive
integers and returns TRUE if the numbers are amicable
and FALSE otherwise. A pair of numbers is said to be
amicable if the sum of divisors of each of the numbers
(excluding the no. itself) is equal to the other number.
Ex. 1184 and 1210 are amicable*/

#include <stdio.h>

int isAmicable(int, int);//0 -F, 1 -T

void main()
{
    int a, b;
    printf("Enter 2 Values.\n");
    scanf("%d %d", &a, &b);
    if(isAmicable(a,b))
        printf("(%d,%d) is a pair of Amicable numbers.\n",a,b);
    else
        printf("Non Amicable.\n");
}

int isAmicable(int a, int b)
{
    int suma = 0, i, sumb = 0;
    for(i = 1; i<=a/2; i++)
        if(a%i==0)
            suma+=i;
    for(i = 1; i<=b/2; i++)
        if(b%i==0)
            sumb+=i;
    if(suma == b && sumb == a)
        return 1;
    else
        return 0;
}