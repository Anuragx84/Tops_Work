#include <stdio.h>

int main() {
    int arr[10];
    int max, min, temp;
    float sum = 0, mean;

    printf("Enter 10 integers:\n");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
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

    mean = sum / 10;

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Mean: %.2f\n", mean);

    printf("Sorted array: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    if (mean - min < max - mean)
        printf("Mean is closer to minimum.\n");
    else if (max - mean < mean - min)
        printf("Mean is closer to maximum.\n");
    else
        printf("Mean is exactly midway between minimum and maximum.\n");

    return 0;
}