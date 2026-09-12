/*Given an array of 5 order amounts (e.g., Zomato orders), use a pointer to iterate 
through the array and print each amount along with its memory address.Hint: Use pointer arithmetic to move to the next element.*/

#include<stdio.h>

int main(){
	int i,amounts[5] = {150,175,225,300,189};
	int *ptr = amounts;
	for(i=1;i<=5;i++){
		printf("amount : %d\tmemory address : %p\n",*ptr,ptr);
		ptr++;
	}
	return 0;
}
