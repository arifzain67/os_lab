#include<stdio.h>
int f(int i,int n,int m,int p[],int b[],int v[],int v1[])
{
	int c=0,flag=0;
	for(int j=0;j<m;j++)
	{
		if(b[j]>=p[i] && v[j]!=1)
		{
			v1[i]=1;
			v[j]=1;
			flag=1;
			printf("\nprocess %d allocated %d",p[i],b[j]);
			c=b[j]-p[i];
			break;
		}
	}
	if(flag==0)
	{
	printf("\nnot  allocated %d",p[i]);
	}
	return c;
}
	
int main()
{
	int n,esum=0,sum=0,count=0;
	printf("enter the no of process:");
	scanf("%d",&n);
	int p[n],v1[n];
	printf("enter the process sizes:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		v1[i]=0;
	}
	int m;
	printf("enter the no of memory blocks:");
	scanf("%d",&m);
	int b[m],v[m];
	printf("enter the memory sizes:");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		v[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		sum=sum+f(i,n,m,p,b,v,v1);
	}
	printf("\ninternal fragmentation = %d",sum);
	for(int i=0;i<m;i++)
	{
		if(v[i]!=1)
		count=count+b[i];
	}
	for(int i=0;i<n;i++)
	{
		if(v1[i]!=1 && p[i]<=count)
		{
			if(esum<p[i])
			esum=p[i];
		}
	}
	printf("\nexternal fragmentation = %d",esum);
}
		
/*enter the no of process:4
enter the process sizes:212
417
112
426
enter the no of memory blocks:5
enter the memory sizes:100
500
200
300
600

process 212 allocated 500
process 417 allocated 600
process 112 allocated 200
not  allocated 426
internal fragmentation = 559
external fragmentation = 0*/
	
