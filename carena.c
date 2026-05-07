#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

#include "carena.h"

// The function does not perform error checking on the base.
CArena carena_create(size_t size_in_bytes)
{
    CArena new_arena = (CArena){
        .base = malloc(size_in_bytes),
        .capacity = size_in_bytes,
        .offset = 0
    };

    return new_arena;
}

CArena carena_create_zeroed(size_t size_in_bytes)
{
    CArena new_arena = (CArena){
        .base = calloc(1, size_in_bytes),
        .capacity = size_in_bytes,
        .offset = 0
    };

    return new_arena;
}

// Returns NULL if the new element does not fit!
void *carena_alloc(CArena *arena, size_t size, size_t align)
{
    if (!arena || !arena->base) return NULL;

    uintptr_t current = (uintptr_t)arena->base + arena->offset;
    uintptr_t aligned = (current + (align - 1)) & ~(align - 1); // ~(align - 1) Rounds down! 
    size_t padding = aligned - current;

    if (arena->offset + padding + size > arena->capacity)
        return NULL;

    arena->offset += padding + size;

    return (void*)aligned;
}

void carena_clear(CArena *arena)
{
    if (!arena || !arena->base)
        return;

    memset(arena->base, 0, arena->capacity);
    arena->offset = 0;
}

// Sets the offset to 0!
void carena_reset(CArena *arena)
{
    if (!arena) return;

    arena->offset = 0;
}

void carena_free(CArena *arena)
{
    if (!arena) return;

    if (arena->base) free(arena->base);
    arena->capacity = 0;
    arena->offset = 0;
}