#include <stdio.h>

int sum(int* arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}
int main() {
    int ascending[4] = {1, 2, 3, 4};
    int triangle = sum(ascending, 4);

    printf("\nSum (triangle): %d\n", triangle);
}