/*Modify your pyramid pattern code to accept the number of rows as user input,
so the user can set the height of the pyramid before printing.*/
#include<stdio.h>
int main(){
	int rows,i,j,l;
	printf("Enter no of rows : ");
	scanf("%d",&rows);
	for(i = 1;i<=rows;i++){
		for(j=1;j<=rows-i;j++){
			printf(" ");
		}
		for(l=1;l<=2*i-1;l++){
			printf("*");
		}
		printf("\n");
	}
}
