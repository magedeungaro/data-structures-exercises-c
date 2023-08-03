#include <stdio.h>

// Create an integer vector with 10 positions with the following values:
// 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
// User for loop to print its values

int main() {
    int integers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (int i = 0; i < 10; i++) {
        printf("%d\n", integers[i]);
    }

    return 0;
}
