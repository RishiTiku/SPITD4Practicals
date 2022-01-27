#include <stdio.h>

int main()
{
    int MIN, hours, minutes;
    printf("Please Enter the number of minutes.\n");
    scanf("%d",&MIN);
    hours = MIN/60;
    minutes = MIN%60;
    printf("%d minutes are %d hours and %d minutes.",MIN,hours,minutes);
    return 0;
}



