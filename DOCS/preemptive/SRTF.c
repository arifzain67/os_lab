#include<stdio.h>
void sort(int n,int AT[],int BT[],int BBT[])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(BT[j]>BT[j+1])
			{
				//swap(&P[j],&P[j+1]);
				swap(&AT[j],&AT[j+1]);
				swap(&BT[j],&BT[j+1]);
				swap(&BBT[j],&BBT[j+1]);
			}
			else if(BT[j]==BT[j+1])
			{
				if(AT[j]>AT[j+1])
				{
					//swap(&P[j],&P[j+1]);
					swap(&AT[j],&AT[j+1]);
					swap(&BT[j],&BT[j+1]);
					swap(&BBT[j],&BBT[j+1]);
				}
			}
		}
	}
}
int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int findmin_AT(int n,int AT[],int V[])
{
	int i,index,min=999;
	for(i=0;i<n;i++)
	{
		if(V[i]!=1 && AT[i]<min)
		{
			min=AT[i];
			index=i;
		}
	}
	return index;
}
int findmin_BT(int n,int t,int AT[],int BT[],int V[])
{
	int i=0,index,min=999,flag=0;
	for(i=0;i<n;i++)
	{
		if(V[i]!=1 && AT[i]<=t)
		{
			if(min>BT[i])
			{
				min=BT[i];
				index=i;
				flag=1;
			}
		}
	}
	if(flag==0)
	{
		return -1;
	}
	else
	{
		return index;
	}
}
int main()
{
	int n,i;
	printf("Enter the No.of Processes: \t");
	scanf("%d",&n);
	int P[n],AT[n],BT[n],CT[n],TAT[n],WT[n],BBT[n],V[100];
	printf("Enter the Arrival Times:  ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&AT[i]);
		P[i]=i+1;
		V[i]=0;
	}
	printf("Enter the Burst Times:  ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&BT[i]);
		BBT[i]=BT[i];
	}
	sort(n,AT,BT,BBT);
	/*printf("\n After Sorting is : \n");
	printf("\n\tPID\tAT\tBT\tBBT");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d\t%d\t%d\t%d",P[i],AT[i],BT[i],BBT[i]);
		printf("\n");
	}*/
	printf("GHANTTCHART IS: \n");
	printf("|0");
	int t=0,j=0,k,l;
	k=findmin_AT(n,AT,V);
	if(AT[k]==0)
	{
		t=AT[k];
		t=t+1;
		printf("|P%d|%d",P[k],t);
		BT[k]=BT[k]-1;
		if(BT[k]==0)
		{
			V[k]=1;
			CT[k]=t;
			TAT[k]=CT[k]-AT[k];
			WT[k]=TAT[k]-BBT[k];
			j++;
		}
	}
	else if(AT[k]!=0)
	{
		t=AT[k];
		printf("|Ideal Time|%d",t);
	}
	while(j<n)
	{
		sort(n,AT,BT,BBT);
		l=findmin_BT(n,t,AT,BT,V);
		if(l!=-1)
		{
			t=t+1;
			printf("|P%d|%d",P[l],t);
			BT[l]=BT[l]-1;
			if(BT[l]==0)
			{
				V[l]=1;
				CT[l]=t;
				TAT[l]=CT[l]-AT[l];
				WT[l]=TAT[l]-BBT[l];
				j++;
			}
		}
		else if(l==-1)
		{
			t=t+1;
			printf("|Ideal Time|%d",t);
		}
	}
	printf("\n\tPID\tAT\tBT\tCT\tTAT\tWT");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d\t%d\t%d\t%d\t%d\t%d",P[i],AT[i],BBT[i],CT[i],TAT[i],WT[i]);
		printf("\n");
	}
	int TATsum=0,WTsum=0;
	for(i=0;i<n;i++)
	{
		TATsum=TATsum+TAT[i];
		WTsum=WTsum+WT[i];
	}
	float TATavg=(float)TATsum/(float)n;
	float WTavg=(float)WTsum/(float)n;
	printf("\n TURN AROUND TIME AVERGE IS :\t%.2f",TATavg);
	printf("\n WAITING TIME AVERGE IS     :\t%.2f",WTavg);
}
/*Enter the No.of Processes: 	6
Enter the Arrival Times:  0 1 2 3 4 5  
Enter the Burst Times:  8 6 5 2 4 1
GHANTTCHART IS: 
|0|P6|1|P5|2|P4|3|P2|4|P1|5|P2|6|P3|7|P3|8|P3|9|P3|10|P4|11|P4|12|P4|13|P4|14|P5|15|P5|16|P5|17|P5|18|P5|19|P6|20|P6|21|P6|22|P6|23|P6|24|P6|25|P6|26
	PID	AT	BT	CT	TAT	WT
	1	1	6	5	2	0
	2	2	5	6	1	0
	3	3	2	10	9	3
	4	4	4	14	10	6
	5	5	1	19	17	12
	6	0	8	26	26	18

 TURN AROUND TIME AVERGE IS :	10.83
 WAITING TIME AVERGE IS     :	6.50*/
