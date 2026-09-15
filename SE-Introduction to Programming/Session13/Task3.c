/*Add two more song names to playlist.txt without deleting the existing ones by opening the file in append mode (a).*/
#include<stdio.h>

int main(){
	FILE *fptr;
	fptr = fopen("playlist.txt","a");
	if(fptr==NULL){
		printf("Error in openenif file\n");
		return 1;
	}
	fprintf(fptr,"LOVE Story\n");
	fprintf(fptr,"Temporary Pyar\n");
	fclose(fptr);
	printf("File updated successfuly\n");
	return 0;
}
