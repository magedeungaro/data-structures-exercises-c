#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Response {
    int success;
    char* message;
};

struct ResultMessage {
    char* truthy;
    char* falsy;
};

struct ResultMessage generate_result_message(void) {
    struct ResultMessage result_message;
    result_message.truthy = "The number is in the array and its index is %d.";
    result_message.falsy = "The number is not in the array.";

    return result_message;
}

void print_result_message(struct Response result) {
    printf("%s\n", result.message);
}

int generate_random_number() {
    return arc4random_uniform(50) + 1;
}

int* generate_random_array(int size) {
    int* array = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        array[i] = generate_random_number();
    }
    
    return array;
}

int get_user_prompt_number() {
    int number;
    printf("Enter a number to search: ");
    scanf("%d", &number);

    return number;
}

struct Response does_array_include_number(int* array, int length, int number) {
    struct Response response;
    struct ResultMessage result_message = generate_result_message();

    response.success = 0;
    response.message = malloc(sizeof(char) * 100);

    for (int i = 0; i < length; i++) {
        if (array[i] == number) {
            response.success = 1;
            sprintf(response.message, result_message.truthy, i);
            break;
        }
    }

    if (!response.success) {
        response.message = result_message.falsy;
    }

    return response;
}

void print_array_values(int* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int array_length() {
    return 10;
}

int main() {
    int length = array_length();
    int* array = generate_random_array(length);
    struct Response response = does_array_include_number(array, length, get_user_prompt_number());
    print_result_message(response);
    print_array_values(array, length);
    free(array);

    return 0;
}

