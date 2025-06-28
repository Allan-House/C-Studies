# Exercises

## Pointers

### 1. Swap Function

Implement a `swap` function that exchanges the values of two integers using pointers.

### 2. Find Maximum

Write a function `find_max(int *a, int *b)` that returns a pointer to the larger of two integers.

### 3. Reverse Array

Write a function that reverses an array in-place using two pointers (one from start, one from end). The function signature should be: `void reverse_array(int *arr, int size);`

### 4. Dynamic Array

Create a program that:

- Asks the user for array size.
- Dynamically allocates memory for that many integers.
- Fills the array with user input.
- Prints the array.
- Properly frees the memory.

### 5. 2D Dynamic Array

Implement functions to:

- Dynamically allocate a 2D array of integers.
- Fill it with multiplication table values (i * j).
- Print the 2D array.
- Free all allocated memory.

### 6. String Manipulation

Write functions for string manipulation using only pointers (no array indexing):

- Get string length.
- Copy string.
- Concatenate strings.
- Compare strings.

### 7. Pointer Array Sorting

Write a program that:

- Creates an array of integer pointers.
- Each pointer points to a different integer variable.
- Sorts the pointers based on the values they point to (not the addresses).
- Prints the sorted values.

### 8. Generic Swap

Write a generic swap function that can swap any data type. The function signature should be: `void generic_swap(void *a, void *b, size_t size);`.

### 9. Function Pointer Calculator

Create a calculator program that:

- Uses function pointers for operations (+, -, *, /).
- Stores function pointers in an array.
- Allows user to select operations dynamically.

### 10. Command Line Argument Parser

Write a program that:

- Takes command line arguments.
- Parses flags (like `-v` for verbose, `-h` for help).
- Uses function pointers to handle different flags.
- Demonstrates understanding of char **argv.