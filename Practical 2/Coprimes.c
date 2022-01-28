#include <stdio.h>
#include <math.h>

int isPrime(int);

void main()
{
    int a, b;
    printf("Enter 2 numbers for ranges. \n");
    scanf("%d %d",&a,&b);
    if(isPrime(7))
        printf("It is prime.\n");
    else 
        printf("No.");

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
    
    for(int i = a; i<=b-2; i++)
    {
        if(isPrime(i))
            if(isPrime(i+2))
                printf("(%d, %d) are coprimes\n",i,i+2);
    }

}

int isPrime(int a)
{
    int root = (int) sqrt(a);
    //printf("%d \n", root);
    for(int i = 2; i<=root; i++)
        if(a%i == 0)
        {  
            return 0;
        }
    return 1;
}
