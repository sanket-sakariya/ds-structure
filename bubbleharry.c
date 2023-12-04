#include <stdio.h>
#include <string.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}

void bubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for no of pass
    {
        for (int j = 0; j < n - i - 1; j++) // for no of comparisions in each pass
        {
            if (A[j] > A[j + 1])
            {

                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the size of Array:");
    scanf("%d",&n);
    int A[n];
    for (int  i = 0; i < n; i++)
    {
        printf("Enter the number %d :",i+1);
        scanf("%d",&A[i]);
    }

    // printf("Before sorting the array:\n");
    // printArray(A, n);     // Printing array brfor sorting
    bubbleSort(A, n); // fubnction to sort the array
    printf("After sorting the array:\n");
    printArray(A, n);  // printing array after sorting
    return 0;
}
