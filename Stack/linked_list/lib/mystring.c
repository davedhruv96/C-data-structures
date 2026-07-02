#include "mystring.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct DynamicString {
  char *data;
  u64 nullCharIndex;
  u64 capacity;
  u64 currentIndex;
};

DynamicString *createString(u64 initial_size) {
  DynamicString *s = malloc(sizeof(DynamicString));
  if (!s) {
    return NULL;
  }

  s->data = malloc(initial_size);
  if (!s->data) {
    free(s);
    return NULL;
  }
  s->capacity = initial_size;
  s->nullCharIndex = 0;
  s->data[0] = '\0';
  s->currentIndex = 0;
  return s;
}

int getstring(DynamicString *s) {
  u64 i = 0;
  while (1) {
    if (i == s->capacity - 1) {
      if (!ensureCapacity(s, s->capacity * 2)) {
        printf("Memory allocation failed!");
        return -1;
      }
      continue;
    }
    if (scanf("%c", &s->data[i]) == EOF) {
      s->data[i] = '\0';
      s->nullCharIndex = i;
      return 0;
    }
    if (i == 0 && s->data[i] == '\n') {
      continue;
    }
    if (s->data[i] == '\n') {
      s->data[i] = '\0';
      s->nullCharIndex = i;
      return 0;
    }
    i++;
  }
}

u64 strlength(char *s1) {
  if (s1 == NULL) {
    return 0;
  }
  u64 len = 0;
  while (s1[len] != '\0') {
    len++;
  }
  return len;
}

void strcopy(DynamicString *s1, DynamicString *s2) {
  if (s1->data == NULL || s2->data == NULL) {
    return;
  }
  u64 i;
  if (ensureCapacity(s1, s2->nullCharIndex + 1)) {
    for (i = 0; i < s2->nullCharIndex; i++) {
      s1->data[i] = s2->data[i];
    }
    s1->data[i] = '\0';
    s1->nullCharIndex = s2->nullCharIndex;
  } else {
    printf("Memory allocation failed!");
  }
}

int strcompare(DynamicString *s1, DynamicString *s2) {
  if (s1->data == NULL && s2->data == NULL) {
    return 1;
  }
  if (s1->nullCharIndex != s2->nullCharIndex) {
    return 0;
  } else {
    for (u64 i = 0; i < s1->nullCharIndex; i++) {
      if (s1->data[i] != s2->data[i]) {
        return 0;
      }
    }
  }
  return 1;
}

void strcats(DynamicString *s1, DynamicString *s2) {
  if (s2 == NULL) {
    return;
  }
  if (ensureCapacity(s1, s1->nullCharIndex + s2->nullCharIndex + 1)) {
    u64 i;
    for (i = 0; i < s2->nullCharIndex; i++) {
      s1->data[s1->nullCharIndex + i] = s2->data[i];
    }
    s1->data[s1->nullCharIndex + i] = '\0';
    s1->nullCharIndex += i;
  } else {
    printf("Memory allocation failed!");
    return;
  }
}

void strncats(DynamicString *s1, DynamicString *s2, u64 n) {
  if (s2 == NULL) {
    return;
  }

  u64 i;
  u64 toAdd = (s2->nullCharIndex < n) ? s2->nullCharIndex : n;
  if (ensureCapacity(s1, s1->nullCharIndex + toAdd + 1)) {
    for (i = 0; i < n && s2->data[i] != '\0'; i++) {
      s1->data[s1->nullCharIndex + i] = s2->data[i];
    }
    s1->data[s1->nullCharIndex + i] = '\0';
    s1->nullCharIndex += i;
  } else {
    printf("Memory allocation failed!");
    return;
  }
}

void strreverse(DynamicString *s) {
  if (s->data == NULL) {
    return;
  }
  char temp;
  for (u64 i = 0; i < (s->nullCharIndex) / 2; i++) {
    temp = s->data[i];
    s->data[i] = s->data[s->nullCharIndex - i - 1];
    s->data[s->nullCharIndex - i - 1] = temp;
  }
}

void strlower(DynamicString *s) {
  if (s->data == NULL) {
    return;
  }
  for (int i = 0; s->data[i] != '\0'; i++) {
    if (s->data[i] >= 'A' && s->data[i] <= 'Z') {
      s->data[i] += 32;
    }
  }
}

void strupper(DynamicString *s) {
  if (s->data == NULL) {
    return;
  }
  for (int i = 0; s->data[i] != '\0'; i++) {
    if (s->data[i] >= 'a' && s->data[i] <= 'z') {
      s->data[i] -= 32;
    }
  }
}

void printString(DynamicString *s) {
  if (!s || !s->data) {
    return;
  }
  printf("%s\n", s->data);
}

int ensureCapacity(DynamicString *s, u64 new_capacity) {
  if (s->capacity >= new_capacity) {
    return 1;
  }

  char *temp = realloc(s->data, new_capacity);
  if (temp == NULL) {
    return 0;
  }

  s->data = temp;
  s->capacity = new_capacity;

  return 1;
}

void destroyString(DynamicString *s) {
  if (s) {
    free(s->data);
    free(s);
  }
}

void strCharConc(DynamicString *s, char charToConc) {
  if (!s || !s->data) {
    return;
  }

  if (ensureCapacity(s, s->nullCharIndex + 1)) {
    s->data[s->nullCharIndex] = charToConc;
    s->nullCharIndex++;
    s->data[s->nullCharIndex] = '\0';
  }
  return;
}

u32 charToInt(char ch) {
  if (ch >= '0' && ch <= '9') {
    // switch case??
    if (ch == '0') {
      return (u32)0;
    } else if (ch == '1') {
      return (u32)1;
    } else if (ch == '2') {
      return (u32)2;
    } else if (ch == '3') {
      return (u32)3;
    } else if (ch == '4') {
      return (u32)4;
    } else if (ch == '5') {
      return (u32)5;
    } else if (ch == '6') {
      return (u32)6;
    } else if (ch == '7') {
      return (u32)7;
    } else if (ch == '8') {
      return (u32)8;
    } else if (ch == '9') {
      return (u32)9;
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}

u32 parseInt(DynamicString *s) {
  if (!s || !s->data) {
    return -1;
  }
  u32 finalInt = 0, carry = 0;
  // trim
  for (u32 i = 0; i < s->nullCharIndex; i++) {
    if (s->data[i] >= '0' && s->data[i] <= '9') {
      carry = charToInt(s->data[i]);
      finalInt = finalInt * 10 + carry;
    } else {
      return -1;
    }
  }
  return finalInt;
}
