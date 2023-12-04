#include <stdio.h>
#include <stdlib.h>

int top = -1;
void push();
void pop();
void display();

int main()
{
    int size;
    printf("Enter the size of stack:");
    scanf("%d", &size);

    int stack[size];
    int choise;
    // int i;
    // int x;

    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.exit\n");
        printf("Enter choise:");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            push(stack, size - 1);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choise");
            break;
        }
    }
}

void push(int *arr, int size)
{
    int x;
    if (top >= size)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("New elemnet to be added is :");
        scanf("%d", &x);
        top = top + 1;
        *(arr + top) = x;
    }
}

void pop(int *arr)
{
    if (top == -1)
    {
        printf("Stack is underflow:\n");
    }
    else

    {
        printf("Poped element is %d\n", *(arr + top));
        top = top - 1;
    }
}

void display(int * arr)
{
    if (top==-1)
    {
        printf("Stack is Underflow\n");

    }
    else
    {
        printf("elemnt in stack\n ");
        for (int i=top; i>=0;--i)
        {
            printf("%d\n",*(arr+i));
        }
        
    }
    
}

