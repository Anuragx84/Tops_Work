/*1.Create a simple JavaScript function called calculateTotal that takes two numbers: itemPrice and quantity,
 and returns the total bill amount using arithmetic operators.*/
#include <stdio.h>

float calculateTotal(float itemPrice, int quantity) {
    return itemPrice * quantity;
}

int main() {
    float price;
    int quantity;

    printf("Enter price : ");
    scanf("%f", &price);

    printf("Quantity : ");
    scanf("%d", &quantity);

    printf("Total amount : %f", calculateTotal(price, quantity));

    return 0;
}
