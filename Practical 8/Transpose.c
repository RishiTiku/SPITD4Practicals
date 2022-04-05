#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

void Input(int ** A, int m, int n);
void Print(int ** A, int m, int n);
void PrintTranspose(int ** A, int m, int n);

void main()
{
    int m, n;
    pf("Enter the dimensions of the matrix. (2 Integers)\n");
    sf("%d%d", &m, &n);
    int** A = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        A[i] = (int*)malloc(n * sizeof(int));
    //Input(A, m, n);
    for(int i = 0; i<m*n; i++)
    {
        pf("Input Element A[%d][%d]: ", i/n, i%n);
        sf("%d", (A+i));
    }
    Print(A, m, n);
    PrintTranspose(A, m, n);
}


void Print(int ** A, int m, int n)
{
    for(int i = 0; i<m*n; i++)
    {
        if(i%n == 0)
            pf("\n");
        pf("%d ", *(A+i));
    }
    pf("\n");
}

void PrintTranspose(int ** A, int m, int n)
{
    pf("Transpose\n");
    int** Arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        Arr[i] = (int*)malloc(n * sizeof(int));
    for(int j = 0, counter = 0; j<n; j++)
    {
        for(int i = j; i < m*n; i+=n)
        {
            *(Arr+counter) = *(A+i);
            counter++;
        }
    }
    Print(Arr, n, m);
}





