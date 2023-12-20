#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct process
{
    int pid;
    int at;
    int bt;
    int pri;
    int ct;
    int tat;
    int st;
    int rt;
    int wt;
};

int main()
{
    struct process p[40];
    int n;
    int total_tat;
    int total_wt;
    int total_rt;
    int total_ideal;

    float avg_tat;
    float avg_wt;
    int bt_remain[40];
    printf("Enter n=");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter AT %d=", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter BT %d=", i + 1);
        scanf("%d", &p[i].bt);
        bt_remain[i] = p[i].bt;
        printf("Enter PRI %d=", i + 1);
        scanf("%d", &p[i].pri);
        p[i].pid = i + 1;
    }
    int is_completed[40];
    for (int i = 0; i < n; i++)
    {
        is_completed[i] = 0;
    }
    int completed = 0;
    int curr_time = 0;
    int prev = 0;
    while (completed != n)
    {
        int idx = -1;
        int mn = 9999;//for highest priority mn=INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= curr_time && is_completed[i] == 0)
            {
                if (p[i].pri < mn)//p[i].pri>mn
                {
                    mn = p[i].pri;
                    idx = i;
                }
                if (p[i].pri == mn)
                {
                    if (p[i].at <= p[idx].at)
                    {
                        mn = p[i].pri;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            if(p[idx].bt==bt_remain[idx]){
                p[idx].st=curr_time;
                total_ideal=total_ideal+(p[idx].st-prev);
            }
            bt_remain[idx]-=1;
            curr_time++;
            prev=curr_time;
            if(bt_remain[idx]==0){
                p[idx].ct=curr_time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                p[idx].rt=p[idx].st-p[idx].at;
                is_completed[idx]=1;
                completed++;
                printf(" P[%d] ",p[idx].pid);
            }
        }
        else{
            curr_time++;
        }
    }
      printf("\nPID\tAT\tBT\tCT\tPRI\tTAT\tST\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].pri,p[i].tat,p[i].st,p[i].wt);
    }
	float tatavg,wtavg;
	int s=0,w=0;
	for(int i=0;i<n;i++)
	{
		s=s+p[i].tat;
		w=w+p[i].wt;
	}
	tatavg=(float)s/n;
	wtavg=(float)w/n;
	printf("\nAVG TAT = %f",tatavg);
	printf("\nAVG WT = %f",wtavg);
    return 0;
}
/*Enter n=7
Enter AT 1=0
Enter BT 1=4
Enter PRI 1=2
Enter AT 2=1
Enter BT 2=2
Enter PRI 2=4
Enter AT 3=2
Enter BT 3=3
Enter PRI 3=6
Enter AT 4=3
Enter BT 4=5
Enter PRI 4=1
Enter AT 5=4
Enter BT 5=1
Enter PRI 5=8
Enter AT 6=5
Enter BT 6=4
Enter PRI 6=3
Enter AT 7=11
Enter BT 7=6
Enter PRI 7=2
 P[4]  P[1]  P[7]  P[6]  P[2]  P[3]  P[5] 
PID	AT	BT	CT	PRI	TAT	ST	WT
1	0	4	9	2	9	0	5
2	1	2	21	4	20	19	18
3	2	3	24	6	22	21	19
4	3	5	8	1	5	3	0
5	4	1	25	8	21	24	20
6	5	4	19	3	14	9	10
7	11	6	17	2	6	11	0

AVG TAT = 13.857142
AVG WT = 10.285714*/
