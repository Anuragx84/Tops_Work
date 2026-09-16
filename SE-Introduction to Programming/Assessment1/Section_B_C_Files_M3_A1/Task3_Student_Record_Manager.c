#include <stdio.h>

struct Student {
    char name[50];
    int rollno;
    float marks;
    char grade;
};

void assignGrade(struct Student *s) {
    if (s->marks >= 90)
        s->grade = 'A';
    else if (s->marks >= 75)
        s->grade = 'B';
    else if (s->marks >= 60)
        s->grade = 'C';
    else if (s->marks >= 45)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void printTopper(struct Student students[], int n) {
    int topIndex = 0;

    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[topIndex].marks) {
            topIndex = i;
        }
    }

    printf("\nTop Performer:\n");
    printf("Name : %s\n", students[topIndex].name);
    printf("Marks: %.2f\n", students[topIndex].marks);
}

int main() {
    struct Student students[3];

    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Student %d\n", i + 1);

        printf("Name: ");
        scanf(" %49[^\n]", students[i].name);

        printf("Roll No: ");
        scanf("%d", &students[i].rollno);

        do {
            printf("Marks (0-100): ");
            scanf("%f", &students[i].marks);

            if (students[i].marks < 0 || students[i].marks > 100)
                printf("Invalid marks. Enter a value from 0 to 100.\n");

        } while (students[i].marks < 0 || students[i].marks > 100);

        assignGrade(&students[i]);
    }

    printf("\n%-20s %-10s %-10s %-8s\n",
           "Name", "Roll No", "Marks", "Grade");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("%-20s %-10d %-10.2f %-8c\n",
               students[i].name,
               students[i].rollno,
               students[i].marks,
               students[i].grade);
    }

    printTopper(students, 3);

    return 0;
}