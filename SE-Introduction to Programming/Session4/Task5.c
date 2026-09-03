/*5.	Write a code snippet that demonstrates the difference between pre-increment (++count) and post-increment 
(count++) by logging the values before and after using both on a followerCount variable.*/
#include <stdio.h>

int main() {
    int followerCount = 100;
    printf("Initial followers: %d\n", followerCount);
    printf("Using ++followerCount: %d\n", ++followerCount);
    printf("After pre-increment: %d\n\n", followerCount);
    followerCount = 100;
    printf("Using followerCount++: %d\n", followerCount++);
    printf("After post-increment: %d\n", followerCount);
    return 0;
}

