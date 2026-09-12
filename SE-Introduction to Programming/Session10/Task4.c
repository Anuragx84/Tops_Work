/*Build a small script that takes the user's full name as input and creates a username 
by copying only the first 5 characters using strcpy(). Print the generated username.
Constraint: If the name is shorter than 5 characters, use the full name as the username.*/

#include<stdio.h>
#include<string.h>

int main(){
	int i;
	char fullName[20];
	char userName[10],temp[7];
	printf("Enter your Full name : ");
	scanf(" %[^\n]",fullName);
	for(i=0;i<5;i++){
		temp[i] = fullName[i];
	}
	temp[i]='\0';
	strcpy(userName,temp);	
	printf("Username of %s : %s",fullName,userName);
	
	return 0;
}
