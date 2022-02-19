#include <stdio.h>

void print(int A[], int n, int x, int y);
void SelectionSort(int A[], int n);
void BinarySearch(int A[], int n);

void main()
{
    int n;
    printf("Input a number for Array Elements. \n");
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++)
    {
        printf("Enter element %d. \n", i+1);
        scanf("%d", &A[i]);
    }
    SelectionSort(A, n);
    BinarySearch(A, n);
}

void BinarySearch(int A[], int n)
{
    int search, mid, first = 0, final = n-1;
    printf("Enter the value to be searched.\n");
    scanf("%d", &search);
    while(first<=final)
    {
        mid = (int)  (first + final)/2;
        if(A[mid]==search)
        {
            printf("Search Element (%d) found at index(%d) and position(%d) for Array = ",search ,mid, mid+1);
            print(A,n,-1,mid);
            return;
        }
        else if(A[mid]>search)
            final = mid-1;
        else
            first = mid+1;
    }
    printf("Search Element (%d) not found in the Array = ", search);
    print(A,n,-1,-1);
}

void SelectionSort(int A[], int n)
{
    int min, pos, i, j;
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
        if(i == x)
            printf("^ ");
        else if(i == y)
            printf("* ");
        else
            printf("  ");
    }
    printf("\n");
}