#include <stdio.h>
void toh(int n, char source, char destination, char helper)
{
    if (n == 0)
        return;

    toh(n - 1, source, helper, destination);
        printf("\nMove disc %d from tower %c to tower %c ", n, source, destination);
    toh(n - 1, helper, destination, source);
}

int main()
{
    int n;
    printf("Enter number of disc :");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}