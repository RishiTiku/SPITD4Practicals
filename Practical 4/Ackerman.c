#include <stdio.h>

double Ack(double, double);

void main()
{
    double a, b;
    printf("Enter two numbers (n1<=3, n2<=10, n1,n2>=0).\n");
    scanf("%lf %lf", &a, &b);
    for(int i = 0;i<=a;i++)
    {
        for(int j = 0; j<=b;j++)
            printf("%0.0lf ",Ack(i,j));
        printf("\n");
    }
}

double Ack(double m, double n)
{
    if(m == 0)
        return n+1;
    if(n == 0)
        return Ack(m-1.0,1.0);
    if(m != 0 && n != 0)
        return Ack(m-1,Ack(m,n-1));
}