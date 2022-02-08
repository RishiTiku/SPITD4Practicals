#include <stdio.h>

void SumofSeries(int);

void main()
{
    int n;
    printf("Enter a number n.\n");
    scanf("%d",&n);
    SumofSeries(n);
}

void SumofSeries(int n)
{
    double factorial = 1; 
    double sum = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
            factorial *= j;
        sum+=(double) i/factorial;
        printf("%d/%0.0lf ",i, factorial);
        factorial = 1;

        if(i%5==0)//some convenient formatting
            printf("\n");
        if(i == n)//Don't Print plus after last digit
            break;
        printf("+ ");
    }
    printf(" = %0.3lf", sum);
}