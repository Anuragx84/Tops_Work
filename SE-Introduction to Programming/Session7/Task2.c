/*Build a right-angled triangle pattern using nested loops, where each row displays increasing
numbers starting from 1, similar to how a leaderboard on a gaming app shows rank numbers.*/

#include<stdio.h>

int main(){
	int i,j;
	for(i=1;i<=5;i++){
		for(j = 1;j<=i;j++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
