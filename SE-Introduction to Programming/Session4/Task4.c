/*4.	Given three variables: likes, comments, and shares (all numbers), write code to check if a post is 'trending' on Instagram
(at least 1000 likes OR more than 200 comments AND at least 50 shares). Print the result.*/
#include<stdio.h>

int main(){
	int like,comments,share;
	printf("Enter likes : ");
	scanf("%d",&like);
	printf("Enter comments : ");
	scanf("%d",&comments);
	printf("Enter share : ");
	scanf("%d",&share);
	if(like>=1000 && comments >= 200 && share >= 50){
		printf("This post is trending on instagram");
	}
	else{
		printf("This post is not trending on instagram");
	}
}

