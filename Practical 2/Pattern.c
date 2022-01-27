#include <stdio.h>

void Pattern(int);

void main()
{
    int n;
    printf("Enter a number.\n");
    scanf("%d",&n);
    Pattern(n);
}

void Pattern(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n*2; j++)
        {
            if(j>=n-i&&j<n+i)
                printf("  ");
            else
                printf("* ");
        }
        printf("\n");
    }
    for(int i = n-1; i>=0; i--)
    {
        for(int j = 0; j<n*2; j++)
        {
            if(j>=n-i&&j<n+i)
                printf("  ");
            else
                printf("* ");
        }
        printf("\n");
    }
}


