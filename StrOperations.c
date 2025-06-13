#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseStr(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed String: %s\n", str);
}

void checkPalindrome(char str[]) {
    int len = strlen(str);
    int flag = 1;
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("It's a palindrome!\n");
    else
        printf("Not a palindrome.\n");
}

void charFrequency(char str[]) {
    int freq[256] = {0};
    for(int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    printf("Character Frequency:\n");
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0)
            printf("'%c' = %d\n", i, freq[i]);
    }
}

void separateVowelsConsonants(char str[]) {
    printf("Vowels: ");
    for(int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            printf("%c ", str[i]);
    }
    printf("\nConsonants: ");
    for(int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if(isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
            printf("%c ", str[i]);
    }
    printf("\n");
}

int main() {
    char str[1000];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // remove newline

    do {
        printf("\n--- String Utility Menu ---\n");
        printf("1. Reverse String\n");
        printf("2. Check Palindrome\n");
        printf("3. Character Frequency\n");
        printf("4. Separate Vowels & Consonants\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline from buffer

        switch(choice) {
            case 1: reverseStr(str); break;
            case 2: checkPalindrome(str); break;
            case 3: charFrequency(str); break;
            case 4: separateVowelsConsonants(str); break;
            case 5: printf("Exiting. Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}
