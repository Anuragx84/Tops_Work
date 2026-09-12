/*1.Declare a string variable called songTitle and assign it the value 'Tum Hi Ho'. 
Print the length of the string using strlen().*/
#include<stdio.h>
#include<string.h>

int main(){
	char songTittle[] = "Tum Hi Ho";
	printf("lenght of songTitle(%s) : %d",songTittle,strlen(songTittle));
	return 0;
}
