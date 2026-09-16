#include <stdio.h>
#include <string.h>

#define SUBJECTS 3
#define DAYS 7

struct StudyLog {
    char subject[40];
    float hours[DAYS];
};

void calculateReport(struct StudyLog logs[], int n) {
    printf("\n========== WEEKLY REPORT ==========\n");

    for (int i = 0; i < n; i++) {
        float total = 0.0f;

        for (int j = 0; j < DAYS; j++) {
            total += logs[i].hours[j];
        }

        printf("\nSubject: %s\n", logs[i].subject);
        printf("Weekly Total: %.2f hours\n", total);
        printf("Daily Average: %.2f hours\n", total / DAYS);
    }
}

void displayProgressChart(struct StudyLog logs[], int n) {
    printf("\n========== PROGRESS CHART ==========\n");

    for (int i = 0; i < n; i++) {
        printf("\n%s\n", logs[i].subject);

        for (int day = 0; day < DAYS; day++) {
            printf("Day %d: ", day + 1);

            int wholeHours = (int)logs[i].hours[day];

            for (int h = 0; h < wholeHours; h++) {
                printf("*");
            }

            printf(" %.2f hours\n", logs[i].hours[day]);
        }
    }
}

void logToday(struct StudyLog logs[], int n, int day) {
    printf("\n--- Log Today's Study Hours (Day %d) ---\n", day + 1);

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Enter hours for %s (0-24): ", logs[i].subject);

            if (scanf("%f", &logs[i].hours[day]) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n');
                continue;
            }

            if (logs[i].hours[day] < 0 || logs[i].hours[day] > 24) {
                printf("Hours must be between 0 and 24.\n");
                continue;
            }

            break;
        }
    }
}

void saveToFile(struct StudyLog logs[], int n) {
    FILE *file = fopen("productivity_log.txt", "w");

    if (file == NULL) {
        printf("Error: Could not open productivity_log.txt.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s", logs[i].subject);

        for (int j = 0; j < DAYS; j++) {
            fprintf(file, ",%.2f", logs[i].hours[j]);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    printf("All records saved to productivity_log.txt successfully.\n");
}

int main() {
    struct StudyLog logs[SUBJECTS] = {
        {"Java", {0, 0, 0, 0, 0, 0, 0}},
        {"DBMS", {0, 0, 0, 0, 0, 0, 0}},
        {"Web Development", {0, 0, 0, 0, 0, 0, 0}}
    };

    int choice;
    int currentDay = 0;

    do {
        printf("\n====================================\n");
        printf("     STUDENT PRODUCTIVITY TRACKER\n");
        printf("====================================\n");
        printf("1. Log Today's Study Hours\n");
        printf("2. View Weekly Report\n");
        printf("3. Save & Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                if (currentDay >= DAYS) {
                    printf("All 7 days have already been logged.\n");
                } else {
                    logToday(logs, SUBJECTS, currentDay);
                    currentDay++;
                    printf("Day %d data saved.\n", currentDay);
                }
                break;

            case 2:
                calculateReport(logs, SUBJECTS);
                displayProgressChart(logs, SUBJECTS);
                break;

            case 3:
                saveToFile(logs, SUBJECTS);
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}
