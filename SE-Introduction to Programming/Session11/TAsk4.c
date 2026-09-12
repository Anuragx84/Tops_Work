/*Create a function incrementFollowers(int *followers, int n) that increases each follower count in an array 
(representing Instagram followers for 5 friends) by 100 using pointer arithmetic, then print the updated counts.*/

#include<stdio.h>

void incrementFollowers(int *followers,int n){
	int i;
	for(i=1;i<=n;i++){
		*followers += 100;
		followers++;
	}
}

int main(){
	int i,n=5;
	int followers[] = {500, 1250, 800, 2300, 1750};
	printf("Before increment followers : \n");
	for(i=0;i<n;i++){
		printf("Friend %d followers :- %d\n",i+1,followers[i]);
	}
	incrementFollowers(followers,n);
	printf("\n\nAfter increment followers : \n");
	for(i=0;i<n;i++){
		printf("Friend %d followers :- %d\n",i+1,followers[i]);
	}
	return 0;
}
