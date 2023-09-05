#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "stack.h"

// Use a stack to see if an expression is balanced, that is,
// if the parentheses, brackets, and braces are balanced.

char* get_expression() {
  char* expression = malloc(sizeof(char) * 100);
  printf("Enter an expression: ");
  scanf("%s", expression);
  
  return expression;
}

int is_opening_bracket(char c) {
  return strchr("([{", c) != NULL;
}

int is_closing_bracket(char c) {
  return strchr(")]}", c) != NULL;
}

int matches_pair(char opening, char closing) {
  switch (opening) {
    case '(': return closing == ')';
    case '[': return closing == ']';
    case '{': return closing == '}';
    default: return 0;
  }
}

int is_balanced(char* expression, Stack* stack) {
  for (int i = 0; i < strlen(expression); i++) {
    if (is_opening_bracket(expression[i])) {
      push(stack, expression[i]);
    }
    else if (is_closing_bracket(expression[i])) {
      if (empty(stack)) {
        return 0;
      }

      char c = pop(stack);
      if (!matches_pair(c, expression[i])) {
        return 0;
      }
    }
  }

  return empty(stack);
}

void print_result(int result) {
  if (result) {
    printf("The expression is balanced.\n");
  } else {
    printf("The expression is not balanced.\n");
  }
}

int main () {
  char* expression = get_expression();
  printf("%s\n", expression);
  Stack* stack = create_stack();
  int result = is_balanced(expression, stack);
  print_result(result);

  free(expression);
  free(stack);

  return 0;
}