#include <stdio.h>

// Create a matrix with 4 rows and 4 columns with the following values:
// a b c d e f g h i j k l m n o p
// and use 2 for loops to print its values

int main() {
    char matrix[4][4] = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}