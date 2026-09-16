#include <stdio.h>

int main() {
    float percentage;
    char grade;

    printf("Enter percentage: ");

    if (scanf("%f", &percentage) != 1) {
        printf("Invalid input. Please enter a numeric percentage.\n");
        return 1;
    }

    if (percentage < 0 || percentage > 100) {
        printf("Error: Percentage must be between 0 and 100.\n");
        return 1;
    }

    if (percentage >= 90) {
        grade = 'A';
        printf("Grade: %c - Excellent work! Keep it up.\n", grade);
    } else if (percentage >= 75) {
        grade = 'B';
        printf("Grade: %c - Good work! Keep pushing.\n", grade);
    } else if (percentage >= 60) {
        grade = 'C';
        printf("Grade: %c - Good effort! You can improve further.\n", grade);
    } else if (percentage >= 45) {
        grade = 'D';
        printf("Grade: %c - Keep practicing and improving.\n", grade);
    } else {
        grade = 'F';
        printf("Grade: %c - Don't give up. Keep working hard.\n", grade);
    }

    return 0;
}