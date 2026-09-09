/*1.Use nested for loops to print a grid of emojis representing
a 5x5 Instagram post feed, where each cell shows a ?? symbol.*/
#include<stdio.h>

int main(){
	int i,j;
	for(i = 1;i<=5;i++){
		for(j = 1;j<=5;j++){
			printf("[ ^] ");
		}
		printf("\n");
	}
	return 0;
}
