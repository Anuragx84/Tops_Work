/*Write two functions: increaseFollowersByValue and increaseFollowersByReference.
Each should take a followers count and add 1000 to it, but one should 
use pass-by-value and the other pass-by-reference. 
how how the original followers count changes (or doesn't) after calling each function.*/

#include<stdio.h>

void increaseFollowerByValue(int followerCount){
	followerCount += 1000;
}

void increaseFollowerByReference(int *followerCount){
	*followerCount += 1000;	
}

int main(){
	int followerCount = 500;
	printf("Before calling no function follower : %d\n",followerCount);
	increaseFollowerByValue(followerCount);
	printf("After calling (increaseFollowerByValue) follower : %d\n\n",followerCount);
	printf("Before calling (increaseFollowersByReference) follower : %d\n",followerCount);
	increaseFollowerByReference(&followerCount);
	printf("After calling (increaseFollowerByReference) follower : %d\n",followerCount);
	return 0;
}
