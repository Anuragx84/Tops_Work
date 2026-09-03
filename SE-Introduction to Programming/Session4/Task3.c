/*3.	Write a function isEligibleForOffer that takes a user's age and total order value, 
and returns true if the user is 18 or older AND the order value is above 500, otherwise false.
<br><br><em><strong>Hint:</strong> Use relational and logical operators together.</em>*/

#include<stdio.h>
int isEligibleforOffer(int age,float orderValue){
	if(age>=18 && orderValue>500){
		return 1;
	}
	return 0;
}
int main(){
	int age;
	float orderValue;
	printf("Enter age : ");
	scanf("%d",&age);
	printf("Enter order value : ");
	scanf("%f",&orderValue);
	if(isEligibleforOffer(age,orderValue)){
		printf("\nCongrats ! You are eligible for offer.....");
	}
	else
	{
		printf("\nSorry ! You are not eligible for offer.....");
	}
	return 0;
}

