/*The Mobius function M (N) is defined as
μ(n) = +1 if n is a square-free positive integer with an even number of prime factors.
μ(n) = −1 if n is a square-free positive integer with an odd number of prime factors.
μ(n) = 0 if n has a squared prime factor.
M (78) = -1 [ 78 = 2 * 3 * 13 ]
M (34) = 1 [ 34 = 2 * 17 ]
M (45) = 0 [ 45 = 3 * 3 * 5 ]
Write a function MOBIUS as specified above. */

#include <stdio.h>

int Mobius(int); //returns -1,0,1

void main()
{
    int a;
    printf("Enter a number.\n");
    scanf("%d", &a);
    printf("Mobius output of %d is %d",a,Mobius(a));
}

int Mobius(int a)
{
    int ctr = 0, flag = 1;
    for(int i = 2;i<=a;i++)//Generates numbers which may contain prime divisors
    {
        for(int j = 2; j*j<=i;j++)//Checks i is prime
            if(i%j==0)
            {
                flag = 0;
                break;
            }
        if(flag==1&&a%i==0)
        {
            if((a/i)%i==0)
                return 0; //Squared Prime Divisors
            ctr++;
        }
        flag = 1;//Next Number is prime by default
    }
    if(ctr%2==0)
        return 1; //Even no. of Prime Divisors
    else
        return -1; //Odd number of Prime Divisors
}