#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int exchange = 0;

    printf("enter number you want:");
    scanf("%d", &n);

    int data[n];

    for (int i = 0; i < n; i++)
    {
        printf("ENTER NUMBER %d:", i + 1);
        scanf("%d", &data[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                exchange = 1;
                int temp;
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
        if (exchange == 0)
        {
            break;
                }
    }

    printf("SORTED:");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", data[i]);
    }
}