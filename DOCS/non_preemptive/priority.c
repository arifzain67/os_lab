
#include<stdio.h>
int swap(int i,int j)
{
	int t=i;
	i=j;
	j=t;
}
int sort(int n,int p[],int at[],int bt[],int pr[])
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
				swap(pr[j],pr[j+1]);
			}
		}
	}
}

int findmin(int completion,int n,int at[],int bt[],int v[],int pr[])
{
	int i=0,index,flag=0,min=9999;//this code is for lowest number highest priority
	//for highest num high priority min=-999,
	while(at[i]<=completion && i!=n)
	{
		if(v[i]!=1 && pr[i]<min)//pr[i]>min
		{
			min=pr[i];
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
	int at[n],p[n],bt[n],ct[n],tat[n],wt[n],v[n],pr[n];
	printf("enter the arrival and burst time and priorities of processes:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		scanf("%d",&pr[i]);
		p[i]=i+1;
	}
	sort(n,p,at,bt,pr);
	printf("Ghantt chart :\n");
	printf("|0");
	int completion=0,min,j=0;
	while(j<n)
	{
		min=findmin(completion,n,at,bt,v,pr);
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
			
/*enter the no of processes:5
enter the arrival and burst time and priorities of processes:0 4 2
1 3 3
2 1 4
3 5 5
4 2 5
Ghantt chart :
|0|p1|4|p2|7|p3|8|p4|13|p5|15
	Process	AT	BT	CT	TAT	WT
	1	0	4	4	4	0
	2	1	3	7	6	3
	3	2	1	8	6	5
	4	3	5	13	10	5
	5	4	2	15	11	9

avgtat=7.400000
avgwt=4.400000*/
	
