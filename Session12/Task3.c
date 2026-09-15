/*.Define a nested structure called MovieShow for a BookMyShow-style app: Movie (string), 
Screen (integer), and a nested structure Time with hours and minutes (integers). 
Create and initialize a MovieShow variable for any movie and print its details in the format 'Movie: X, Screen: Y, Time: HH:MM'.*/

#include<stdio.h>

struct Time{
		int hours;
		int minutes;
	};
	
struct MovieShow{
	char movie[25];
	int screen;
	struct Time time;
};

int main(){
	struct MovieShow movie1 = {
	    "Pushpa2: The Rule",
	    3,
	    {7, 30}
	};
	printf("Movie: %s, Screen: %d, Time: %02d:%02d",
       movie1.movie,
       movie1.screen,
       movie1.time.hours,
       movie1.time.minutes);
	return 0;
}
