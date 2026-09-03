/*2.Build a Zomato-style food suggestion tool: take the user's preferred meal time ('breakfast', 'lunch', 'dinner', or 'snack') 
and use a switch-case statement to suggest a popular dish for that time. If the input doesn't match any meal, suggest 'Try some fruits!'.*/
#include <stdio.h>

int main() {
    char meal;

    printf("Enter meal time (b = breakfast, l = lunch, d = dinner, s = snack): ");
    scanf(" %c", &meal);

    switch (meal) {
        case 'b':
        case 'B':
            printf("Suggestion: Poha and tea\n");
            break;

        case 'l':
        case 'L':
            printf("Suggestion: Biryani\n");
            break;

        case 'd':
        case 'D':
            printf("Suggestion: Paneer butter masala with naan\n");
            break;

        case 's':
        case 'S':
            printf("Suggestion: Samosa with chai\n");
            break;

        default:
            printf("Try some fruits!\n");
    }

    return 0;
}
