#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>

#include "carena.h"

void bench_carena(int n)
{
    CArena arena = carena_create(sizeof(int) * n);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < n; i++)
    {
        int *x = CARENA_PUSH(&arena, int);
        *x = i;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1e6;

    printf("carena: %d allocations: %.3f ms\n", n, ms);
    carena_free(&arena);
}

void bench_malloc(int n)
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int **ptrs = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
    {
        ptrs[i] = malloc(sizeof(int));
        *ptrs[i] = i;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    for (int i = 0; i < n; i++)
        free(ptrs[i]);
    free(ptrs);

    double ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1e6;
    printf("carena: %d allocations: %.3f ms\n", n, ms);

    clock_gettime(CLOCK_MONOTONIC, &end);
}