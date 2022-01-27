#include <stdio.h>

int main()
{
    int DAYS, years, months, days;
    printf("Please Enter the number of days.\n");
    scanf("%d",&DAYS);
    years = DAYS/365;
    months = (DAYS%365)/30;
    days = (DAYS%365)%30;
    printf("%d days are %d years, %d months and %d days",DAYS,years,months,days);
    return 0;
}