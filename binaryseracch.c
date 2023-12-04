#include <stdio.h>
#include <string.h>

int main()
{

    int A[8] = {2, 4, 6, 8, 10, 12, 14, 16};
    
    int low = 0;
    int high =8;
    int key;
    int mid;
    mid = (low + high) / 2;
    printf("Enter key:");
    scanf("%d", &key);
    while (low<=mid)
    {
        mid = (low + high) / 2;
        if (A[mid] == key)
        {
            return key;
        }
        else if (A[mid] > key)
        {
            high = mid - 1;
        }
        else if (A[mid] < key)
        {
            low = mid + 1;
        }
    }
    printf("Not found");
}