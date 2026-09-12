/*Build a function that takes a 1D array of 7 integers representing your daily 
Zomato order amounts and calculates the average spend for the week.
Hint: Use a loop to sum the values, then divide by the array length.*/
#include<stdio.h>

float averageSpend(int amounts[],int length){
	int i,sum=0;
	for(i=0;i<length;i++){
		sum += amounts[i];
	}
	return (float)sum/length;
}
int main(){
	int zomatoOrders[7] = {250, 180, 320, 150, 450, 275, 200};
	int length = sizeof(zomatoOrders)/4;
	printf("Average spend for the week : %.2f",averageSpend(zomatoOrders,length));
	return 0;
}
