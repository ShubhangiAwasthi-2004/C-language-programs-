#include <stdio.h>

// Function to calculate grade
char calculateGrade(float avg) {
    if (avg >= 90)
        return 'A';
    else if (avg >= 75)
        return 'B';
    else if (avg >= 60)
        return 'C';
    else if (avg >= 40)
        return 'D';
    else
        return 'F'; // Fail
}

int main() {
    char name[50];
    float marks[3];
    float total = 0, average;
    char grade;

    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);

    for (int i = 0; i < 3; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    average = total / 3;
    grade = calculateGrade(average);

    printf("\n--- Student Report ---\n");
    printf("Name: %s", name);
    printf("Total Marks: %.2f\n", total);
    printf("Average: %.2f\n", average);
    printf("Grade: %c\n", grade);

    return 0;
}

