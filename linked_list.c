#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* head=NULL;
struct node* CreateNode(int value){
	struct node* new_node=(struct node*) malloc(sizeof(struct node));
	new_node->data=value;
	new_node->link=NULL;
	return new_node;
}
int InsertAtBeginning(int item){
	struct node* temp=CreateNode(item);
	if(temp==NULL)
		printf("Insertion is not possibNNle\n");
	temp->link=head;
	head=temp;
	printf("%d entered at Beginning\n\n",item);
}
int InsertAtEnd(int item){
	struct node* temp=CreateNode(item);
	struct node *ptr=head;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}
	ptr->link=temp;
	printf("%d entered at End\n\n",item);
}
int InsertAtPosition(int element,int pos){
	struct node* temp=CreateNode(element);
	struct node* ptr=head;
	for(int i=1;i<pos-1;i++){
		ptr=ptr->link;
	}
	temp->link=ptr->link;
	ptr->link=temp;
	printf("%d entered at %d\n\n",element,pos);
}
void DeleteFromBeginning(){
	struct node *ptr=head;
	if(head==NULL){
		printf("Element not found\n");
	}else{
		head=ptr->link;
		free(ptr);
		printf("Element deleted from Beginning\n\n");
	}
}
void DeleteFromEnd(){
	struct node *ptr=head;
	struct node *temp=ptr;
	if(head==NULL){
		printf("Element not found\n");
	}
	else if(head->link==NULL){
		free(head);
		printf("Element DELETED\n");
	}else{
		while(ptr->link!=NULL){
			temp=temp->link;
			if(temp->link!=NULL){
				ptr=ptr->link;
			}else{
				ptr->link=NULL;
				free(temp);
			}
		}
		printf("Element DELETED from End\n");
	}
	
}
void DeleteFromPosition(int position){
	struct node *ptr=head;
	struct node *temp;
	for(int i=1;i<position-1;i++){
		ptr=ptr->link;
	}
	temp=ptr->link;
	ptr->link=temp->link;
	free(temp);
	printf("Element at position %d DELETED\n\n",position);
}
void display(){
	struct node* ptr=head;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->link;	
	}
	printf("null\n\n");
}
int main(){
	printf("LINKED LIST\n\n");
	int opt,element,pos;
	do{
		printf("Options\n");
		printf("\t1.Insert At Beginning\n\t2.Insert At End\n\t3.Insert At A Position\n\t4.Delete At Beginning\n\t5.Delete From End\n\t6.Delete from Position\n\t7.Display\n\t8.Exit\n\n");
		printf("Enter an Option ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter the element to Insert At Beginning: ");
				scanf("%d",&element);
				InsertAtBeginning(element);
				break;
			case 2:
				printf("Enter the element to Insert At End: ");
				scanf("%d",&element);
				InsertAtEnd(element);
				break;
			case 3:
				printf("Enter the element: ");
				scanf("%d",&element);
				printf("\nEnter the position: ");
				scanf("%d",&pos);
				InsertAtPosition(element,pos);
				break;
			case 4:
				DeleteFromBeginning();
				break;
			case 5:
				DeleteFromEnd();
				break;
			case 6:
				printf("Enter the position for deletion: ");
				scanf("%d",&pos);
				DeleteFromPosition(pos);
				break;
			case 7:
				printf("Linked List\n");
				display();
				break;	
			case 8:
				printf("Exiting........\n");
				exit(0);
				break;
			default:
				printf("Invalid Input\n");
				break;
		}
	}while(opt!=8);	
}
