#include <stdio.h>

int main() {
    char answer;
    int score = 0;

    printf("🎯 Welcome to the C Programming Quiz!\n");
    printf("📋 Total Questions: 5 | ✅ +1 point for each correct answer\n\n");

    // Q1
    printf("1️⃣ What is the correct file extension for C language?\n");
    printf("A. .cp\nB. .c\nC. .cpp\nD. .cs\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') score++;

    // Q2
    printf("\n2️⃣ Which data type is used to store characters in C?\n");
    printf("A. int\nB. float\nC. char\nD. string\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') score++;

    // Q3
    printf("\n3️⃣ What is the output of: printf(\"%%d\", 10);\n");
    printf("A. %%d\nB. 10\nC. Error\nD. d\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') score++;

    // Q4
    printf("\n4️⃣ Which of these is a looping structure in C?\n");
    printf("A. for\nB. repeat\nC. jump\nD. choose\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'A' || answer == 'a') score++;

    // Q5
    printf("\n5️⃣ What is the size of int typically (on 32-bit system)?\n");
    printf("A. 2 bytes\nB. 4 bytes\nC. 8 bytes\nD. 1 byte\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') score++;

    // Result
    printf("\n🎉 Quiz Completed!\n");
    printf("📊 Your Score: %d/5\n", score);

    if (score == 5)
        printf("🏆 Excellent! You're a C Master!\n");
    else if (score >= 3)
        printf("👍 Good job! Keep learning.\n");
    else
        printf("📘 Keep practicing. You'll get better!\n");

    return 0;
}
