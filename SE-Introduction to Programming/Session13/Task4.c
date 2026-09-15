/*Write a program that reads all song names from playlist.txt and prints only those that 
contain the word 'love' (case-insensitive). Hint:Use the 'in' keyword or equivalent string method for filtering.*/
#include<stdio.h>
#include<string.h>

int main(){
	int i;
	FILE *fptr;
	fptr = fopen("playlist.txt","r");
	if(fptr==NULL){
		printf("Error in opening file\n");
		return 1;
	}
	char line[100];
	while(fgets(line,sizeof(line),fptr)!=NULL){
		for(i = 0; line[i] != '\0'; i++)
			{
			    line[i] = toupper(line[i]);
			}
		if(strstr(line,"LOVE")!=NULL){
			printf("%s",line);
		}
	}
	fclose(fptr);
	return 0;
}
