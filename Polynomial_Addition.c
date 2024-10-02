#include <stdio.h>
struct poly{
	int coef;
	int expo;
}p1[10],p2[10],p3[10];
int readPoly(struct poly p[10]){
	int t;
	printf("Enter number of elements ");
	scanf("%d",&t);
	printf("\nEnter coefficient and exponents in descending order\n\n");
	for(int i=0;i<t;i++){
		printf("Enter coefficient (%d) :",i+1);
		scanf("%d",&p[i].coef);
		printf("Enter exponent (%d) :",i+1);
		scanf("%d",&p[i].expo);
		printf("\n");
	}
	return t;
}
void display(struct poly p[10],int t){
	for (int i=0;i<t-1;i++){
		printf("%d(x^%d) + ", p[i].coef, p[i].expo);
	}
	printf("%d(x^%d)",p[t-1].coef, p[t-1].expo);
}
int addPoly(struct poly p1[10],int t1,struct poly p2[10],int t2,struct poly p3[10]){
	int i=0,j=0,k=0;
	while (i<t1 && j<t2){
		if(p1[i].expo==p2[j].expo){
			p3[k].coef=p1[i].coef+p2[j].coef;
			p3[k].expo=p1[i].expo;
			i++;j++;k++;
		}
		else if(p1[i].expo>p2[j].expo){
			p3[k].coef=p1[i].coef;
			p3[k].expo=p1[i].expo;
			i++;k++;
		}
		else{
			p3[k].coef=p2[j].coef;
			p3[k].expo=p2[j].expo;
			j++;k++;
		}
	}
	while (i<t1){
		p3[k].coef=p1[i].coef;
		p3[k].expo=p1[i].expo;
		i++;k++;
	}
	while(j<t2){
		p3[k].coef=p2[j].coef;
		p3[k].expo=p2[j].expo;
		j++;k++;
	}
	return k;
}
int main(){
	int t1,t2,t3;
	printf("\n\nFirst Polynomial\n\n");
	t1=readPoly(p1);
	display(p1,t1);
	printf("\n\nSecond Polynomial\n\n");
	t2=readPoly(p2);
	display(p2,t2);
	t3=addPoly(p1,t1,p2,t2,p3);
	printf("\n\nResultant Polynomial\n\n");
	display(p3,t3);
}