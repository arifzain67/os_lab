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
void scan(int t[],int s,int e,int h,int n)
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
			if(t[i]>h)
			{
				k=i;
				break;
			}
		}
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
		}	
		sum=sum+e-h;
		sum=sum+e-t[0];
		for(int i=0;i<(n+2);i++)
		printf("%d--> ",p[i]);
		printf("\nsum = %d",sum);
	}
	else
	{
		m=0;
		p[m]=h;
		for(int i=0;i<n;i++)
		{
			if(t[i]>h)
			{
				l=i;
				break;
			}
		}
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
		}		
		sum=(h-0)+(t[n-1]-0);
		for(int i=0;i<(n+2);i++)
		printf("%d--> ",p[i]);
		printf("\nsum = %d",sum);
	}
}
int main()
{
	int s,e,h,n;
	printf("enter the starting and ending track of disks:");
	scanf("%d%d",&s,&e);
	printf("enter the readwrite head position:");
	scanf("%d",&h);
	printf("enter the no of disks:");
	scanf("%d",&n);
	int t[n],t1[n];;
	printf("enter the disks of the track:");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&t[i]);
	t1[i]=t[i];
	}
	int k,p[n+2];
	scan(t,s,e,h,n);
}
/*enter the starting and ending track of disks:0
199
enter the readwrite head position:50
enter the no of disks:8
enter the disks of the track:176
79
34
60
92
11
41
114
Right = 1 && Left =2
2
50 41 34 11 0 60 79 92 114 176 
sum = 226*/
