#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Check if a word or a number is a palindrome using a stack
// Hint: Stack it. In each pop, verify it against the word or number.

char* word_to_check() {
  char* word = malloc(sizeof(char) * 100);
  printf("Enter a word to check if it is a palindrome: ");
  scanf("%s", word);

  return word;
}

void stack_word(char* word, Stack* stack) {
  for (int i = 0; i < strlen(word); i++) {
    push(stack, word[i]);
  }
}

int validate_stack(char* word, Stack* stack) {
  return stack->size == strlen(word);
}

int is_palindrome(char* word, Stack* stack) {
  if (!validate_stack(word, stack)) {
    printf("There was a problem while stacking the word.\n");
  }

  for (int i = 0; i < strlen(word); i++) {
    if (pop(stack) != word[i]) {
      return 0;
    }

    return 1;
  }
}

void print_result(int result) {
  if (result) {
    printf("The word is a palindrome.\n");
  } else {
    printf("The word is not a palindrome.\n");
  }
}

int main () {
  char* word = word_to_check();
  Stack* stack = create_stack();

  stack_word(word, stack);
  int result = is_palindrome(word, stack);
  printf("The chosen word is: %s\n", word);
  print_result(result);
  free(word);
  free(stack);
  
  return 0;
}