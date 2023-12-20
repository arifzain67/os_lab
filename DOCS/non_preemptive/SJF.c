
#include<stdio.h>
int swap(int i,int j)
{
	int t=i;
	i=j;
	j=t;
}
int sort(int n,int p[],int at[],int bt[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				swap(at[j],at[j+1]);
				swap(p[j],p[j+1]);
				swap(bt[j],bt[j+1]);
			}
		}
	}
}

int findmin(int completion,int n,int at[],int bt[],int v[])
{
	int i=0,index,flag=0,min=9999;
	while(at[i]<=completion && i!=n)
	{
		if(v[i]!=1 && bt[i]<min)
		{
			min=bt[i];
			index=i;
			flag=1;
		
		}
		i++;
	}
	if(flag==0)
	return -1;
	else
	return index;
}
int main()
{	
	int n;
	printf("enter the no of processes:");
	scanf("%d",&n);
	int at[n],p[n],bt[n],ct[n],tat[n],wt[n],v[n];
	printf("enter the arrival and burst time of processes:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	sort(n,p,at,bt);
	printf("Ghantt chart :\n");
	printf("|0");
	int completion=0,min,j=0;
	while(j<n)
	{
		min=findmin(completion,n,at,bt,v);
		if(min!=-1)
		{
			ct[min]=completion+bt[min];
			tat[min]=ct[min]-at[min];
			wt[min]=tat[min]-bt[min];
			v[min]=1;
			completion=ct[min];		
			printf("|p%d|%d",p[min],ct[min]);
			j=j+1;
		}
		else
		{
			completion=completion+1;
			printf("|ideal case|%d",completion);
		}	
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j]>p[j+1])
			{
				swap(p[j],p[j+1]);
				swap(at[j],at[j+1]);
				swap(bt[j],bt[j+1]);
				swap(ct[j],ct[j+1]);
				swap(tat[j],tat[j+1]);
				swap(wt[j],wt[j+1]);
			}
		}
	}
	printf("\n");
	printf("\tProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	printf("\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	int s=0,w1=0;
	for(int i=0;i<n;i++)
	{
		s=s+tat[i];
		w1=w1+wt[i];
	}
	float tatavg=(float)s/n;
	float wtavg=(float)w1/n;
	printf("\navgtat=%f",tatavg);	
	printf("\navgwt=%f",wtavg);
}
/*enter the no of processes:6
enter the arrival and burst time of processes:0 8
1 6
2 5
3 2
4 4
5 1
Ghantt chart :
|0|p1|8|p6|9|p4|11|p5|15|p3|20|p2|26
	Process	AT	BT	CT	TAT	WT
	1	0	8	8	8	0
	2	1	6	26	25	19
	3	2	5	20	18	13
	4	3	2	11	8	6
	5	4	4	15	11	7
	6	5	1	9	4	3

avgtat=12.333333
avgwt=8.000000*/	
