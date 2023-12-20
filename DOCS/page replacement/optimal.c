#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

void main(){
	
	int size;
	printf("Enter the number of pages: ");
	scanf("%d",&size);
	
	int pages[size];
	printf("Enter the pages: ");
	int i;
	for(i = 0; i < size; i++){
		scanf("%d",&pages[i]);
	}
	
	int frames;
	printf("Enter the number of frames: ");
	scanf("%d",&frames);
	
	int pageFaults = 0;
	int arr[frames];
	int ind = -1;
	int front = -1;
	
	for(i = 0; i < size; i++){
		
		if(ind == -1){
			
			front = 0;
			ind ++;
			arr[ind] = pages[i];
			pageFaults ++;
			printf("pagefault at %d\n",pages[i]);
			
		} else{
			
			bool flag = true;
			int j;
			
			for(j = 0; j <= ind; j++){
				
				if(arr[j] == pages[i]){
					flag = false;
					break;
				}
				
			}
			
			if(flag){
				
				if(ind + 1 < frames){
					ind ++;
					arr[ind] = pages[i];
				} else{
					
					int dist[frames];
					
					for(j = 0; j < frames; j++){
						int k;
						int min = INT_MAX;
						for(k = i + 1; k < size; k ++){
								
								if(pages[k] == arr[j]){
									min = k - i + 1;
									break;
								} 
								
						}
						dist[j] = min;
					}
				
					int val = -1;
					int max = INT_MIN;
					
					for(j = 0; j < frames; j++){
						
						if(dist[j] > max){
							val = j;
							max = dist[j];
						}
						
					}
					
					if(val == -1){
						arr[front] = pages[i];
						front ++;
						front %= frames;
					} else{
						arr[val] = pages[i];
					}
				}
			
				pageFaults++;
				printf("page fault occured at %d\n",pages[i]);
			
			
			} else {
				
				printf("page hit occured at %d\n",pages[i]);
				
			}
		
		}
		int j;
		for(j = 0; j <= ind; j++){
			printf("%d ",arr[j]);
		
		}
		printf("\n");
		
	}
	
	
	printf("Total pageFaults is %d",pageFaults++);
}
