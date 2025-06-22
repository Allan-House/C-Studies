#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double addition(const double x, const double y) { return x + y; }

double subtraction(const double x, const double y) { return x - y; }

double multiplication(const double x, const double y) { return x * y; }

double division(const double x, const double y) {
    if (fabs(y) < 1e-10) {
        printf("ERROR: Division by zero is undefined.\n");
        exit(EXIT_FAILURE);
    }
    return x / y;
}

bool read_number(double *operand) {
    double temp = 0.0;
    printf("Enter operand: ");
    int result = scanf("%lf", &temp);
    
    if (result != 1) {
        printf("ERROR: Invalid input. Please enter a valid number.\n");
        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }
    
    if (!isfinite(temp)) {
        printf("ERROR: Please enter a finite number.\n");
        return false;
    }
    
    *operand = temp;
    return true;
}

bool read_operator(char *operator) {
    printf("Enter operation (+, -, *, /): ");
    int result = scanf(" %c", operator);
    
    if (result != 1) {
        printf("ERROR: Invalid operator input.\n");
        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }
    
    if (*operator != '+' && *operator != '-' && *operator != '*' && *operator != '/') {
        printf("ERROR: Invalid operator. Use +, -, *, or /.\n");
        return false;
    }
    
    return true;
}

int main() {
    double x = 0.0, y = 0.0, result = 0.0;
    char operator;

    printf("=== Simple Calculator ===\n");

    if (!read_number(&x)) {
        return EXIT_FAILURE;
    }

    if (!read_operator(&operator)) {
        return EXIT_FAILURE;
    }

    if (!read_number(&y)) {
        return EXIT_FAILURE;
    }

    switch (operator) {
        case '+': 
            result = addition(x, y); 
            break;
        case '-': 
            result = subtraction(x, y); 
            break;
        case '*': 
            result = multiplication(x, y); 
            break;
        case '/': 
            result = division(x, y); 
            break;
        default: 
            printf("ERROR: Invalid operator.\n"); 
            return EXIT_FAILURE;
    }

    printf("\nResult: %.4lf %c %.4lf = %.4lf\n", x, operator, y, result);

    return EXIT_SUCCESS;
}
