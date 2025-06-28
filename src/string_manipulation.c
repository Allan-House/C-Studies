#include <stdio.h>
#include <stdlib.h>

char *string_copy(char *dest, const char *src);
char *string_concat_safe(char* dest, const char *src, size_t dest_size);
int string_compare(const char *str1, const char *str2);

int main() {
    char buffer[50];
    
    string_copy(buffer, "Hello");
    printf("Copied: %s\n", buffer);
    
    string_concat_safe(buffer, ", world!", sizeof(buffer));
    printf("After concat: %s\n", buffer);
    
    printf("Compare with 'Hello, world!': %s\n",
          string_compare(buffer, "Hello, world!") ? "Equal" : "Different");
    return 0;
}

char *string_copy(char *dest, const char *src) {
    char *original_dest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

char *string_concat_safe(char* dest, const char *src, size_t dest_size) {
    char *original_dest = dest;
    size_t dest_len = 0;
    
    while (*dest != '\0' && dest_len < dest_size - 1) {
        dest++;
        dest_len++;
    }
    
    while (*src != '\0' && dest_len < dest_size - 1) {
        *dest = *src;
        dest++;
        src++;
        dest_len++;
    }
    
    *dest = '\0';
    return original_dest;
}


int string_compare(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0') ? 1 : 0;
}

size_t get_string_length(const char *string) {
    size_t length = 0;
    while (*string != '\0') {
        length++;
        string++;
    }
    return length;
}
