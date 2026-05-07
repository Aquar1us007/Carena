#pragma once

#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdalign.h>

typedef struct CArena
{
    unsigned char *base;
    size_t offset;
    size_t capacity;
} CArena;

CArena carena_create(size_t size_in_bytes);
CArena carena_create_zeroed(size_t size_in_bytes);
void *carena_alloc(CArena *arena, size_t size, size_t align);
void carena_clear(CArena *arena);
void carena_reset(CArena *arena);
void carena_free(CArena *arena);

// ==== Macros ====
#define CARENA_PUSH(arena, T) \
    (T*)carena_alloc(arena, sizeof(T), alignof(T))

#define CARENA_PUSH_ARRAY(arena, T, n) \
    (T*)carena_alloc(arena, sizeof(T) * (n), alignof(T))
// End of file!
