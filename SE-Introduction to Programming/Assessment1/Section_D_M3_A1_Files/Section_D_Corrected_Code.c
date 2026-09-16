#include <stdio.h>

int main() {
    int arr[10];
    int max, min, temp;
    int validInput;
    float sum = 0.0f, mean;
    float distanceMin, distanceMax;

    printf("Enter exactly 10 integers:\n");

    for (int i = 0; i < 10; i++) {
        do {
            printf("Value %d: ", i + 1);
            validInput = scanf("%d", &arr[i]);

            if (validInput != 1) {
                printf("Invalid input. Please enter an integer.\n");
                while (getchar() != '\n');
            }
        } while (validInput != 1);

        sum += arr[i];
    }

    max = arr[0];
    min = arr[0];

    for (int i = 1; i < 10; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    mean = sum / 10.0f;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nMaximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Mean: %.2f\n", mean);

    printf("Sorted array: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    distanceMin = mean - min;
    distanceMax = max - mean;

    if (distanceMin < distanceMax)
        printf("Mean is closer to minimum.\n");
    else if (distanceMax < distanceMin)
        printf("Mean is closer to maximum.\n");
    else
        printf("Mean is exactly midway between minimum and maximum.\n");

    return 0;
}