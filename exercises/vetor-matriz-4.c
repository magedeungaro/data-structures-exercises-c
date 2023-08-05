#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a matrix with 3x3 dimensions with random values
// Display the sum of each row of the matrix

struct Dimentions {
    int rows;
    int columns;
};

int generate_random_number() {
    return arc4random_uniform(50) + 1;
}

struct Dimentions matrix_dimentions() {
    struct Dimentions dimentions;
    dimentions.rows = 3;
    dimentions.columns = 3;
    return dimentions;
}

char* line_sum_message() {
    return "Line %d has sum of %d. \n";
}

int* generate_random_matrix(struct Dimentions dimentions) {
    int* matrix = malloc(sizeof(int) * dimentions.rows * dimentions.columns);

    for (int i = 0; i < dimentions.rows; i++) {
        for (int j = 0; j < dimentions.columns; j++) {
            *(matrix + i * dimentions.columns + j) = generate_random_number();
        }
    }

    return matrix;
}

void print_matrix_values(int* matrix, struct Dimentions dimentions) {
    for (int i = 0; i < dimentions.rows; i++) {
        for (int j = 0; j < dimentions.columns; j++) {
            printf("%d ", *(matrix + i * dimentions.columns + j));
        }

        printf("\n");
    }
}

void print_sum_each_matrix_line(int* matrix, struct Dimentions dimentions) {
    for (int i = 0; i < dimentions.rows; i++) {

        int sum = 0;

        for (int j = 0; j < dimentions.columns; j++) {
            sum += *(matrix + i * dimentions.columns + j);
        }

        printf(line_sum_message(), i + 1, sum);
    }
}

int main() {
    struct Dimentions dimentions = matrix_dimentions();
    int* matrix = generate_random_matrix(dimentions);
    print_matrix_values(matrix, dimentions);
    print_sum_each_matrix_line(matrix, dimentions);
    free(matrix);

    return 0;
}