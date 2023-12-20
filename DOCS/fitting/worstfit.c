#include<stdio.h>
int first(int i,int n,int m,int v[],int v1[],int p[],int b[])
{
	int index=0,flag=0,min=0,IF=0;
	for(int j=0;j<m;j++)
	{
		if(b[j]>=p[i] && v[j]!=1)
		{
			if(b[j]>min)
			{
				min=b[j];
				index=j;
				flag=1;
				}
			}
		}
		if(flag==1)
		{
			v[index]=1;
			v1[i]=1;
			printf("\nProcess %d is Allocated to MemoryBlock %d:",p[i],b[index]);
			IF=b[index]-p[i];
	}
	else
	{
		printf("\nMemoryBlock is not allocated to %d Process",p[i]);
	}
	return IF;
}
			
int main()
{
	int n,esum=0,sum=0,count=0;
	printf("enter the no of process:");
	scanf("%d",&n);
	int p[n],v1[n];
	printf("ente the sizes of process:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		v1[i]=0;
	}
	int m;
	printf("enter the no of memory blocks:");
	scanf("%d",&m);
	int b[m],v[m];
	printf("ente the sizes of process:");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		v[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		sum=sum+first(i,n,m,v,v1,p,b);
	}
	printf("\ninternal frag = %d",sum);
	for(int i=0;i<m;i++)
	{
		if(v[i]!=1)
		{
			count=count+b[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(v1[i]!=1 && p[i]<=count)
		{
			if(esum<p[i])
			{
				esum=p[i];
			}
		}
	}
	printf("\nexternal frag = %d",esum);
}
	/*enter the no of process:4
ente the sizes of process:212
417
112
426
enter the no of memory blocks:5
ente the sizes of process:100
500
200
300
600

Process 212 is Allocated to MemoryBlock 600:
Process 417 is Allocated to MemoryBlock 500:
Process 112 is Allocated to MemoryBlock 300:
MemoryBlock is not allocated to 426 Process
internal frag = 659
external frag = 0*/
	
