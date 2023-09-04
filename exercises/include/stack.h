#ifndef STACK_H
#define STACK_H

typedef struct element {
  char value;
  struct element* next;
} Element;


typedef struct stack {
  Element* top;
  int size;
} Stack;

Stack* create_stack();
int empty(Stack* stack);
void push(Stack* stack, char value);
char pop(Stack* stack);
char top(Stack* stack);
int size(Stack* stack);

#endif