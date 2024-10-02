#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 10

int number(char c){
	switch (c){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return false;
	}
}

int main(){
	char postfix[MAX];
	int stack[MAX];
	printf("Enter postfix expression: ");
	scanf("%s", postfix);
	int i=0,top=-1,value=0;
	while(postfix[i]!='\0'){
		char c=postfix[i];
		//int n = number(c);
		if (isdigit(c)){
			top++;
			stack[top]=number(c);
		}else{
			int a=stack[top];
			int b=stack[top-1];
			top=top-2;
			switch(c){
				case '+':
					stack[++top]=a+b;
					break;
				case '-':
					stack[++top]=b-a;
					break;
				case '*':
					stack[++top]=a*b;
					break;
				case '/':
					stack[++top]=b/a;
					break;
			}
		}
		i++;
	}
	printf("Postfix evaluation: %d",stack[top]);
}