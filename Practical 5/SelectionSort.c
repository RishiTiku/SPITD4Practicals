#include <stdio.h>

void print(int A[], int n, int x, int y);

void main()
{
    int n , min, pos, i, j;
    printf("Input a number for Array Elements. \n");
    scanf("%d", &n);
    int A[n];
    for(i = 0; i<n; i++)
    {
        printf("Enter element %d. \n", i+1);
        scanf("%d", &A[i]);
    }
    printf("Unsorted array A[%d] = ", n);
    print(A,n,-1,-1);
    for(i = 0; i<n-1; i++)
    {
        min = A[i];
        pos = i;
        for(j = i; j<n; j++)
        {
            if(A[j]<min)
            {
                min = A[j];
                pos = j;
            }
        }
        A[pos] = A[i];
        A[i] = min;
        printf("Step %d = ", i+1);
        print(A,n,i,pos);
    }
    printf("Sorted array A[%d] = ", n);
    print(A,n,-1,-1);
}

void print(int A[], int n, int x, int y)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d", A[i]);
        if(i == x||i==y)
            printf("* ");
        else
            printf("  ");
    }
    printf("\n");
}