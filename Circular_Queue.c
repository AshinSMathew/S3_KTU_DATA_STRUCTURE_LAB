#include <stdio.h>
#include <stdlib.h>
int main(){
	int size,front=-1,rear=-1,choice,value;
	printf("Enter the number of elements ");
	scanf("%d",&size);
	int crqueue[size];
	while(1){
		printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter the option ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(front==-1 && rear==-1){
					front=rear=0;
					printf("Enter element ");
					scanf("%d",&value);
					crqueue[rear]=value;
				}
				else if(front==(rear+1)%size){
					printf("Overflow");
				}
				else{
					rear=(rear+1)%size;
					printf("Enter element ");
					scanf("%d",&value);
					crqueue[rear]=value;
				}
				break;
			case 2:
				if(front==-1 && rear==-1){
					printf("Underflow");
				}
				else{
					int data=crqueue[front];
					if(front==rear){
						front=rear=-1;
					}
					else{
						front=(front+1)%size;
					}
					printf("%d Dequeued \n",data);
				}
				break;
			case 3:
				int i=front;
				while(1){
					printf("%d ",crqueue[i]);
					if (i==rear)
						break;
					i=(i+1)%size;
				}
				printf("\n");
				break;
			case 4:
				printf("EXITING.....\n");
				exit(0);
			default:
				printf("Invalid Output\n");
			}
		}
}