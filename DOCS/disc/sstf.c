#include<stdio.h>
#include<math.h>
#include<limits.h>
int main()
{
	int n=7,s=0,e=200,h=100,hm=0;
	int t[7]={20,30,50,70,125,145,160};
	int c=0;
	while(c!=n)
	{
		int min=INT_MAX,d,s;
		for(int i=0;i<n;i++)
		{
			d=abs(t[i]-h);
				if(min>d)
				{
					min=d;
					s=i;
				}
		}
		hm=hm+min;
		h=t[s];
		t[s]=INT_MAX;
		c++;
	}
printf("head total movements = %d",hm);
					
}
