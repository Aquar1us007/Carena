#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "test.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("The program requires the following argument: n_allocations(positive integer!)\n");
        return 1;
    }

    printf("The following arguments were provided:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    if (argc <= 2)
    {
        // No args:
        int n_allocations = 0;

        char *end = NULL;
        long parsed = strtol(argv[1], &end, 10);

        if (end == argv[1])
        {
            printf("Invalid number passed as argument!\n");
            return 1;
        }
        if (*end != '\0')
        {
            printf("Invalid characters in the number!\n");
            return 1;
        }

        if (parsed <= 0)
        {
            printf("The number must be a positive integer!\n");
            return 1;
        }

        n_allocations = (int)parsed;

        // Run benchmark:
        printf("Pool allocations:\n");
        bench_carena(n_allocations);
        printf("Malloc allocations:\n");
        bench_malloc(n_allocations);
        return 0;
    }
    else

    return 0;
}
