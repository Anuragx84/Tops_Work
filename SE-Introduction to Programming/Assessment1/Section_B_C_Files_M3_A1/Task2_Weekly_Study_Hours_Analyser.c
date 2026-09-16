#include <stdio.h>

int main() {
    float hours[7];
    float total = 0.0f;
    int highestDay = 0;

    for (int i = 0; i < 7; i++) {
        while (1) {
            printf("Enter study hours for Day %d (0-24): ", i + 1);

            if (scanf("%f", &hours[i]) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n');
                continue;
            }

            if (hours[i] < 0 || hours[i] > 24) {
                printf("Invalid hours. Please enter a value from 0 to 24.\n");
                continue;
            }

            break;
        }

        total += hours[i];

        if (i == 0 || hours[i] > hours[highestDay]) {
            highestDay = i;
        }
    }

    printf("\n--- Weekly Study Summary ---\n");
    printf("Weekly Total: %.2f hours\n", total);
    printf("Daily Average: %.2f hours\n", total / 7);
    printf("Highest Study Hours: Day %d (%.2f hours)\n",
           highestDay + 1, hours[highestDay]);

    printf("\nStudy Chart:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);

        for (int j = 0; j < (int)hours[i]; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}