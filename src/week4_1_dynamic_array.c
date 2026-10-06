#include <stdio.h>
#include <stdlib.h> // Required for malloc, free, and exit

int main(void) {
    int n;
    printf("Enter number of elements: ");
    
    // Check if scanf successfully read a number, and if it's positive
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Dynamically allocate memory for n integers
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Always check if malloc returned a valid pointer
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        // Check if reading the integer failed
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr); // Free memory before exiting to prevent leaks
            return 1;
        }
        sum += arr[i];
    }

    // Calculate average using floating-point division
    float average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    // Always free dynamically allocated memory
    free(arr);
    return 0;
}
