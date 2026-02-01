#include <stdio.h>

int main() {

    int ascending = 1;
    int* ptr = &ascending;
    int** ptr_ptr = &ptr;

    printf("Memory address of variable ascending is equal to: %p.\n", &ascending);
    printf("The value assigned to the variable ascending is: %d.\n", ascending);

    printf("\n");
    
    printf("ptr is pointing to the ascending memory address: %p.\n", ptr);
    printf("Memory address of variable ptr is equal to: %p.\n", &ptr);
    printf("The value assigned to the variable ptr is: %d.\n", *ptr);
    
    printf("\n");
    printf("ptr_ptr is pointing to the ascending memory address: %p.\n", ptr_ptr);
    printf("Memory address of variable ptr_ptr is equal to: %p.\n", &ptr_ptr);
    printf("The value assigned to the variable ptr_ptr is: %d.\n", **ptr_ptr);

    return 0;
}