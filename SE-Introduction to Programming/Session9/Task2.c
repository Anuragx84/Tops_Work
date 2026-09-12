/*Create a 2D array called playlistRatings to store ratings for 3 Spotify playlists over 5 days 
(rows = playlists, columns = days). Fill it with sample numbers and print the ratings for the second playlist.*/
#include<stdio.h>

int main(){
	int i;
	float playlistRatings[3][5]={{4.2,4.4,4.1,4.6,4.5},{3.8,4.0,4.2,4.1,4.4},{4.5,4.3,4.6,4.7,4.8}};
	printf("ratings for second playlist : \n");
	for(i=0;i<5;i++){
		printf("day %d  : %.1f\n",i+1,playlistRatings[1][i]);
	}
	return  0;
}
