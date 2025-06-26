/*
## Exercise 7: Dynamic Array

Create a program that:

- Asks the user for array size.

- Dynamiaclly allocates memory for that many integers.

- Fills the array with user input.

- Prints the array.

- Properly frees the memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t length = 0;
    printf("Enter an array size: ");
    scanf("%zu", &length);
    if (!(length > 0)) {
        printf("ERROR: enter a valid number.\n");
        return -1;
    }
    int *array_pointer = malloc(length * sizeof(int));

    if (array_pointer == NULL) {
        printf("Error: Memory allocation failed.\n");
        return -1;
    }

    for (size_t i = 0; i < length; i++) {
        printf("Enter array[%zu]: ", i);
        scanf("%d", array_pointer + i);
    }
    printf("\n");

    printf("Array = { ");
    for (size_t i = 0; i < length; i++) {
        printf("%d ", *(array_pointer + i));
    }
    printf("}\n");

    free(array_pointer);
    return 0;
}
