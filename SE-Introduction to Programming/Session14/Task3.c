#include <stdio.h>

// This function formats the follower count
// into K (thousand) or M (million) format.
void formatFollowersCount(int count, char result[])
{
    // If followers are 1 million or more,
    // convert the count into millions.
    if (count >= 1000000)
    {
        sprintf(result, "%.1fM", (float)count / 1000000);
    }

    // If followers are 1000 or more,
    // convert the count into thousands.
    else if (count >= 1000)
    {
        sprintf(result, "%.1fK", (float)count / 1000);
    }

    // If followers are below 1000,
    // keep the number as it is.
    else
    {
        sprintf(result, "%d", count);
    }
}

int main()
{
    char result[20];

    // Format 1500 followers.
    formatFollowersCount(1500, result);
    printf("1500 followers = %s\n", result);

    // Format 1200000 followers.
    formatFollowersCount(1200000, result);
    printf("1200000 followers = %s\n", result);

    // Format a number below 1000.
    formatFollowersCount(850, result);
    printf("850 followers = %s\n", result);

    return 0;
}
