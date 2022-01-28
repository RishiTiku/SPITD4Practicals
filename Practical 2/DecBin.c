#include <stdio.h>
#include <math.h>
void main()
{
    int IDec, dec, rem;
    float bin = 0;
    printf("Enter number in decimal.\n");
    scanf("%d",&IDec);
    dec = IDec;
    for(int i = 0;;i++)
    {
        if(dec == 0)
            break;
        rem = dec%2;
        bin = (float) bin + rem*pow(10,i);
        dec = (int) dec/2;
        
    }
    printf("Binary for Decimal(%d) is Binary(%0.0f).\n", IDec, bin);
}