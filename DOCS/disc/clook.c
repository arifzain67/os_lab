#include<stdio.h>
#include<math.h>
#include<limits.h>
void sort(int t[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(t[j]>t[j+1])
			{
				int s=t[j];
				t[j]=t[j+1];
				t[j+1]=s;
			}
		}
	}
}
void cscan(int t[],int s,int e,int h,int n)
{
	int dir,sum=0,m,k,l;
	int p[n+2],t1[n];
	sort(t,n);
	printf("Right = 1 && Left =2\n");
	scanf("%d",&dir);
	if(dir==1)
	{
		m=0;
		for(int i=0;i<n;i++)
		{
			if(t[i]>=h)
			{
				k=i;
				break;
			}
		}
		sum=sum+(t[n-1]-h);
		sum=sum+(t[n-1]-s)+(t[k-1]-s);
		printf("sum = %d",sum);
	}
	else
	{
		m=0;
		p[m]=h;
		for(int i=0;i<n;i++)
		{
			if(t[i]>=h)
			{
				l=i;
			
				break;
			}
		}
		sum=(h-t[0])+(e-t[0])+(e-t[l]);
		printf("sum = %d",sum);
	}
}
int main()
{
	int n=7,s=0,e=200,h=100;
	int t[7]={20,30,50,70,125,145,160};
	cscan(t,s,e,h,n);
}
