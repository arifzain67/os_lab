#include<stdio.h>
	int n,r;
	int allocation[100][100],max[100][100],need[100][100],available[100];
int check(int i,int n,int r,int work[])
{
	int flag=-1;
	for(int j=1;j<=r;j++)
	{
		if(work[j]<need[i][j])
		{
			flag=1;
			break;
		}
	}
	return flag;
}
int printing(int sequence[])
{
	for(int i=1;i<=n;i++)
	{
		printf("p%d\t",sequence[i]);
	}
	printf("\n");
}


int Safety_sequence(int sequence[],int finish[],int work[],int k)
{
	if(k>n)
	{
		printing(sequence);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		int p=check(i,n,r,work);
		if(p==-1 && finish[i]==-1)
		{
			sequence[k]=i;
			finish[i]=1;
			for(int j=1;j<=r;j++)
			{
				work[j]=work[j]+allocation[i][j];
			}
			Safety_sequence(sequence,finish,work,k+1);
			for(int j=1;j<=r;j++)
			{
				work[j]=work[j]-allocation[i][j];
			}
			finish[i]=-1;
		}
	}
}
int main()
{
	printf("enter the no of processes:");
	scanf("%d",&n);
	printf("enter the no of resources:");
	scanf("%d",&r);
	int finish[n],work[r],sequence[n];
	printf("enter the allocation of matrix:\n");
	for(int i=1;i<=n;i++)
	{
		finish[i]=-1;
		for(int j=1;j<=r;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	
	printf("enter the max matrix:\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=r;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	printf("enter the available instances:");
	int k=1;
	for(int i=1;i<=r;i++)
	{
		scanf("%d",&available[i]);
		work[i]=available[i];
	}
	printf("these are the possible sequences:\n");
	Safety_sequence(sequence,finish,work,k);
}
		
/*
enter the no of processes:4
enter the no of resources:3
enter the allocation of matrix:
2 1 0
1 2 2
0 2 0
3 0 1
enter the max matrix:
8 6 3
9 4 3
5 3 3
4 2 3
enter the available instances:4 3 2
these are the possible sequences:
p4	p3	p1	p2	
*/	
	
	
	
	
	
	
