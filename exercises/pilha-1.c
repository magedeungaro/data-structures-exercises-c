#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
  char c;
  int value;

  Stack* stack = create_stack();
  // step 1
  c = pop(stack);
  printf("Question a: %c\n", c);
  // step 2
  push(stack, 'a');
  // step 3
  push(stack, 'c');
  // step 4
  c = top(stack);
  printf("Question b: %c\n", c);
  // step 5
  value = size(stack);
  printf("Question c: %d\n", value);
  // step 6
  push(stack, 'g');
  // step 7
  pop(stack);
  // step 8
  push(stack, 'm');
  // step 9
  pop(stack);
  // step 10
  c = top(stack);
  printf("Question d: %c\n", c);
  // step 11
  pop(stack);
  // step 12
  pop(stack);
  // step 13
  value = empty(stack);
  printf("Question e: %d\n", value);

  return 0;
}