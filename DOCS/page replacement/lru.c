#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

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
	
	int top = -1;
	int stk[frames];
	int pageFaults = 0;
	
	for(i = 0; i < size; i ++){
		
		if(top == -1){
			
			top ++;
			stk[top] = pages[i];
			pageFaults ++;
			
			printf("Page fault at %d\n",pages[i]);
			
		} else {
			
			bool flag = true;
			int j;
			for(j = 0; j <= top; j++){
				
				if(stk[j] == pages[i]){
					flag = false;
					break;
				}
				
			}
			
			if(flag){
				
				if(top + 1 < frames){
					top ++;
					stk[top] = pages[i];
				} else{
					
					for(j = 1; j <= top; j++){
						stk[j - 1] = stk[j];
					}
					
					stk[top] = pages[i];
					
				}
				pageFaults ++;
				printf("Page fault at %d\n",pages[i]);
				
			} else{
				
				int newstk[frames];
				int ind = 0;
				
				for(j = 0; j <= top; j++){
					
					if(stk[j] != pages[i]){
						newstk[ind ++] = stk[j];
					}
					
				}
				
				
				for(j = 0; j < top; j++){
					
					stk[j] = newstk[j];
					
				}
				
				stk[top] = pages[i];
				
				printf("Page hit at %d\n",pages[i]);
				
			}
			
		}
		int j;
		for(j = 0; j <= top; j++){
			printf("%d ",stk[j]);
		}
		printf("\n");
		
	}
	
	printf("total number of pagefaults is %d",pageFaults);
	
}
