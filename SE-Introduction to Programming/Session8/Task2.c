/*2.Create a function addToCart that takes a shopping cart array and a product name,
adds the product to the cart, and prints the updated cart.
Demonstrate how passing the cart array by reference allows changes to persist outside the function.
Hint: In languages like JavaScript, arrays are passed by reference. In C/C++, use pointers for reference behavior.*/

#include<stdio.h>
#include<string.h>
void addToCart(char list[][50],char productName[],int *count){
	int i;
	strcpy(list[*count],productName);	
	(*count)++;
	printf("Updated Carts : ");
	for(i=0;i< *count;i++){
		printf("%s,	",list[i]);
	}
}

int main(){
	char list[10][50];
	int i,count = 0;
	char productName[50];
	for(i=0;i<10;i++){
		printf("\nEnter product name : ");
		scanf(" %[^\n]",productName);
		addToCart(list,productName,&count);
	}
	return 0;
}
