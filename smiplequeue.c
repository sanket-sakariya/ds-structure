#include<stdio.h>
#include<conio.h>
#include<process.h>
// #include<dos.h>
// #include<direct.h>

struct queue
{
    int s[10];
    int front;
    int rear;

}q;

void insert(struct queue *q1,int n)
{
    if(q1->rear>=9)
    {
        printf("\n\t The queue is overflow");
        // delay(2000);
        // exit(0);
    }
    else
    {
        q1->rear++;
        q1->s[q1->rear]=n;

    }
    if(q1->front==-1)
    {
        q1->front=0;
    }

}

int deletef(struct queue *q2)
{
    int a;
    if(q2->front==-1)
    {
        printf("\n\t The queue is underflow ");
        // delay(2000);
        exit(0);
    }
    a=q2->s[q2->front];
    if(q2->front==q2->rear)
    {
        q2->front=-1;
        q2->rear=-1;
    }
    else
    {
        q2->front++;
    }
    return a;
}

void display(struct queue *q3)
{
    int i;
    if(q3->front==-1)
    {
        printf("\n\tThe queue is empty");
        // delay(2000);
        exit(0);
    }
    for(int i=q3->front;i<=q3->rear;i++)
{
    printf("The %d element is %d\n",i+1,q3->s[i]);
}
    
}
void main()
{
    int ch,x,y;
    q.front=-1;
    q.rear=-1;

    while(1)
    {
        printf("\n\t1.Insert\n\t2.delet\n\t3.display\n\t4.exit\n");
        printf("\nEnter the choise :");
        scanf("%d",&ch);
        switch(ch)
        {
            
            case 1:
                    printf("\n\tEnter the value of the element :");
                    scanf("%d",&x);
                    insert(&q,x);
                    break;
            case 2:
                    y=deletef(&q);
                    printf("\n\t The deleted element is : %d\n",y);
                    break;
            case 3:
                    display(&q);
                    break;
            case 4:
                    exit(0);                        
        }
    }
}