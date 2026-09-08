/*Build a 'Guess the Song' game like Spotify — the program randomly picks a song name
 from a list and asks the user to guess it. Use a do-while loop so the user can keep guessing
  until they get it right.Use at least 3 song names of your choice.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int i,randIndex;
	char guess[50],songs[10][50] = {
        "Tum Hi Ho",
        "Channa Mereya",
        "Agar Tum Saath Ho",
        "Phir Bhi Tumko Chaahunga",
        "Kesariya",
        "Tera Yaar Hoon Main",
        "Khairiyat",
        "Samjhawan",
        "Hamari Adhuri Kahani",
        "Ae Dil Hai Mushkil"
    };
    randIndex = (rand()%10);
    printf("Songs List : \n");
    for(i = 0;i<10;i++){
    	printf("%s\n",songs[i]);
	}
    printf("\nGuess the song game\n");
    do{
    	printf("Enter song : ");
    	scanf(" %[^\n]", guess);
//    	fgets(guess,50,stdin);
	}while(strcmp(guess,songs[randIndex])!=0);
	printf("You guess the correct song the song is %s\n",songs[randIndex]);
	return 0;
}
