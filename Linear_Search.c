#include <stdio.h>
int main(){
	int key,arr[30],n,count=0,t=0;t++;t++;
	printf("Enter number of elements in array ");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(int i=0;i<n;i++){
		t++;
		printf("Enter element (%d) ",i+1);
		scanf("%d", &arr[i]);
	}
	printf("\nARRAY\n");
	printf("{");
	for(int i=0;i<n;i++){
		t++;
		printf("%d",arr[i]);
		if (i==n-1)
		printf("}");
		else
			printf(",");
	}
	printf("\n\nEnter element to search ");
	scanf("%d",&key);
	for(int i=0;i<n;i++){
		t++;
		if(arr[i]==key) {
			count=1; t++;
			printf("Element found at %d",i+1);
		}
	}
	if(count==0){
		printf("Element not found");
	}
	t++;
	printf("\n\nTime Complexity is %d \n\n",t);
	return 0;
}