#include<stdio.h>
void sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
void main()
{
 int n,i,count=0,hm=0,x;
 printf("total no.of.tracks:");
 scanf("%d",&x);
 printf("no.of requested tracks:");
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 int head;
 printf("initial pos of head:");
 scanf("%d",&head);
 sort(a,n);
 int ch;
 printf("enter direction:");
 while(ch!=0)
 {
 	scanf("%d",&ch);
 	switch(ch)
 	{
 		case 1:left(a,n,head,x);
 		 break;
 		case 2:right(a,n,head,x);
 		break;
 		default:
 			break;
	 }	
 }
}

void right(int a[],int n,int head,int x)
{
	sort(a,n);
	int diff=(x-1)-head,i,dist=0;
	if(a[0]<head)
	dist=(x-1)-a[0];
	printf("head movements:%d\n",diff+dist);
	printf("%d ",head);
	for(i=0;i<n;i++)
	{
		if(a[i]>head)
		printf("%d ",a[i]);
	}
	printf("%d ",x-1);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<head)
		 printf("%d ",a[i]);
	}
}

void left(int a[],int n,int head,int x)
{
	sort(a,n);
	int diff=head,i,dist=0;
	if(a[n-1]>head)
	dist=a[n-1]-0;
	printf("head movements:%d\n",diff+dist);
		printf("%d ",head);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<head)
		printf("%d ",a[i]);
	}
	printf("%d ",0);
	for(i=0;i<n;i++)
	{
		if(a[i]>head)
		 printf("%d ",a[i]);
	}
}

