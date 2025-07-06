#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roll;
    srand(time(0)); // Seed once
    printf("🎲 Press Enter to roll the dice...");
    getchar();
    roll = (rand() % 6) + 1;
    printf("You rolled a %d!\n", roll);
    return 0;
}
