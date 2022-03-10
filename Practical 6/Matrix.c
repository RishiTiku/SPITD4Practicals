#include <stdio.h>
 
void input(int A[100][100], int m, int n, char name);
void print(int A[100][100], int m, int n, char name);
void matrixMultiply(int A[100][100], int B[100][100], int a, int n, int b);//A=a*n, B = n*b
void printTranspose(int A[100][100], int a, int b, char name);

void main()
{
    //Variables
    int am, an, bm, bn, A[100][100], B[100][100];
    //Input
    printf("[+] Enter Order of First Matrix A in (Form: m n)\n");
    scanf("%d %d", &am, &an);
    printf("[+] Enter Order of First Matrix B in (Form: m n)\n");
    scanf("%d %d", &bm, &bn);
    input(A, am, an, 'A');
    input(B, bm, bn, 'B');
    print(A, am, an, 'A');
    print(B, bm, bn, 'B');
    //Operations
    if(an != bm)
        printf("[-] Can't Perform Matrix Multiplication.\n");
    else
        matrixMultiply(A, B, am, an, bn);
    printTranspose(A,am,an, 'A');
    printTranspose(B,bm,bn, 'B');
}

void input(int A[100][100], int m, int n, char name)
{
    printf("[+] Input Array %c[%d][%d].\n",name , m, n);
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("Element[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void print(int A[100][100], int m, int n, char name)
{
    printf("\n[+] Array %c[%d][%d]:\n",name , m, n);
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
}

void matrixMultiply(int A[100][100], int B[100][100], int a, int n, int b)
{
    int C[100][100], sum = 0;
    for(int i = 0; i<a; i++) //C[i][j] = A[i][x] * B[x][j]
    {
        for(int j = 0; j<b;j++)
        {
            for(int x = 0; x<n; x++)
                sum+=A[i][x]*B[x][j];
            C[i][j] = sum;
            sum = 0;
        }
    }
    print(C, a, b, 'C');
} 

void printTranspose(int A[100][100], int a, int b, char name)
{
    printf("\n[+] Transpose of Array %c[%d][%d]:\n", name, a, b);
    for(int i = 0; i<b; i++)
    {
        for(int j = 0; j<a; j++)
            printf("%d\t", A[j][i]);
        printf("\n");
    }
}