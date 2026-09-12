/*Given a 2D array called cricketScores where each row represents an IPL match 
and columns represent runs scored by each team, write code to print the highest score from each match.*/
#include<stdio.h>

int main(){
	int i,cricketScores[3][2] = {
		    {185, 172},
		    {210, 195},
		    {160, 165}
		};	
		
	for(i=0;i<3;i++){
		printf("Highest score of team %d : ",i+1);
		if(cricketScores[i][0]>cricketScores[i][1]){
			printf("%d\n",cricketScores[i][0]);
		}
		else{
			printf("%d\n",cricketScores[i][1]);
		}
	}
	return 0;
}
