#include<stdio.h>
#include<string.h>

void main()
{
	int array[100],i,j,temp,n;
	printf("ENter the array:");
	scanf("%d",&n);
	printf("enter %d integer\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
		}	
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<i-n-1;j++)
		{
			if(array[i]>array[i+1])
			{
				temp=array[i];
				array[i]=array[i+1];
				array[i+1]=array[i];
			}
		}
	}	
	printf("Sorted list is acesnding order:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",array[i]);
		}	
}
