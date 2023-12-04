#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}
void insertionsort(int *A, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // Loop for passes
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) // loop for each pass
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{

    // int A[] = {12, 54, 65, 7, 23, 9};
    // int n = 6;
    int n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number at index %d:", i + 1);
        scanf("%d", &A[i]);
    }

    insertionsort(A, n);
    printArray(A, n);

    return 0;
}