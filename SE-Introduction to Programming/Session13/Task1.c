/*Create a file called playlist.txt and write the names of your top 3 favorite songs from Spotify into it using write mode (w).*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	FILE *ptr;
	ptr = fopen("playlist.txt","w");
	if(ptr==NULL){
		printf("Error in opening file");
		return 1;
	}
	fprintf(ptr,"Tum Hi Ho\n");
	fprintf(ptr,"Love Me Like You Do\n");
	fprintf(ptr,"Father Saab\n");
	fclose(ptr);
	printf("Data entered successfully in the file playlist.txt\n");
	return 0;
}
