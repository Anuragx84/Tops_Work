/*Build a function formatPrice that takes a price in rupees and returns a string formatted
like Flipkart's price tag (e.g., '?1,599'). Use this function to display prices for three different products.*/

#include<stdio.h>
#include<string.h>
void formatPrice(char Price[],int price){
	int cpy = price;
	if(cpy>=1000){
		sprintf(Price,"?%d,%03d",cpy/1000,cpy%1000);
	}
	else{
		sprintf(Price,"?%d",cpy);
	}
}

int main(){
	char Price[50];
	int price = 10589;
	formatPrice(Price,price);
	printf("%s\n",Price);
	return 0;
}
