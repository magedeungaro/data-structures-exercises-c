#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

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
