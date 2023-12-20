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
void right(int a[],int n,int head,int x)
{
	sort(a,n);
	int diff=abs((x-1)-head),dist=abs((x-1)-0),i,d=0;
	a[-1]=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<head)
		{
			d=d+abs(a[i]-a[i-1]);
		}
	}
	printf("head movements:%d\n",diff+dist+d);
	printf("%d ",head);
	for(i=0;i<n;i++)
	{
		if(a[i]>head)
		printf("%d ",a[i]);
	}
	printf("%d ",x-1);
	printf("%d ",0);
	for(i=0;i<n;i++)
	{
		if(a[i]<head)
		 printf("%d ",a[i]);
	}
}

void left(int a[],int n,int head,int x)
{
	sort(a,n);
	int diff=abs(head-0)+abs((x-1)-0),i,d=0;
	a[5]=(x-1);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]>head)
		d=d+abs(a[i+1]-a[i]);
	}
	printf("%d ",d);
	printf("head movements:%d\n",diff+d);
		printf("%d ",head);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<head)
		 printf("%d ",a[i]);
	}
	printf("%d ",0);
	printf("%d ",(x-1));
	for(i=n-1;i>=0;i--)
	{
		if(a[i]>head)
		 printf("%d ",a[i]);
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
 
 for(i=0;i<n;i++){
 	printf("enter %d track ", i+1,":");
 	 scanf("%d",&a[i]);
 }
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



