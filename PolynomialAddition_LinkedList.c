#include <stdio.h>
#include <stdlib.h>
struct node{
	int coef;
	int expo;
	struct node* link;
}p1,p2,result;
struct node *head=NULL;
struct node* CreateNode(int c,int e){
	struct node* new_node=(struct node*) malloc(sizeof(struct node));
	new_node->coef=c;
	new_node->expo=e;
	new_node->link=NULL;
	return new_node;
}
void InsertNode(struct node** head, int coef,int expo){
	struct node* newnode=CreateNode(coef,expo);
	if(*head==NULL){
		newnode->link=*head;
		*head=newnode;
		return;
	}
	struct node *temp=*head;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link=newnode;
}
struct node* addPoly(struct node* p1,struct node* p2){
	struct node* result=NULL;
	while(p1!=NULL & p2!=NULL){
		if(p1->expo == p2->expo){
			InsertNode(&result,p1->coef+p2->coef, p1->expo);
			p1=p1->link;
			p2=p2->link;
		}
		else if(p2->expo > p1->expo){
			InsertNode(&result,p2->coef,p2->expo);
			p2=p2->link;
		}else{
			InsertNode(&result,p1->coef,p1->expo);
			p1=p1->link;
		}
	}
	while(p1!=NULL){
		InsertNode(&result,p1->coef,p1->expo);
		p1=p1->link;
	}
	while(p2!=NULL){
		InsertNode(&result,p2->coef,p2->expo);
		p2=p2->link;
	}
	return result;
}
struct node* InputPoly(struct node** poly){
	int n,c,e;
	printf("Enter number of terms: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter Coefficient (%d): ",i+1);
		scanf("%d",&c);
		printf("Enter Exponent (%d): ",i+1);
		scanf("%d",&e);
		InsertNode(poly,c,e);
	}
}
void display(struct node *ptr){
	while(ptr!=NULL){
		printf("%d(x^%d)",ptr->coef,ptr->expo);
		if(ptr->link != NULL){
			printf(" + ");
		}else{
			printf("\n");
		}
		ptr=ptr->link;
	}
}
int main(){
	struct node *p1=NULL;
	struct node *p2=NULL;
	InputPoly(&p1);
	InputPoly(&p2);
	struct node *result=addPoly(p1,p2);
	display(result);
}
