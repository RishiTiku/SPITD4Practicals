#include <stdio.h>

double RateTime(int Time, double Rate);

int main()
{
    double Principal = 500000.00; //5Lac
    int Time = 10; //10 years
    double Rate = 0.035; //3.5% pa
    double SI = (double) Principal*Time*Rate;
    double CI;
    printf("Simple Interest on Rs. %0.2f on %d years = Rs. %0.2f\n",Principal,Time,SI);
    CI = Principal*RateTime(Time, Rate);
    printf("Interest on Rs. %0.2f on %d years compounded annually = Rs. %0.2f\n",Principal,Time,CI);
    CI = Principal*RateTime(Time*2, Rate/2);
    printf("Interest on Rs. %0.2f on %d years compounded semi annually = Rs. %0.2f\n",Principal,Time,CI);
    CI = Principal*RateTime(Time*4, Rate/4);
    printf("Interest on Rs. %0.2f on %d years compounded quarterly = Rs. %0.2f\n",Principal,Time,CI);
    CI = Principal*RateTime(Time*12, Rate/12);
    printf("Interest on Rs. %0.2f on %d years compounded monthly = Rs. %0.2f\n",Principal,Time,CI);
    CI = Principal*RateTime(Time*365, Rate/365);
    printf("Interest on Rs. %0.2f on %d years compounded daily = Rs. %0.2f\n",Principal,Time,CI);
    return 0;
}

double RateTime(int Time, double Rate)
{//This function returns [(1+rate)^time]-1. Multiply by Principal to get CI.
    double exp = 1.00;
    for(int i = 1; i<=Time; i++)
    {
        exp = (double) exp*(1+Rate);
    }
    exp = exp-1;
    return exp;
}




