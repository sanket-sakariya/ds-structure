#include<stdio.h>
#include<string.h>

int top=-1;
void main()
{
    int stack[n];
    int n,x;
    printf("Enter numvber n:")

    printf("press 1 for push && press 2 for pop");
    scanf("%d",&x);
    switch (x)
    {
    case 1:push();
        
        break;
    case 2:pop();
        break;
    
    default:printf("Not found");
        break;
    }
}
void push(int stack[n])

{
    
    printf("Enter value");
    scanf("%d",&stack[top]);
    
    if(top<n-1)
    {
        if (top < 0)
        {
            stack[0] = vallue ;
            top = 0;

        }
        else
        {
            stack[top+1] = vallue;
            top++;
        }
    }
    else
    {
        printf("Stackoverflow!!!!\n");
    }   
}
