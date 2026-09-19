/*Write a simple C program tasklist_c.c that allows you to add up to 5 tasks (as strings) 
to a global array and print all tasks using a for loop.*/


/*Modify your tasklist_c.c to add a function markTaskDone(int index) that sets the selected 
task to 'DONE' in the array, then print the updated list.
Hint: Use a separate status array or append ' - DONE' to the task string.*/


#include<stdio.h>
#include<string.h>

char array[5][100];


void markTaskDone(int index){
	strcat(array[index]," - DONE");
}

int main(){
	int i;
	char check[50];
	for(i=0;i<5;i++){
		printf("Enter task(%d) : ",i+1);
		scanf(" %[^\n]",array[i]);
	}

	printf("\n\n");	
	for(i=0;i<5;i++){
		printf("The task(%d) is done ? : ",i+1);
		scanf("%s",check);
		if(strcmp(check,"done")==0){
			markTaskDone(i);
		}
	}
	
	printf("\n\n");
	for(i=0;i<5;i++){
		printf("Task(%d) : %s\n",i+1,array[i]);
	}
	return 0;
}
