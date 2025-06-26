#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr1, *arr2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Using malloc (uninitialized memory)
    arr1 = (int*)malloc(n * sizeof(int));

    // Using calloc (initialized to 0)
    arr2 = (int*)calloc(n, sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter %d elements for malloc array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("\nArray from malloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nArray from calloc (default initialized):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    // Free allocated memory
    free(arr1);
    free(arr2);

    return 0;
}
