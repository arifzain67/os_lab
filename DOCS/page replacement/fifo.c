#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>


void main(){
	
	int size;
	printf("Enter the size: ");
	scanf("%d",&size);
	
	int pages[size];
	printf("Enter the pageframes: ");
	int i;
	for(i = 0;i < size; i++){
		scanf("%d",&pages[i]);
	}
	
	int front = -1,rear = -1;
	int q[100];
	
	int pageFaults = 0;
	int frames;
	printf("Enter the number of frames: ");
	scanf("%d",&frames);
	
	for(i = 0; i < size; i++){
		
		if(front == -1){
			front = 0;
			rear = 0;
			q[front] = pages[i];
			pageFaults++;
			printf("page fault at %d\n",pages[i]);
		} else {
			
			bool flag = true;
			int j;
			for(j = front; j <= rear; j++){
				if(pages[i] == q[j]){
					flag = false;
					break;
				}
			}
			
			if(flag){
				
				if(rear - front + 1 < frames){
					q[++rear] = pages[i];
				}	else{
					q[++rear] = pages[i];
					front++;
				}
				
				printf("page fault occured at %d\n",pages[i]);
				pageFaults++;				
			} else{
				
				printf("page hit occured at %d\n",pages[i]);
				
			}
			
		}
		
	}
	
	printf("%d is total number of pagefaults\n",pageFaults);
	
}
