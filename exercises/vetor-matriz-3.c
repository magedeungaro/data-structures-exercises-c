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
    srand(time(NULL) + clock());

    return rand() % 100;
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

int array_length(void* array) {
    return sizeof(array) / sizeof(array[0]);
}

struct Response does_array_include_number(int* array, int number) {
    struct Response response;
    struct ResultMessage result_message = generate_result_message();
    int length = array_length(array);

    for (int i = 0; i < length; i++) {
        if (array[i] == number) {
            response.success = 1;
            sprintf(response.message, result_message.truthy, i);
        }
    }

    response.success = 0;
    response.message = result_message.falsy;

    return response;
}

int main() {
    int* array = generate_random_array(10);
    struct Response response = does_array_include_number(array, get_user_prompt_number());
    print_result_message(response);
    free(array);

    return 0;
}

