#include <stdio.h>
#include <math.h>

//n+1 right, n left
void main()
{
    int n, r, sqn, sqnc, ctr = 0, p;
    printf("Enter number to be checked for Kaprekar.\n");
    scanf("%d",&n);
    sqn = sqnc = n*n;
    while(sqnc>0)
    {
        sqnc = sqnc/10; 
        ctr++;
    }
    if(ctr%2==0)
        r = ctr/2;
    else
        r = ctr/2 + 1;//right
    p = (float) pow(10,r);
    sqnc = (int) sqn % p;
    sqn = (int) sqn/p;
    if((sqnc+sqn) == n)
        printf("%d is a Kaprekar number.",n);
    else
        printf("%d is not a Kaprekar number.",n);
}
