#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,rear=-1,front=0,opt;
	printf("Enter limit ");
	scanf("%d",&n);
	int queue[n];
	do{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
		printf("Enter an option ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				if(rear==n-1){
					printf("QUEUE OVERFLOW\n\n");
				}
				else{
					printf("\n");
					rear++;
					printf("Enter an element ");
					scanf("%d",&queue[rear]);
					printf("%d enqueued at %d\n\n",queue[rear],rear);
				}
				break;
			case 2:
				if(front>rear){
					printf("QUEUE UNDERFLOW\n\n");
				}
				else{
					int a=queue[front];
					printf("%d is dequeued\n\n",a);
					front++;
				}
				break;
			case 3:
				printf("The Elements are :");
				for(int i=front;i<=rear;i++){
					printf("%d  ",queue[i]);
				}
				break;
			case 4:
				printf("Exiting........\n\n");
				exit(0);
			default:
				printf("Invalid Option\n\n");
		}
	}while(opt!=4);
}
