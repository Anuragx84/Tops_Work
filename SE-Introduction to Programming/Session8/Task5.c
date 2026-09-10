/*Refactor an existing function you wrote above to make it reusable for both product names and usernames
(for example, a function that capitalizes the first letter of any string).
Constraint: The refactored function should work for any string input, not just a specific use case.*/

#include<stdio.h>
#include<string.h>

void capitalizeFirst(char str[]){
	str[0] = toupper(str[0]);
	printf("%s\n",str);;
}

int main(){
	char product[30],username[30],course[30],city[30];
	printf("Enter product name : ");
	scanf(" %[^\n]",product);
	capitalizeFirst(product);
	printf("Enter username : ");
	scanf(" %[^\n]",username);
	capitalizeFirst(username);
	printf("Enter course : ");
	scanf(" %[^\n]",course);
	capitalizeFirst(course);
	printf("Enter city : ");
	scanf(" %[^\n]",city);
	capitalizeFirst(city);

	return 0;
}
