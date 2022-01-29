#include <stdio.h>

int main()
{
    int a, b, i = 0, LCM, GCD = 1;
    printf("Enter 2 numbers.\n");
    scanf("%d %d",&a, &b);
    if(a>b)
        i = a;
    else if(a==b)
        i = -1;
    else
        i = b;

    for(;i>=1;i--)
    {
        if(a%i==0&&b%i==0)
        {
            GCD = i;
            break;
        }    
    }
    if(i==-1)
        GCD = a;
    LCM = a*b/GCD;
    printf("The GCD of %d , %d is %d\n",a,b,GCD);
    printf("The LCM of %d , %d is %d\n",a,b,LCM);
    return 0;
}
