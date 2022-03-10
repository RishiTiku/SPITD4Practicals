#include <stdio.h>
#define pf printf
#define sf scanf

void Sort(int A[][2], int n);
void print(int A[][2], int n, char name);
void main()
{
    int cur, n;
    pf("Enter current year.\n");
    sf("%d", &cur);
    pf("Enter number of employees.\n");
    sf("%d", &n);
    int A[n][2];
    //Input the Matrix
    for(int i = 0; i<n; i++)
    {
        pf("Enter Employee #%d Number.\n", i+1);
        sf("%d", &A[i][0]);
        pf("Enter Employee Age.\n");
        sf("%d", &A[i][1]);
        A[i][1] = cur + 65 - A[i][1];//retirement year here  
    }
    Sort(A, n);
    for(int i = 0; i<n;)
    {
            pf("Retirement Year = %d. \n Employee IDs = ", A[i][1]);
            do
            {
                pf("%d ", A[i][0]);
            }while(i<n && A[i]==A[++i]);
            pf("\n");
    }
}

void print(int A[][2], int n, char name)
{
    printf("\n[+] Array %c[%d][%d]:\n",name , m, n);
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<2; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
}

void Sort(int A[][2], int n)
{
    int min = A[0][1], pos = 0, temp = 0;
    for(int i = 0; i<n; i++)//Loop to sort the Matrix based on year
    {
        for(int j = 0; j<n; j++)//Loop to calculate next min value
        {
            if(A[j][1]<=min)
            {
                min = A[j][1];
                pos = j;
            }
        }
        for(int k = 0; k<2;k++)//Loop to swap Variables
        {
            temp = A[i][k];
            A[i][k] = A[pos][k];
            A[pos][k] = temp;
        }    
    }
    print(A, n, 'A');    
}