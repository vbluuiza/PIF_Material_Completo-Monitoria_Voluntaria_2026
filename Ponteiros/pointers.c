#include <stdio.h>

int sum(int* arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int prod(int* arr, int size) {
    int total = 1;
    printf("ARR %p\n", arr);
    for (int* pos = arr; pos < arr + size; pos++) {
        printf("POS %p\n", pos);
        total *= *pos;
    }
    return total;
}

int main() {
    int ascending[4] = {1, 2, 3, 4};
    // int triangle = sum(ascending, 4);
    int factorial = prod(ascending, 4);
    printf("\n");
    printf("%p\n", &ascending[0]);
    printf("%p\n", &ascending[1]);
    printf("%p\n", &ascending[2]);
    printf("%p\n", &ascending[3]);

    // printf("\nSum (triangle): %d\n", triangle);
    printf("Product (factorial): %d\n", factorial);
}