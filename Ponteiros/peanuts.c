#include <stdio.h>

int argmax(int array[], int length) {
    int max_index = 0;
    for (int i = 1; i < length; i++) {
        if (array[max_index] < array[i]) {
            max_index = i;
        }
    }
    return max_index;
}

int getLastBox(int peanutCounts[], int numBoxes, int amount) {
    int max_box = 0;
    while (amount > 0) {
        max_box = argmax(peanutCounts, numBoxes);
        peanutCounts[max_box]--;
        amount--;
    }
    return max_box;
}

int main() {
    int peanutCounts[2] = {5, 6};
    int last_box = getLastBox(peanutCounts, 2, 2);
    printf("The hamster ends on box %d.\n", last_box);

    return 0;
} 