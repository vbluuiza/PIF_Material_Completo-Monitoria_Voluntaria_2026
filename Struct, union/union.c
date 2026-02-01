#include <stdio.h>

typedef union {
    int x, y;
} Numero ;

int main() {
    Numero num = {.y = 10};
    printf("X: %d\n", num.x);
    printf("Y: %d\n", num.y);
}