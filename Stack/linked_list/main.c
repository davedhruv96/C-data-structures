#include "arena.h"
#include "stack.h"

int main() {
  mem_arena *main_arena = arena_create(KiB(1));
  stack *st = stack_create(main_arena);

  if (!st) {
    return -1;
  }
  push(main_arena, st, 1);
  push(main_arena, st, 2);
  printStack(st);
  pop(main_arena, st);
  printStack(st);
  pop(main_arena, st);
  printStack(st);
  stack_destory(main_arena, st);

  arena_destroy(main_arena);

  return 0;
}
