/*3.Create a Flipkart discount calculator that asks the user for the total cart amount. 
Use nested if statements to check: if amount > 2000, apply 20% discount; else if amount > 1000, apply 10% discount;
else, no discount. Print the final amount to pay.<br><br><em><strong>Hint:</strong> Use nested ifs to check each discount slab.</em>*/
#include <stdio.h>

int main() {
    float amount, finalAmount;

    printf("Enter total cart amount: ");
    scanf("%f", &amount);

    if (amount > 2000) {
        finalAmount = amount - (amount * 20 / 100);
    } else {
        if (amount > 1000) {
            finalAmount = amount - (amount * 10 / 100);
        } else {
            finalAmount = amount;
        }
    }

    printf("Final amount to pay: Rs. %.2f\n", finalAmount);

    return 0;
}
