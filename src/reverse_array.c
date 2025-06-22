#include <stdio.h>

void reverse_array(int *array, int size);
void print_array(int *array, int size);

int main() {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array) / sizeof(array[0]);
    printf("Original array: ");
    print_array(array, length);
    printf("\n");

    reverse_array(array, length);

    printf("Reversed array: ");
    print_array(array, length);
    printf("\n");
    return 0;
}

void reverse_array(int *array, int size) {
    int *right_ptr = &array[size-1];
    int temp = 0;
    while (array < right_ptr) {
        temp = *array;
        *array = *right_ptr;
        *right_ptr = temp;
        array++;
        right_ptr--;
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}