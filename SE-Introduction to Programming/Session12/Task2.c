/*Create a structure called FoodItem to store Zomato-style menu data: itemName (string), 
price (float), and rating (float). Initialize an array of 3 FoodItem variables 
with real menu items and display their details using a loop.*/

#include<stdio.h>

struct FoodItem{
	char itemName[65];
	float price;
	float rating;
};
int main(){
	int i;
	struct FoodItem items[3]={
		{"Paneer Tikka",249,4.5},
		{"Veg Biryani",199,4.2},
		{"Cheese Burger",179,4.3}
	};
	for(i=0;i<3;i++){
		printf("%s\tPrice : %.2f\t Ratings : %.1f\n",items[i].itemName,items[i].price,items[i].rating);
	}
	return 0;
}
