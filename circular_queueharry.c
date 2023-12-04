#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularqueue *q)
{
    if (q->f == (q->r + 1) % q->size)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct circularqueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularqueue q;
    q.size = 3;
    q.f = q.r = 0; // A space reserve for 0 in the circular queue so we can add only number size -1
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
   
    //  enqueue(&q, 45);
    // enqueue(&q, 45);
    // enqueue(&q, 45);

    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(&q))
    {
        printf("Queue is full\n");
    }

    return 0;
}
