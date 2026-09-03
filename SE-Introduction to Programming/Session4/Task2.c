/*2.	Build a Flipkart-style discount calculator: given product price, discount percentage, and a boolean isMember, 
use arithmetic and logical operators to calculate the final price (apply an extra 5% off if isMember is true).*/
#include<stdio.h>
float calculateTotal(float itemPrice,int quantity){
	return itemPrice * quantity;	
}
int main(){
	float price,discountPrcnt;
	int isMember;
	int quantity;
	printf("Enter price : ");
	scanf("%f",&price);
	printf("Enter discountPrcnt : ");
	scanf("%f",&discountPrcnt);
	printf("isMember ? (0-NO/1-YES) : ");
	scanf("%d",&isMember);
	float finalPrice = price - (price * discountPrcnt/100);
	if(isMember){
		finalPrice = finalPrice - (finalPrice * 5/100);
	}
	printf("\nFinal price after discount : - %f",finalPrice);
	return 0;
}

