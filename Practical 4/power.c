#include <stdio.h>

double power(double x, double y);

void main()
{
    double x, y;
    printf("Enter a number.\n");
    scanf("%lf", &x);
    printf("Enter the power.\n");
    scanf("%lf", &y);
    if(y<0)
        printf("Result = %0.7lf.\n",power(x , y));
    else
        printf("Result = %0.0lf.\n",power(x , y));
}

double power(double x, double y)
{
    if(y==0)
        return 1;
    else if(y==1)
        return x;
    else
        if(y<0)
        {    
            x = 1/x;
            y = -y;
        }
    return x*power(x,y-1); 
}