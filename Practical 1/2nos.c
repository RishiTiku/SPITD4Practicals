#include <stdio.h>

int main()
{
    int a, b, sum, diff, prod, mod;
    float quo;
    printf("Please Enter 2 numbers.\n");
    scanf("%d%d",&a,&b);
    sum = a+b;
    diff = a-b;
    prod = a*b;
    mod = a%b;
    quo = (float) a/b;
    printf("\nSum of the numbers = %d",sum);
    printf("\nDifference of First and Second = %d",diff);
    printf("\nProduct of the numbers = %d",prod);
    printf("\nQuotient of First/Second = %f",quo);
    printf("\nModulus of First/Second = %d",mod);
    return 0;
}