/*
2D Dynamic Array
Implement functions to:
- Dynamically allocate a 2D array of integers.
- Fill it with multiplication table values (i * j).
- Print the 2D array.
- Free all allocated memory.
*/
#include <stdio.h>
#include <stdlib.h>

int** allocate2D(size_t rows, size_t columns);
void fillMultiplicationTable(int **array, size_t rows, size_t columns) ;
void print2D(int **array, size_t rows, size_t columns);
void free2D(int **array, size_t rows);

int main() {
    size_t rows = 0, columns = 0;
    
    printf("Enter the number of rows and columns: ");
    scanf("%zu %zu", &rows, &columns);
    
    // Allocate 2D array
    int **matrix = allocate2D(rows, columns);
    if (!matrix) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Fill with multiplication table
    fillMultiplicationTable(matrix, rows, columns);
    
    // Print the array
    printf("\nMultiplication Table (%zu x %zu):\n", rows, columns);
    print2D(matrix, rows, columns);
    
    // Free allocated memory
    free2D(matrix, rows);
    
    printf("\nMemory freed successfully.\n");
    return 0;
}

int** allocate2D(size_t rows, size_t columns) {
    int **array = malloc(rows * sizeof(int*));
    if (!array) return NULL;
    
    for (size_t i = 0; i < rows; i++) {
        array[i] = malloc(columns * sizeof(int));
        if (!array[i]) {
            // Cleanup on failure
            for (size_t j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}

void fillMultiplicationTable(int **array, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            array[i][j] = (i + 1) * (j + 1);
        }
    }
}

void print2D(int **array, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void free2D(int **array, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}