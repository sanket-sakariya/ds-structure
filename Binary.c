#include <stdio.h>

int main()
{
    int n;

    printf("Enter num want to enter:");
    scanf("%d", &n);

    int A[n];

    printf("Enter number:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (A[i] > A[j])
            {
                int temp;

                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    printf("\nSorted:");

    for (int i = 0; i < n; i++)
    {
        printf("%d,", A[i]);
    }

    int key;
    printf("\nEnter want find:");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = (low + high) / 2;

        if (A[mid] == key)
        {
            printf("%d is found at %d", key, mid + 1);
            break;
        }
        else if (A[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return 0;
}