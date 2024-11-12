#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct BinaryTree{
	int arr[MAX_SIZE];
	int size;
};
void Initialize(struct BinaryTree *tree){
	for(int i=0; i<MAX_SIZE;i++){
		tree->arr[i]=-1;
	}
	tree->size=0;
}
void Insert(struct BinaryTree *tree,int value){
	if (tree->size==0){
		tree->arr[0]=value;
		tree->size=1;
		printf("Inserted %d at root\n", value);
	}else{
		int parent;
		printf("Enter the parent node value for %d : ", value);
		scanf("%d",&parent);
		int i;
		for (i=0;i<MAX_SIZE;i++){
			if (tree->arr[i]==parent){
				break;
			}
		}
		if (i==MAX_SIZE || tree->arr[i]==-1){
			printf("Parent node %d not found\n",parent);
			return;
		}
		char direction[1];
		printf("Insert %d to left(L) or Right(R) of %d : ", value, parent);
		scanf("%s",direction);
		int index=(direction[0]=='L'|| direction[0]=='l')?(2*i+1):(2*i+2);
		if (index < MAX_SIZE && tree->arr[index]==-1){
			tree->arr[index]=value;
			tree->size++;
			printf("Inserted %d at index %d\n",value,index);
		}
		else{
			printf("Cannot insert at choosen position as it is already occupied and or out of bounds\n");
		}
	}
}
int search(struct BinaryTree *tree,int value){
	for (int i=0;i<MAX_SIZE;i++){
		if(tree->arr[i]==value){
			return i;
		}
	}
	return -1;
}
void DeleteNode(struct BinaryTree *tree, int value){
	int index=search(tree,value);
	if(index==-1){
		printf("Value %d not found in the tree\n",value);
		return;
	}
	tree->arr[index]=-1;
	printf("Deleted node %d from the tree\n",index);
}
void inorder(struct BinaryTree *tree,int index){
	if (index<MAX_SIZE && tree->arr[index]!=-1){
		inorder(tree,2*index+1);
		printf("%d\n",tree->arr[index]);
		inorder(tree,2*index+2);
	}
}
void preOrder(struct BinaryTree *tree,int index){
	if (index<MAX_SIZE &&tree->arr[index]!=-1){
		printf("%d\n",tree->arr[index]);
		preOrder(tree,2*index+1);
		preOrder(tree,2*index+2);
	}
}
void postOrder(struct BinaryTree *tree,int index){
	if(index<MAX_SIZE && tree->arr[index]!=-1){
		postOrder(tree,2*index+1);
		postOrder(tree,2*index+2);
		printf("%d\n",tree->arr[index]);
	}
}
int main(){
	struct BinaryTree tree;
	Initialize(&tree);
	int choice, value;
	do{
		printf("\n\t1.Insert\n\t2.Search\n\t3.Delete\n\t4.Inorder Traversal\n\t5.PostOrder Traversal\n\t6.Preorder Traversal\n\t7.Exit\n");
		printf("Enter your choice ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the value to insert ");
				scanf("%d",&value);
				Insert(&tree,value);
				break;
			case 2:
				printf("Enter value to search ");
				scanf("%d",&value);
				int index=search(&tree,value);
				if(index!=-1){
					printf("Value %d found at index %d\n",value,index);
				}else{
					printf("Value %d not found in the tree\n",value);
				}
				break;
			case 3:
				printf("Enter value of delete ");
				scanf("%d",&value);
				DeleteNode(&tree,value);
				break;
			case 4:
				printf("Inorder Traversal\n");
				inorder(&tree,0);
				printf("\n");
				break;
			case 5:
				printf("Postorder Traversal\n");
				postOrder(&tree,0);
				printf("\n");
				break;
			case 6:
				printf("Preorder Traversal\n");
				preOrder(&tree,0);
				printf("\n");
				break;
			case 7:
				printf("Exiting.........");
				exit(0);
			default:
				printf("Invalid input");
				break;
			}
		
	}while(choice!=7);
}
