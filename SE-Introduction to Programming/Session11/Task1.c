/*Declare an integer variable called likes and a pointer variable called ptrLikes; 
assign likes a value, point ptrLikes to likes, and print both the value and the address stored in ptrLikes.*/

#include<stdio.h>

int main(){
	int like = 250;
	int *ptrLikes;
	ptrLikes = &like;
	printf("like : %d\n*ptrLikes : %d\n&like : %p\nptrLikes : %p",like, *ptrLikes,&like,ptrLikes);
	return 0;
}
