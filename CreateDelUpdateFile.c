#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[] = "sample.txt";

    // 1. Creating & writing to a file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed to create the file.\n");
        return 1;
    }
    fprintf(fp, "Hello, this is a new file!\n");
    fprintf(fp, "Initial content written to file.\n");
    fclose(fp);
    printf("File created and initial content written.\n");

    // 2. Appending/updating content
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Failed to open the file for updating.\n");
        return 1;
    }
    fprintf(fp, "Appending some more content to the file.\n");
    fclose(fp);
    printf("File updated successfully.\n");

    // 3. Deleting the file
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting the file");
    }

    return 0;
}
