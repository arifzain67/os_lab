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
		}/*
		p[m]=h;
		m++;
		for(int i=k;i<n;i++)
		{
			p[m]=t[i];
			m++;
		}
		p[m]=e;
		m++;
		for(int i=k-1;i>=0;i--)
		{
			p[m]=t[i];
			m++;
		}	*/
		sum=sum+e-h;
		sum=sum+e-s;
		sum=sum+t[k-1]-s;
	//	for(int i=0;i<(n+2);i++)
	//	printf("%d ",p[i]);
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
		}/*
		p[m]=h;
		m++;
		for(int i=l-1;i>=0;i--)
		{
			p[m++]=t[i];
		}
		p[m]=s;
		m++;
		for(int i=l;i<=n;i++)
		{
			p[m++]=t[i];
		}	*/	
		sum=(h-0)+(e-s);
		sum=sum+(e-t[l]);
	//	printf("%d",t[k]);
	//	for(int i=0;i<(n+2);i++)
	//	printf("%d ",p[i]);
		printf("sum = %d",sum);
	}
}
int main()
{
	int n=7,s=0,e=200,h=100;
	int t[7]={20,30,50,70,125,145,160};
	cscan(t,s,e,h,n);
}
