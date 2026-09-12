/*Take input for two usernames (as strings) and compare them using strcmp(). 
Display whether they are the same or different.*/
#include<stdio.h>
#include<string.h>

int main(){
	char username1[25],username2[25];
	printf("Enter 1st username : ");
	scanf(" %[^\n]",username1);
	printf("Enter 2nd username  : ");
	scanf(" %[^\n]",username2);
	if(strcmp(username1,username2)==0){
		printf("Both usernames are same \n");
		}
	else{
		printf("Usernames are different\n");
	}
	return 0;
}
