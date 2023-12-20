#include<stdio.h>
#include<math.h>
#include<limits.h>
int main()
{
	int n,s,e,h,hm=0;
	printf("enter the starting and ending of tracks:");
	scanf("%d%d",&s,&e);
	printf("enter the readwrite head position:");
	scanf("%d",&h);
	printf("enter no of  tracks:");
	scanf("%d",&n);
	int t[n];
	printf("enter the tracks:");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&t[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			hm=hm+abs(t[i]-h);
		}
		else
		{
			hm=hm+abs(t[i-1]-t[i]);
		}
	}
	for(int i=0;i<n;i++)
	printf("%d-->",t[i]);
printf("\nhead total movements = %d",hm);
					
}

/*
enter the starting and ending of tracks:0
199
enter the readwrite head position:50
enter no of  tracks:8
enter the tracks:176
79
34
60
92
11
41
114
176-->79-->34-->60-->92-->11-->41-->114-->
head total movements = 510*/
