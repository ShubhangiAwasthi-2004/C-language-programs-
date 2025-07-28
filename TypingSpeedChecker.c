// Typing Speed Checker

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SENTENCES 5
#define MAX_LEN 256

int main() {
    char *sentences[MAX_SENTENCES] = {
      "The quick brown fox jumps over the lazy dog.",
      "C programming is fun and powerful.",
      "Typing fast can be a useful skill.",
      "Keep practicing to improve your speed.",
      "Always write clean and readable code.",
      "Debugging is like being the detective in a crime movie.",
      "Simplicity is the soul of efficiency in programming.",
      "Learning never exhausts the mind, it sharpens it.",
      "A good programmer looks both ways before crossing a one-way street.",
      "If you can't explain it simply, you don't understand it well enough.",
      "First solve the problem, then write the code.",
      "Sometimes, the best code is no code at all.",
      "Computers are fast, but programmers keep slowing them down.",
      "Clean code is like poetry — every word matters.",
      "Never underestimate the power of a well-placed semicolon."
      "The quick brown fox jumps over the lazy dog.",
      "C programming is fun and powerful.",
      "Typing fast can be a useful skill.",
      "Keep practicing to improve your speed.",
      "Always write clean and readable code."
    };

    char input[MAX_LEN];
    int index;

    srand(time(NULL));
    index = rand() % MAX_SENTENCES;

    printf("📝 Type the following sentence as fast as you can:\n\n");
    printf("👉 \"%s\"\n\n", sentences[index]);

    printf("Press ENTER when you're ready...");
    getchar();

    time_t start = time(NULL);

    printf("\nStart typing below:\n");
    fgets(input, MAX_LEN, stdin);

    time_t end = time(NULL);

    double time_taken = difftime(end, start);  // in seconds
    int word_count = 1;

    // Count words in original sentence
    for (int i = 0; sentences[index][i]; i++) {
        if (sentences[index][i] == ' ')
            word_count++;
    }

    double wpm = (word_count / time_taken) * 60.0;

    printf("\n⌛ Time taken: %.2f seconds\n", time_taken);
    printf("✍️ Words typed: %d\n", word_count);
    printf("🚀 Typing Speed: %.2f WPM\n", wpm);

    // Optional: Accuracy Check
    if (strcmp(sentences[index], input) == 0) {
        printf("✅ Perfect match! Well done!\n");
    } else {
        printf("⚠️ There were some differences in your typing.\n");
    }

    return 0;
}
