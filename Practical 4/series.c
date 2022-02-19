#include <stdio.h>

void series(int a);

//int gn;//global_n

void main()
{
    int n;
    printf("Enter a number.\n");
    scanf("%d", &n);
    //gn = n;
    series(n);
}

/*void series(int n, char s)
{
    if(n<=0)//changes the character when encounter negative value
        s = '+';
    if(n==gn&&s=='+')//global variable gn checks if n overshoots
    {
        printf("%d", n);
        return;
    }
    printf("%d, ", n);
    if(s=='+')//if positive, increase value
        series(n+5,s);
    else//if negative, decrease value
        series(n-5,s);
}*/

void series(int n)
{
    printf("%d ",n);
    if(n<=0)
        return;
    series(n-5);
    printf("%d ", n);
}