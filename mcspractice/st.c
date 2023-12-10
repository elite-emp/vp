#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,n,a[20],min,total=0,head;
	printf("Enter no of element:\n");
	scanf("%d",&n);
	printf("Enter element:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter head:\n");
	scanf("%d",&head);
	
	printf("Display Disk Order:\n");
	printf("%d\n",head);
	for(i=0;i<n;i++)
	{
		min=2000;
		for(j=0;j<n;j++)
		{
			if(min>=abs(head-a[j]) && a[j]!=-1)
			{
				min=abs(head-a[j]);
				k=j;
			}
		}
		total=total+min;
		head=a[k];
		a[k]=-1;
		printf("%d\n",head);
	}
	printf("Total Head Movement:%d\n",total);
}
