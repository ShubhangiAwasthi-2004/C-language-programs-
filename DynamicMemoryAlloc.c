#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2;
    int n = 5, i;

    // malloc - uninitialized memory
    arr1 = (int *)malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed using malloc.\n");
        return 1;
    }
    printf("Memory allocated using malloc:\n");
    for (i = 0; i < n; i++) {
        arr1[i] = i + 1; // manually initializing
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // calloc - initialized to zero
    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed using calloc.\n");
        return 1;
    }
    printf("Memory allocated using calloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // realloc - expanding arr1 to hold 8 elements
    arr1 = (int *)realloc(arr1, 8 * sizeof(int));
    if (arr1 == NULL) {
        printf("Reallocation failed.\n");
        return 1;
    }
    printf("Array after realloc (expanded):\n");
    for (i = n; i < 8; i++) {
        arr1[i] = (i + 1) * 10;
    }
    for (i = 0; i < 8; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // free the memory
    free(arr1);
    free(arr2);

    printf("Memory freed successfully.\n");

    return 0;
}
