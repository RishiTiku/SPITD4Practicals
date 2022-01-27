#include <stdio.h>

int main()
{
    float Fahrenheit, Celsius;
    printf("Please Enter the temperature in Fahrenheit.\n");
    scanf("%f",&Fahrenheit);
    Celsius = (float)(Fahrenheit-32)*5/9;
    printf("\nTemperature %0.2f \'F in Celsius = %0.2f \'C",Fahrenheit,Celsius);
    return 0;
}