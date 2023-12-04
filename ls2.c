#include<stdio.h>
#include<string.h>

void main()
{
	int i, A[10]  = {30,40,44,56,37,49,23,67,24,45};
	int num,flag=1;
	printf("Enter number want position:");
	scanf("%d",&num);
	
	for (i=0;i<10;i++)
	{
		if (num==A[i])
		{
			flag=0;
			printf("%d position is %d",num,i+1);
			break;
		}
		
	}
	if (flag==1)
	{
		printf("Not found");
	}
	
}