/*Declare a function called getUserInitials that takes a user's full name (like 'Virat Kohli')
and returns their initials in uppercase (e.g., 'VK'). Call this function 
with your favorite cricketer's name and print the result.*/
#include <stdio.h>

void getUserInitials(char name[]){
    int i = 0;
    printf("Initials : ");
    if (name[0] != ' ')
        printf("%c", toupper(name[0]));
    while (name[i] != '\0')    {
        if (name[i] == ' ' && name[i + 1] != '\0'){
            printf("%c", toupper(name[i + 1]));
        }
        i++;
    }
}

int main()
{
    char name[100];
    printf("Enter cricketer's full name : ");
    fgets(name, sizeof(name), stdin);
    getUserInitials(name);

    return 0;
}
