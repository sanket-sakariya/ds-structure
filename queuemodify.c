#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int r;
    int f;
    int *arr;
} q;

int isEmpty(struct queue *q)
{
    return q->r == q->f;
}

int isFull(struct queue *q)
{
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        a = q->arr[++q->f];
    }
    return a;
}

void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("\n\tThe queue is empty");
    }
    else
    {
        for (int i = q->f; i <= q->r; i++)
        {
            printf("The %d element is %d\n", i + 1, q->arr[i]);
        }
    }
}

int main()
{
    int n;
    int ch, val, y;
    printf("Enter the size of queue:");
    scanf("%d", &n);

    q.size = n;
    q.r = -1;
    q.f = 0;
    q.arr = (int *)malloc(n * sizeof(int));

    while (1)
    {
        printf("\n\t1.Enqueue\n\t2.dequeue\n\t3.display\n\t4.exit\n");
        printf("\nEnter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n\tEnter the value of the element :");
            scanf("%d", &val);
            enqueue(&q, val);
            break;
        case 2:
            y = dequeue(&q);
            if (y != -1)
            {
                printf("\n\t The deleted element is : %d\n", y);
            }
            break;
        case 3:
            display(&q);
            break;
        case 4:
            free(q.arr);
            exit(0);
        }
    }
}