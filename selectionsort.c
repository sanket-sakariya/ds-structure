#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *A, int n)
{
    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}

void selectionsort(int *A, int n)
{
    int pass,temp;
    printf("Running selection sort......!\n");
    for (int i = 0; i < n-1; i++)
    {
        pass=i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j]<A[pass])
            {
                pass=j;

            }
        }
        temp=A[i];
        A[i]=A[pass];
        A[pass]=temp;
        
    }
    
}
int main()
{
    int n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number at index %d:",i+1);
        scanf("%d", &A[i]);
    }
    selectionsort(A, n);
    printArray(A, n);
    return 0;
}