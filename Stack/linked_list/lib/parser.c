#include "parser.h"
#include "arena.h"
#include "mystring.h"
#include "stack.h"
#include <stdio.h>

DynamicString *getNextStr(DynamicString *s) {
  if (!s || !s->data || s->currentIndex >= s->nullCharIndex) {
    return NULL;
  }

  DynamicString *output = createString(10);
  while (s->data[s->currentIndex] == ' ') {
    s->currentIndex++;
  }
  if (s->data[s->currentIndex] >= '0' && s->data[s->currentIndex] <= '9') {
    while (s->data[s->currentIndex] >= '0' && s->data[s->currentIndex] <= '9') {
      strCharConc(output, s->data[s->currentIndex]);
      s->currentIndex++;
    }
  } else if (s->data[s->currentIndex] == '+' ||
             s->data[s->currentIndex] == '-' ||
             s->data[s->currentIndex] == '*' ||
             s->data[s->currentIndex] == '/') {
    strCharConc(output, s->data[s->currentIndex]);
    s->currentIndex++;
  } else if (s->data[s->currentIndex] == '(' ||
             s->data[s->currentIndex] == ')') {
    strCharConc(output, s->data[s->currentIndex]);
    s->currentIndex++;
  }
  return output;
}

int getPriority(char op) {
  if (op == (char)'*' || op == (char)'/') {
    return 2;
  }
  if (op == (char)'+' || op == (char)'-') {
    return 1;
  } else {
    return 0;
  }
}

int executeTopOperator(mem_arena *value_arena, mem_arena *op_arena,
                       stack *value_stack, stack *op_stack) {
  int op = pop(op_arena, op_stack);
  int value2 = pop(value_arena, value_stack);
  int value1 = pop(value_arena, value_stack);

  if (op == (int)'+') {
    return value1 + value2;
  } else if (op == (int)'-') {
    return value1 - value2;
  } else if (op == (int)'*') {
    return value1 * value2;
  } else if (op == (int)'/') {
    return (value2 != 0) ? (value1 / value2) : (0);
  }
  return -1; // error
}

u32 strToResult(mem_arena *value_arena, mem_arena *op_arena, stack *value_stack,
                stack *op_stack, DynamicString *s) {
  if (!value_arena || !op_arena || !value_stack || !op_stack || !s ||
      !s->data) {
    return -1;
  }

  u32 finalResult = 0;
  while (s->currentIndex < s->nullCharIndex) {
    DynamicString *currentTerm = getNextStr(s);
    char firstChar = currentTerm->data[0];
    if (!currentTerm) {
      return -1;
    }
    if (firstChar >= '0' && firstChar <= '9') {
      push(value_arena, value_stack, parseInt(currentTerm));
    } else if (firstChar == '(') {
      push(op_arena, op_stack, (int)'(');
    } else if (firstChar == ')') {
      while (op_stack->tos->fields.dec != (int)'(') {
        int tempAns =
            executeTopOperator(value_arena, op_arena, value_stack, op_stack);
        push(value_arena, value_stack, tempAns);
      }
      pop(op_arena, op_stack);
    } else if (firstChar == '+' || firstChar == '-' || firstChar == '*' ||
               firstChar == '/') {

      while (op_stack->tos && getPriority((char)op_stack->tos->fields.dec) >=
                                  getPriority(firstChar)) {

        if (!op_stack->tos) {
          break;
        }
        push(value_arena, value_stack,
             executeTopOperator(value_arena, op_arena, value_stack, op_stack));
      }
      push(op_arena, op_stack, (int)firstChar);
    } else {
      return -1;
    }
    destroyString(currentTerm);
  }
  while (op_stack->tos) {
    finalResult +=
        executeTopOperator(value_arena, op_arena, value_stack, op_stack);
  }
  return finalResult;
}
