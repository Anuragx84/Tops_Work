/*Open playlist.txt in read mode (r) and display each song name on a separate line in the console.*/
#include<stdio.h>

int main(){
	FILE *fptr;
	fptr = fopen("playlist.txt","r");
	if(fptr==NULL){
		printf("Error in opening file\n");
		return 1;
	}
	char line[100];
	while(fgets(line,sizeof(line),fptr)!=NULL){
		printf("%s",line);
	}
	fclose(fptr);
	return 0;
}
