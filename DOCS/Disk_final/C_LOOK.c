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
 while(ch!=0)
 {
 	printf("\n1.Left\n2.Right\n");
 	scanf("%d",&ch);
 	switch(ch)
 	{
 		case 1:left(a,n,head,x);
 		 break;
 		case 2:right(a,n,head,x);
 		break;
 		case 0:
 			break;
 		default:
 			break;
	 }	
 }
}

void right(int a[],int n,int head,int x)
{
	sort(a,n);
		int i,d=0,diff;
	 diff=abs(a[n-1]-head)+abs(a[n-1]-a[0]);
	int max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<head && max<a[i])
		{
			max=a[i];
		}
	}
	int dist=abs(a[0]-max);
	printf("head movements:%d\n",diff+dist);
	printf("%d ",head);
	for(i=0;i<n;i++)
	{
		if(a[i]>head)
		printf("%d ",a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]<head)
		 printf("%d ",a[i]);
	}
}

void left(int a[],int n,int head,int x)
{
	sort(a,n);
	int diff=abs(head-a[0])+abs(a[n-1]-a[0]),i,d=0;
	int min=a[n-1];
	for(i=1;i<n;i++)
	{
	 if(a[i]>head && min>a[i])
	 {
	  min=a[i]; 	
	 }	
	}
	d=a[n-1]-min;
	printf("%d ",d);
	printf("head movements:%d\n",diff+d);
	printf("%d ",head);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<head)
		 printf("%d ",a[i]);
	}
	for(i=n-1;i>=0;i--)
	{
		if(a[i]>head)
		 printf("%d ",a[i]);
	}
}


