#ifndef PARSER_H
#define PARSER_H

#include "arena.h"
#include "mystring.h"
#include "stack.h"

u32 strToResult(mem_arena *, mem_arena *, stack *, stack *, DynamicString *);

DynamicString *getNextStr(DynamicString *);

u32 charToInt(char);

int getPriority(char);

int executeTopOperator(mem_arena *, mem_arena *, stack *, stack *);

#endif
