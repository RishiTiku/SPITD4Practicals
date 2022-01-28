#include <stdio.h>
#include <math.h>

int main()
{
    float principal = 500000, rate = 0.035;
    int time = 10;
    float SI = (float) principal*rate*time;
    float CIa = (float) principal*(pow(1+rate,time) - 1); // A = p[(1+r)^t], CI = p[(1+r)^t - 1] 
    float CIs = (float) principal*(pow(1+(rate/2),time*2) - 1); // CI(n) = p[(1+r/n)^nt - 1]
    float CIq = (float) principal*(pow(1+(rate/4),time*4) - 1);
    float CIm = (float) principal*(pow(1+(rate/12),time*12) - 1);
    float CId = (float) principal*(pow(1+(rate/365),time*365) - 1);
    printf("Simple Interest on Rs. %0.2f on %d years = Rs. %0.2f\n",principal,time,SI);
    printf("Interest on Rs. %0.2f on %d years compounded annually = Rs. %0.2f\n",principal,time,CIa);
    printf("Interest on Rs. %0.2f on %d years compounded semi annually = Rs. %0.2f\n",principal,time,CIs);
    printf("Interest on Rs. %0.2f on %d years compounded quarterly = Rs. %0.2f\n",principal,time,CIq);
    printf("Interest on Rs. %0.2f on %d years compounded monthly = Rs. %0.2f\n",principal,time,CIm);
    printf("Interest on Rs. %0.2f on %d years compounded daily = Rs. %0.2f\n",principal,time,CId);
    return 0;
}