#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "arena.h"
#include <stdbool.h>

typedef struct stack stack;
typedef struct block block;
typedef struct data data;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef i8 b8;
typedef i32 b32;

#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)

stack *stack_create(mem_arena *arena);

void stack_destory(mem_arena *arena, stack *st);

void push(mem_arena *arena, stack *st, int value);

int pop(mem_arena *arena, stack *st);

void printStack(stack *st);

#endif
