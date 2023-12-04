#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int roll;
    char name[20];
    int marks;
}*first[20];

int i=0;

void insert()
{
    first[i]=(struct student*)malloc(sizeof(struct student));
    printf("\n enter the roll no:");
    scanf("%d",&(first[i]->roll));
    printf("\n enter the name:");
    scanf("%s",&(first[i]->name));
    printf("\n enter the marks:");
    scanf("%d",&(first[i]->marks));
    i++;
}

void search()
{
    int no,j;
    printf("\nenter the roll no:");
    scanf("%d",&no);

    for ( j = 0; j < i; j++)
    {
        if(no == first[j]->roll)
        {
            printf("\n student is found");
        }    
        else
        {
            printf("student is not found");
        }
        
    }
    
}

void update()
{
    int no,j;
    printf("\n enter the roll no:");
    scanf("%d",&no);

    for ( j = 0; j < i; j++)
    {
        if (no == first[j]->roll)
        {
            printf("student is found");
            
        }
    }
    printf("student is not found");
}

void delete()
{
    int del,j,k;
    printf("\n enter the roll no:");
    scanf("%d",&del);

    for ( j = 0; j < i; j++)
    {
        if (del == first[j]->roll)
        {
            for(k=j;k<j;k++)
            {
                first[k]=first[k+1];
                printf("data deleted");
                
            }
        }
        --i;
    }
}

void display()
{
    int j=0;
    for ( j = 0; j < i; j++)
    {
        printf("\n%d\t%s\t%d",first[j]->roll,first[j]->name,first[j]->marks);
    }
}

void sort()
{
    int j,k;
    struct student *temp;
    for( j = 0; j < i; j++)
    {
        for ( k = j+1; k < i; k++)
        {
            if (first[j]->roll > first[k]->roll)
            {
                temp=first[j];
                first[j]=first[k];
                first[k]=temp;

            }
            
        }
        
    }
    
}


int main()
{
    int n;
    do
    {
        printf("\n------------------------------------------");
        printf("\ncreate a student record");
        printf("\nsearch a student record ");
        printf("\nupdate a student record");
        printf("\ndelete a student record");
        printf("\ndisplay a student record");
        printf("\nsort a student record");
        printf("\n------------------------------------------");
        printf("\n enter operation :- ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            insert();
            break;

        case 2:
            search();
            break;    
        
        case 3:
            update();
            break;

        case 4:
            delete();
            break;

        case 5:
            display();
            break;

        case 6:
            sort();
            break;

        default:
            break;
        }
    } while (n!=0);
    return 0;
}