#include <stdio.h>

void swap(int *x, int *y);
void print_array(int array[], int length);
void demonstrate_pointer_arithmetic(int *ptr, int length);

int main() {
    printf("=== C POINTERS DEMONSTRATION ===\n\n");

    // 1. Pointers and Addresses
    printf("1. BASIC POINTERS AND ADDRESSES\n");
    printf("--------------------------------\n");
    int x = 10, y = 5;
    int *ptr_x = &x, *ptr_y = &y;

    printf("Variable x:\n");
    printf("  Address of x (&x):     %p\n", (void*)&x);
    printf("  Value of x:            %d\n", x);
    printf("\nPointer ptr_x:\n");
    printf("  ptr_x points to:       %p\n", (void*)ptr_x);
    printf("  Value at ptr_x (*ptr_x): %d\n", *ptr_x);
    printf("  Address of ptr_x:      %p\n", (void*)&ptr_x);

    printf("\nVariable y:\n");
    printf("  Address of y (&y):     %p\n", (void*)&y);
    printf("  Value of y:            %d\n", y);
    printf("\nPointer ptr_y:\n");
    printf("  ptr_y points to:       %p\n", (void*)ptr_y);
    printf("  Value at ptr_y (*ptr_y): %d\n", *ptr_y);
    printf("  Address of ptr_y:      %p\n", (void*)&ptr_y);

    // 2. Pass by Reference (Swapping)
    printf("\n\n2. PASS BY REFERENCE - SWAPPING VALUES\n");
    printf("--------------------------------------\n");
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap:  x = %d, y = %d\n", x, y);
    printf("(Notice how the original variables changed!)\n");

    // 3. Pointers and Arrays
    printf("\n\n3. POINTERS AND ARRAYS\n");
    printf("----------------------\n");
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr_a = a; // Equivalent to: int *ptr_a = &a[0];
    
    printf("Array contents: ");
    print_array(a, 10);
    
    printf("\nArray name 'a' is essentially a pointer to the first element:\n");
    printf("  Address of a[0] (&a[0]): %p\n", (void*)&a[0]);
    printf("  Value of a (array name): %p\n", (void*)a);
    printf("  Value of ptr_a:          %p\n", (void*)ptr_a);
    
    printf("\nDifferent ways to access a[i]:\n");
    printf("  a[0]           = %d\n", a[0]);
    printf("  *(a + 1)       = %d\n", *(a + 1));
    printf("  *(ptr_a + 2)   = %d\n", *(ptr_a + 2));
    printf("  ptr_a[3]       = %d\n", ptr_a[3]);

    // 4. Pointer Arithmetic
    printf("\n\n4. POINTER ARITHMETIC\n");
    printf("---------------------\n");
    demonstrate_pointer_arithmetic(ptr_a, 10);

    // 5. NULL Pointers
    printf("\n\n5. NULL POINTERS\n");
    printf("----------------\n");
    int *null_ptr = NULL;
    printf("null_ptr = %p\n", (void*)null_ptr);
    printf("Always check for NULL before dereferencing!\n");
    if (null_ptr != NULL) {
        printf("Safe to use: *null_ptr = %d\n", *null_ptr);
    } else {
        printf("null_ptr is NULL - cannot dereference safely\n");
    }

    // 6. Pointer to Pointer
    printf("\n\n6. POINTER TO POINTER\n");
    printf("---------------------\n");
    int value = 42;
    int *ptr = &value;
    int **ptr_to_ptr = &ptr;
    
    printf("value = %d\n", value);
    printf("*ptr = %d (ptr points to value)\n", *ptr);
    printf("**ptr_to_ptr = %d (ptr_to_ptr points to ptr, which points to value)\n", **ptr_to_ptr);
    
    printf("\n=== END OF DEMONSTRATION ===\n");
    return 0;
}

void swap(int *x, int *y) {
    printf("Inside swap function:\n");
    printf("  Before: *x = %d, *y = %d\n", *x, *y);
    
    int temp = *x;
    *x = *y;
    *y = temp;
    
    printf("  After:  *x = %d, *y = %d\n", *x, *y);
}

void print_array(int array[], int length) {
    printf("{ ");
    for (int i = 0; i < length; i++) {
        printf("%d", array[i]);
        if (i < length - 1) printf(", ");
    }
    printf(" }\n");
}

void demonstrate_pointer_arithmetic(int *ptr, int length) {
    printf("Starting pointer: %p\n", (void*)ptr);
    printf("Pointer arithmetic demonstration:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("  ptr + %d = %p, value = %d\n", 
               i, (void*)(ptr + i), *(ptr + i));
    }
    
    printf("\nMoving pointer through array:\n");
    int *moving_ptr = ptr;
    for (int i = 0; i < 5; i++) {
        printf("  moving_ptr at %p, value = %d\n", 
               (void*)moving_ptr, *moving_ptr);
        moving_ptr++; // Increment pointer to next element
    }
}