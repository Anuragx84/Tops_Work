/*Declare a 1D array called dailySteps with 7 elements to store your step count 
for each day of the week, assign sample values, and print each value using a loop.*/

#include<stdio.h>

int main(){
	int i,dailySteps[] = {7842,9156,6734,8921,10284,12467,5893};
	printf("Weekly steps count : \n");
	for(i=0;i<7;i++){
		printf("day %d : %d\n",i+1,dailySteps[i]);
	}
	return 0;
}
