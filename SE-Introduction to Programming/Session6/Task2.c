/*2.Create a menu-driven console app that lets the user: 1) View your favorite 3 IPL teams, 2) Add a new team, 3) Exit.
Use a while loop to keep showing the menu until the user chooses Exit.
<br><br><em><strong>Hint:</strong> Use input() (or Scanner in Java) to get the user's choice each time.</em>*/
#include<stdio.h>
#include<string.h>
int main(){
	int i,j,choice=1,a=3;
	char teams[10][50]={"Chennai Super Kings","Mumbai Indians","Royal Challengers Bengaluru"};
	while(choice!=3){
		printf("1) View your favorite 3 IPL teams\n2) Add a new team\n3) Exit\nEnter : ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
		case 1:
			for(i=0;i<a;i++){
					printf("%s\n",teams[i]);
			}
			break;
		case 2:
				printf("Enter team name : ");
				fgets(teams[a],50,stdin);
//				gets(teams[a]);
				a++;
				break;
			
		case 3:
			printf("Exiting....");
			return 1;
			break;
			
		default :
			printf("Wrong input......\nTry again\n\n");
		}
	}
	return 0;
}
