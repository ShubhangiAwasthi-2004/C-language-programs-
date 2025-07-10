//  ******** Enjoy rock , paper and scissor game!! **********


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getComputerChoice() {
    return rand() % 3;  // 0 = Rock, 1 = Paper, 2 = Scissors
}

const char* getChoiceName(int choice) {
    if (choice == 0) return "Rock";
    else if (choice == 1) return "Paper";
    else return "Scissors";
}

void determineWinner(int user, int computer) {
    if (user == computer) {
        printf("It's a draw!\n");
    } else if ((user == 0 && computer == 2) ||
               (user == 1 && computer == 0) ||
               (user == 2 && computer == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    int userChoice, computerChoice;

    srand(time(0)); // Seed for random number generation

    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("Enter your choice:\n");
    printf("0 for Rock\n1 for Paper\n2 for Scissors\n");
    printf("Your choice: ");
    scanf("%d", &userChoice);

    if (userChoice < 0 || userChoice > 2) {
        printf("Invalid choice! Please enter 0, 1, or 2.\n");
        return 1;
    }

    computerChoice = getComputerChoice();

    printf("You chose: %s\n", getChoiceName(userChoice));
    printf("Computer chose: %s\n", getChoiceName(computerChoice));

    determineWinner(userChoice, computerChoice);

    return 0;
}
