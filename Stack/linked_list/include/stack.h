#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "arena.h"
#include <iso646.h>
#include <stdbool.h>

typedef struct {
  int dec;
} data;

typedef struct block {
  data fields;
  struct block *link;
} block;

typedef struct {
  block *tos;
} stack;

stack *stack_create(mem_arena *arena);

void stack_destory(mem_arena *arena, stack *st);

void push(mem_arena *arena, stack *st, int value);

int pop(mem_arena *arena, stack *st);

void printStack(stack *st);

int peek(stack *st);

#endif
