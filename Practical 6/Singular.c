#include <stdio.h>
#define sf scanf
#define pf printf

int Det(int A[10][10], int n);
void print(int A[10][10], int n);

void main()
{
    int n, A[10][10], det;
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

void print(int A[10][10], int n)
{
    pf("\n");
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            pf("%d ",A[i][j]);
        pf("\n");
    }
}
int Det(int A[10][10], int n)
{
    int det, sub[10][10], sign, sum = 0;
    if(n == 1)//A[1x1] is itself a determinant
        sum = A[0][0];
    else if(n == 2)//Standard Determinant for array[2x2]
        sum = (A[0][0] * A[1][1]) - (A[1][0] * A[0][1]);
    else//n>2 Row/Coloumn Deletion Method 
    {
        for(int o = 0; o<n; o++)
        {
            sign = (o%2==0)?1:-1;
            for(int p = 0, a = 1; p<n-1; p++, a++)//p,q take positions in sub-array, a,b take positions in main array
            {
                for(int q = 0, b = 0; q<n-1; q++, b++)
                {
                    if(q == o)
                        b++;
                    sub[p][q] = A[a][b];//Creates a smaller sub-array
                }
            }
            det = Det(sub, n-1);//Finds Determinant of sub-array
            sum+= A[0][o] * sign * det;
        }
    }
    return sum;//Return the final determinant
} 
