#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *A, int n)
{
    printf("Running Quicksort.......\n");
    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}
int partision(int A[], int low, int high)
{
    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    // swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quicksort(int A[], int low, int high)
{
    int partistionindex; // Index of pivot after partision
    if (low < high)
    {
        partistionindex = partision(A, low, high);
        quicksort(A, low, partistionindex - 1);  // sort left sub array
        quicksort(A, partistionindex + 1, high); // sort right sub array
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
        printf("Enter the number at index %d:", i + 1);
        scanf("%d", &A[i]);
    }
    quicksort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}
