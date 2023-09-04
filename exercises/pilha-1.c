#include <stdio.h>
#include <stdlib.h>

// Starting from an empty stack

// Steps:
// 1. pop()
// 2. push(p, 'a')
// 3. push(p, 'c')
// 4. top()
// 5. size()
// 6. push(p, 'g')
// 7. pop()
// 8. push(p, 'm')
// 9. pop()
// 10. top()
// 11. pop()
// 12. pop()
// 13. empty()

// Questions:
// a) What is the return of step 1?
// b) What is the return of step 4?
// c) What is the return of step 5?
// d) What is the return of step 10?
// e) What is the return of step 13?

typedef struct element {
  char value;
  struct element* next;
} Element;


typedef struct stack {
  Element* top;
  int size;
} Stack;

Stack* create_stack() {
  Stack* stack = malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

int empty(Stack* stack) {
  return stack->size == 0;
}

void push(Stack* stack, char value) {
  Element* element = malloc(sizeof(Element));
  element->value = value;
  element->next = stack->top;
  stack->top = element;
  stack->size++;
}

char pop(Stack* stack) {
  if (empty(stack)) {
    return '\0';
  }

  Element* element;
  char c;

  element = stack->top;
  c = element->value;
  stack->top = element->next;
  free(element);
  element = NULL;
  stack->size--;

  return c;
}

int size(Stack* stack) {
  return stack->size;
}

char top(Stack* stack) {
  if (empty(stack)) {
    return '\0';
  }

  return stack->top->value;
}

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