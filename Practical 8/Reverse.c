#include <stdio.h>
#include <stdlib.h>
void main()
{
	//printf("");
	int* A, temp, n;
	//Inputs
	printf("Enter number of elements for the Array.\n");
	scanf("%d", &n);
	printf("Enter an Array of length %d.\n", n);
	for(int i = 0; i<n;i++)
	{   
		printf("A[%d]: ", i);
		scanf("%d", (A+i));	
	}
	//Print Once
	printf("The Input Array is: ");
	for(int i = 0; i<n;i++)
		printf("%d ", *(A+i));
	printf("\n");
	int m = (n%2==0)? n/2: (n-1)/2;
	printf("%d", m);
	//Swap the array elements
	for(int i = 0; i<m  ; i++)
	{
	
		temp = *(A+i);
		*(A+i) = *(A+n-1-i);
		*(A+n-1-i) = temp;
	}
	//Print Final Solution
	printf("The final Array is: ");
	for(int i = 0; i<n;i++)
		printf("%d ", *(A+i));
	printf("\n");
	//free(A);
	return;
}