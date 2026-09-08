/*Explain with your own example the difference between entry-controlled 
and exit-controlled loops by writing a short code snippet for each (for/while vs do-while)
 and describing what happens if the loop condition is false at the start.*/

#include <stdio.h>

int main()
{
    int i = 10;
    printf("Entry-Control Loop:\n");
    while(i <= 5)
    {
        printf("%d\n", i);
        i++;
    }
    printf("While loop did not execute because condition was false.\n\n");
    i = 10;
    printf("Exit-Controlled Loop:\n");
    do
    {
        printf("%d\n", i);
        i++;
    } while(i <= 5);
    printf("Do-while executed once before checking the condition.\n");
    return 0;
}
