#include "stack.h"
#include <stdio.h>

struct data {
  int dec;
};

struct stack {
  block *tos;
};

struct block {
  struct data fields;
  block *link;
};

stack *stack_create(mem_arena *arena) {
  stack *main_stack = (stack *)arena_push(arena, (u64)sizeof(stack));

  if (!main_stack) {
    return NULL;
  }
  main_stack->tos = NULL;

  return main_stack;
}

void stack_destory(mem_arena *arena, stack *st) {
  if (!st) {
    return;
  }
  while (st->tos) {
    pop(arena, st);
  }
  arena_pop(arena, (u64)sizeof(stack));
}

void push(mem_arena *arena, stack *st, int value) {
  block *new_block = (block *)arena_push(arena, (u64)sizeof(block));
  if (!new_block) {
    return;
  }

  new_block->fields.dec = value; // the actual data, should be modified for the
  // data that is to be stored
  new_block->link = st->tos;
  st->tos = new_block;
}

int pop(mem_arena *arena, stack *st) {
  data temp;
  temp.dec = 0;
  if (st) {
    if (st->tos) {
      temp = st->tos->fields;
      st->tos = st->tos->link;
      arena_pop(arena, (u64)sizeof(block));
    }
  }
  return temp.dec;
}

void printStack(stack *st) {
  if (!st) {
    return;
  }
  printf("[");

  if (!st->tos) {
    printf("]\n");
    return;
  }
  block *traverse = st->tos;
  while (traverse) {
    printf("%d", traverse->fields.dec);
    if (traverse->link) {
      printf(", ");
    }
    traverse = traverse->link;
  }
  printf("]\n");
}
