/*Declare a structure named Playlist to store details of a song: title (string), artist (string), and duration in seconds (integer). 
Initialize one Playlist variable with your favorite song's details and print each field.*/
#include<stdio.h>

struct Playlist{
	char title[50],artist[20];
	int duration;
};
int main(){
	struct Playlist song1={"Kesariya","Arijit Singh",268};
	printf("Title : %s\tArtist : %s\tDuration : %dseconds",song1.title,song1.artist,song1.duration);
	return 0;
}
