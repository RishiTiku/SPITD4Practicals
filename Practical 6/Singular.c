#include <stdio.h>
#define sf scanf
#define pf printf

int Det(int A[4][4], int n);
void print(int A[4][4], int n);

void main()
{
    int n, A[4][4], det;
    pf("Enter order N of NxN Matrix.\n");
    sf("%d", &n);
    pf("Enter the Matrix.\n");
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            pf("Enter A[%d][%d]: ",i,j);
            sf("%d", &A[i][j]);
        }
    }
    print(A, n);
    det = Det(A, n);
    pf("\n%d", det);
    return;
}

void print(int A[4][4], int n)
{
    pf("\n");
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            pf("%d ",A[i][j]);
        pf("\n");
    }
}
int Det(int A[4][4], int n)
{
    int det, sub[4][4], sign, sum = 0; //det = 2x2, sub stores sub array after r,c deletion, sum stores the det sum
    if(n == 1)
        sum = A[0][0];
    else if(n == 2)
        sum = (A[0][0] * A[1][1]) - (A[1][0] * A[0][1]);
    else
    {
        for(int o = 0; o<n; o++)
        {
            sign = (o%2==0)?1:-1;
            for(int p = 0, a = 1; p<n-1; p++, a++)
            {
                for(int q = 0, b = 0; q<n-1; q++, b++)
                {
                    if(q == o)
                        b++;
                    sub[p][q] = A[a][b];
                }
            }
            det = Det(sub, n-1);
            sum+= A[0][o] * sign * det;
        }
    }
    return sum;
} 

/*int det = 0;
    if(n == 1)
        return A[0][0];
    else if(n == 2)
    {
        det = (A[0][0]*A[1][1])-(A[0][1]*A[1][0]);
    }
    else if(n==3)
    {*/