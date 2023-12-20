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
	int i=0,index,flag=0;
	while(at[i]<=completion && i!=n)
	{
		if(v[i]!=1)
		{
			index=i;
			flag=1;
			break;
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
		v[i]=0;
	}
	sort(n,p,at,bt);
	printf("Ghantt chart :\n");
	printf("|0");
	int completion=0,min,j=0;
	if(at[0]!=0)
	{
		completion=at[0];
		printf("|ideal time|");
	}
	else if(at[0]==0)
	{
		ct[0]=at[0]+bt[0];
		tat[0]=ct[0]-at[0];
		wt[0]=tat[0]-bt[0];
		completion=ct[0];
		v[0]=1;
		j++;
		printf("|p%d|%d",p[0],ct[0]);
	}
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
	int s=0,w=0;
	for(int i=0;i<n;i++)
	{
		s=s+tat[i];
		w=w+wt[i];
	}
	float tatavg=(float)s/n;
	float wtavg=(float)w/n;
	printf("\navgtat=%f",tatavg);	
	printf("\navgwt=%f",wtavg);		
}
	/*enter the no of processes:5
enter the arrival and burst time of processes:4 2
10 1
15 2
20 3
28 8
Ghantt chart :
|0|ideal time||p1|6|ideal case|7|ideal case|8|ideal case|9|ideal case|10|p2|11|ideal case|12|ideal case|13|ideal case|14|ideal case|15|p3|17|ideal case|18|ideal case|19|ideal case|20|p4|23|ideal case|24|ideal case|25|ideal case|26|ideal case|27|ideal case|28|p5|36
	Process	AT	BT	CT	TAT	WT
	1	4	2	6	2	0
	2	10	1	11	1	0
	3	15	2	17	2	0
	4	20	3	23	3	0
	5	28	8	36	8	0

avgtat=3.200000
avgwt=0.000000*/
