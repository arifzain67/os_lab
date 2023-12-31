#include<stdio.h>
int main()
{
	int n,m,i,j,sum=0,count=0,esum=0;
	printf("Enter the No.of Process: ");
	scanf("%d",&n);
	int P[n],v1[n];
	printf("\nEnter the Process Sizes: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&P[i]);
		v1[i]=0;
	}
	printf("Enter the No.of MemoryBlocks: ");
	scanf("%d",&m);
	int M[m],v[m];
	printf("\nEnter the MemoryBlock Sizes: \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&M[i]);
		v[i]=0;
	}
	for(i=0;i<n;i++)
	{
		sum=sum+FIRSTFIT(i,m,n,v,v1,P,M);
	}
	printf("\nIntegral Fragmentation is : %d",sum);
	for(j=0;j<m;j++)
	{
		if(v[j]!=1)
		{
			count=count+M[j];
		}
	}
	for(i=0;i<n;i++)
	{
		if(v1[i]!=1 && count>P[i])
		{
			if(esum<P[i])
			{
			esum=P[i];
			}	
		}
	}
	printf("\nExternal Fragmentation is : %d",esum);
}
int FIRSTFIT(int i,int m,int n,int v[],int v1[],int P[],int M[])
{
	int j,IF=0,flag=0,index,min=1000;
	for(j=0;j<m;j++)
	{
		if(M[j]>=P[i] && v[j]!=1)
		{
			if(M[j]<min)
			{
				min=M[j];
				index=j;
				flag=1;
			}
		}
	}
	if(flag==1)
	{
		v[index]=1;
		v1[i]=1;
		printf("\nProcess %d is Allocated to MemoryBlock %d:",P[i],M[index]);
		IF=M[index]-P[i];
	}
	else
	{
		printf("\n MemoryBlock is not allocated to %d Process",P[i]);
	}
	return IF;
}
/*Enter the No.of Process: 4

Enter the Process Sizes: 
212
417
112
426
Enter the No.of MemoryBlocks: 5

Enter the MemoryBlock Sizes: 
100
500
200
300
600

Process 212 is Allocated to MemoryBlock 300:
Process 417 is Allocated to MemoryBlock 500:
Process 112 is Allocated to MemoryBlock 200:
Process 426 is Allocated to MemoryBlock 600:
Integral Fragmentation is : 433
External Fragmentation is : 0*/
