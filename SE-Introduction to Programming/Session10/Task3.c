/*Copy the string 'Flipkart' into another string variable called shoppingApp using strcpy(), then print the value of shoppingApp.
Hint: Make sure to declare enough space for the destination string.*/

#include<stdio.h>
#include<string.h>

int main(){
	char appName[25] = "Flipkart";
	char shoppingApp[25];
	strcpy(shoppingApp,appName);
	printf("App : %s\tShopping App : %s\n",appName,shoppingApp);	
	return 0;
}
