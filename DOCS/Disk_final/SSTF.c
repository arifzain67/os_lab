#include<stdio.h>
#include<math.h>

void main(){
	int n;
	
	printf("Enter Total No.of Tracks : ");
	scanf("%d",&n);
	int a[] = {176, 79, 34, 60, 92, 11, 41, 114};
	int b[] = {0,0,0,0,0,0,0,0};
	
	printf("Enter Track Sequence : ");
	int i, j, k;
//	for(i= 0 ; i < n ; i ++){
//		scanf("%d",&a[i]);
//	}
	int head = 50;
//	printf("Enter Head : ");
//	scanf("%d",&head);
	int x = head;
	int sumTrack = 0;
	for(i = 0 ; i< n ; i++){
		int min = 99999;
		for(j = 0 ; j < n ; j++){
			if(b[j]!=1 && abs(a[j]- x)<min){
				min = abs(a[j]-x);
				k = j;//
			}
		}
		b[k] = 1;
		x = a[k];
		sumTrack += min;
		
	}
	printf("%d",sumTrack);
	
}
