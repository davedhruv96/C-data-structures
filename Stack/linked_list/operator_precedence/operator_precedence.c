#include "arena.h"
#include "mystring.h"
#include "parser.h"
#include "stack.h"
#include <inttypes.h>
#include <stdio.h>

int main() {
  mem_arena *value_arena = arena_create(KiB(1));
  mem_arena *op_arena = arena_create(KiB(1));

  stack *value_stack = stack_create(value_arena);
  stack *op_stack = stack_create(op_arena);
  DynamicString *input = createString(10);
  printf("Enter all the terms to be solved: ");
  getstring(input);

  printf("Answer of given equation is %" PRIu32 "\n",
         strToResult(value_arena, op_arena, value_stack, op_stack, input));

  destroyString(input);
  stack_destory(value_arena, value_stack);
  stack_destory(op_arena, op_stack);
  arena_destroy(value_arena);
  arena_destroy(op_arena);
  return 0;
}
