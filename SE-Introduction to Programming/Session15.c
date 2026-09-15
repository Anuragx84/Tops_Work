#include <stdio.h>

int main()
{
    int minutes[7] = {0};
    int count = 0;
    int choice;
    int i;

    do
    {
        printf("\n===== Music Listening Logger =====\n");
        printf("1. Log Daily Listening Minutes\n");
        printf("2. View Weekly Summary\n");
        printf("3. Generate Weekly Report\n");
        printf("4. Reset Weekly Data\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                FILE *file;
                int dailyMinutes;

                if (count >= 7)
                {
                    printf("You have already entered data for all 7 days.\n");
                    break;
                }

                printf("Enter listening minutes for Day %d: ", count + 1);
                scanf("%d", &dailyMinutes);

                minutes[count] = dailyMinutes;
                count++;

                // Open the file in append mode so old data is not deleted.
                file = fopen("music_log.txt", "a");

                if (file == NULL)
                {
                    printf("Error opening music_log.txt\n");
                    break;
                }

                // Save the daily listening minutes into the file.
                fprintf(file, "%d\n", dailyMinutes);

                fclose(file);

                printf("Listening minutes saved successfully.\n");
                break;
            }

            case 2:
            {
                printf("\n===== Weekly Summary =====\n");

                if (count == 0)
                {
                    printf("No listening data available.\n");
                }
                else
                {
                    for (i = 0; i < count; i++)
                    {
                        printf("Day %d: %d minutes\n",
                               i + 1, minutes[i]);
                    }
                }

                break;
            }

            case 3:
            {
                FILE *file;
                int value;
                int total = 0;
                int highest = 0;
                int days = 0;
                float average;

                // Open the saved file in read mode.
                file = fopen("music_log.txt", "r");

                if (file == NULL)
                {
                    printf("No saved music data found.\n");
                    break;
                }

                // Read all saved listening minutes from the file.
                while (fscanf(file, "%d", &value) == 1)
                {
                    total += value;

                    if (value > highest)
                    {
                        highest = value;
                    }

                    days++;
                }

                fclose(file);

                if (days == 0)
                {
                    printf("No listening data available.\n");
                }
                else
                {
                    average = (float)total / days;

                    printf("\n===== Weekly Report =====\n");
                    printf("Total Listening Minutes: %d\n", total);
                    printf("Average Listening Minutes: %.2f\n", average);
                    printf("Highest Listening Minutes: %d\n", highest);
                }

                break;
            }

            case 4:
            {
                char confirmation;
                FILE *file;

                printf("Are you sure you want to reset weekly data? (y/n): ");
                scanf(" %c", &confirmation);

                if (confirmation == 'y' || confirmation == 'Y')
                {
                    // Clear the array.
                    for (i = 0; i < 7; i++)
                    {
                        minutes[i] = 0;
                    }

                    count = 0;

                    // Opening a file in write mode clears its contents.
                    file = fopen("music_log.txt", "w");

                    if (file == NULL)
                    {
                        printf("Error clearing music_log.txt\n");
                        break;
                    }

                    fclose(file);

                    printf("Weekly data has been reset successfully.\n");
                }
                else
                {
                    printf("Reset cancelled.\n");
                }

                break;
            }

            case 5:
                printf("Exiting Music Listening Logger...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
