#include <stdio.h>
#include <stdlib.h>

void main()
{
	//printf("");
	int n, *min, *max;
	//Inputs
	printf("Enter number of elements for the Array.\n");
	scanf("%d", &n);
	int * A = (int*) malloc(n*sizeof(int));
	min = A;
	max = A;
	printf("Enter an Array of length %d.\n", n);
	for(int i = 0; i<n;i++)
	{   
		printf("A[%d]: ", i);
		scanf("%d", (A+i));
		if((*min)>(*(A+i)))
		{
			min = A+i;
		}
		if((*max)<(*(A+i)))
		{
			max = A+i;
		}	
	}
	//Print Once
	printf("The final Array is: ");
	for(int i = 0; i<n;i++)
	{
		printf("%d ", *(A+i));
	}
	
	//swap min and max values
	int temp = *min;
	*min = *max;
	*max = temp;
	
	//Print Final Array
	printf("\nArray after min and max swapped: ");
	for(int i = 0; i<n;i++)
	{
		printf("%d ", *(A+i));
	}
	printf("/n");
	free(A);
	return;
}
