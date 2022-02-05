/*Write a program that prints the following pattern 
input n = 5 
        1                   
      1 2 3                 
    1 2 3 4 5               
  1 2 3 4 5 6 7             
1 2 3 4 5 6 7 8 9
*/

#include <stdio.h>

void Pattern(int);

void main()
{
    int n;
    printf("Enter a number.\n");
    scanf("%d",&n);
    Pattern(n);
}

void Pattern(int n)//n layers
{
    int ctr = 1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<n*2+i; j++)
        {
            if(j>=n+1-i&&j<n+i)
            {    
                printf("%d ",ctr);
                ctr++;
            }
            else 
            printf("  ");
        }
        printf("\n");
        ctr = 1;
    }
}