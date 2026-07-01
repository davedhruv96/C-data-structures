#include <arena.h>
#include <stdlib.h>

struct mem_arena {
  u8 *buffer;
  u64 capacity;
  u64 offset;
};

mem_arena *arena_create(u64 size) {
  mem_arena *arena = (mem_arena *)malloc(sizeof(mem_arena));
  arena->buffer = (u8 *)malloc(size);
  if (!arena->buffer) {
    return NULL;
  }
  arena->capacity = size;
  arena->offset = 0;
  return arena;
}

u64 align_offset(u64 currentOffset, u64 alignment) {
  return (currentOffset + (alignment - 1)) & ~(alignment - 1);
}

void *arena_push(mem_arena *arena, u64 size) {

  u64 currentOffset = align_offset(arena->offset, sizeof(void *));
  if (currentOffset + size > arena->capacity) {
    return NULL;
  }
  void *ptr = arena->buffer + currentOffset;

  arena->offset = currentOffset + size;
  return ptr;
}

void arena_pop(mem_arena *arena, u64 size) {
  size = MIN(size, arena->offset);
  arena->offset -= size;
}

void arena_clear(mem_arena *arena) { arena->offset = 0; }

void arena_destroy(mem_arena *arena) {
  free(arena->buffer);
  arena = NULL;
}
