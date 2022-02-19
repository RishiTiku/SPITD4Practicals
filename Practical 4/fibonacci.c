#include <stdio.h>

int fibonacci(int);
int a = 0; 
void main()
{
    int n;
    printf("Enter a number.\n");
    scanf("%d", &n);
    for(int i = 1;i<=n;i++)
        printf("%d ",fibonacci(i));
}

int fibonacci(int n)
{
    if(n<=1)
        return 0;
    else if(n==2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
