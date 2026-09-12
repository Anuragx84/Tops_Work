/*Write a function swapPlaylistCounts(int *a, int *b) that swaps the number of songs in two Spotify playlists 
using pointers, then call the function in main and print the swapped values.*/

#include<stdio.h>

void swapPlaylistCount(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int playlist1 = 50,playlist2 = 75;
	printf("Before swapping : playlist 1 : %d\tPlaylist 2 : %d\n",playlist1,playlist2);
	swapPlaylistCount(&playlist1,&playlist2);
	printf("After swapping : playlist 1 : %d\tPlaylist 2 : %d\n",playlist1,playlist2);
	return 0;
}

