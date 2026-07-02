#ifndef MYSTRING_H
#define MYSTRING_H
#include "arena.h"
#include <stdint.h>

typedef struct {
  char *data;
  u64 nullCharIndex;
  u64 capacity;
  u64 currentIndex;
} DynamicString;

int getstring(DynamicString *s); // returns 0 for success, -1 if malloc fails
void printString(DynamicString *s);

// core functions, almost same as original just more safe ;)
u64 strlength(char *);
void strcopy(DynamicString *, DynamicString *);
int strcompare(DynamicString *, DynamicString *);
void strcats(DynamicString *, DynamicString *);
void strncats(DynamicString *, DynamicString *, u64);
void strreverse(DynamicString *);
void strlower(DynamicString *);
void strupper(DynamicString *);

// funcitons not present in string.h
void strCharConc(DynamicString *, char);
u32 parseInt(DynamicString *);
u32 charToInt(char);
// main memory capacity checker
int ensureCapacity(DynamicString *, u64);

// constructor destructor
DynamicString *createString(u64 initial_size);
void destroyString(DynamicString *s);

#endif
