#include <stdio.h>

void print(int A[], int n, int x);
void InsertDelete(int A[], int n);

void main()
{
    int n;
    printf("Input a number for Array Elements. \n");
    scanf("%d", &n);
    int A[n+1];
    for(int i = 0; i<n; i++)
    {
        printf("Enter element %d. \n", i+1);
        scanf("%d", &A[i]);
    }
    print(A, n, -1);
    InsertDelete(A, n);
}

void InsertDelete(int A[], int n)
{
    int ele, pos;
    printf("\n\nEnter element to be inserted. \n");
    scanf("%d", &ele);
    printf("Enter position (index+1). \n");
    scanf("%d", &pos);
    if(pos<1||pos>n+1)
    {
        printf("Position out of bounds. Cannot Insert.\n");
        return;
    }
    else 
    {
        for(int i = n+1; i>=pos; i--)
            A[i] = A[i-1];
        A[pos-1] = ele;
        print(A, n+1, pos-1);
    }
    printf("Enter position (index+1) to be deleted. \n");
    scanf("%d", &pos);
    if(pos<1||pos>n+1)
    {
        printf("Position out of bounds. Cannot Delete.\n");
        return;
    }
    else 
    {
        for(int i = pos-1; i<=n; i++)
            A[i] = A[i+1];
        print(A, n, -1);
    }
}

void print(int A[], int n, int x)
{
    printf("Array A = ");
    for(int i = 0; i<n; i++)
    {
        printf("%d", A[i]);
        if(i == x)
            printf("^ ");
        else
            printf("  ");
    }
    printf("\n");
}