# Carena
Carena is a super simple, type-safe memory arena allocator written in C. It uses macros to provide type-safe allocations and includes a benchmark file for testing.

## Benchmarks

Measured on Linux (Arch), AMD Ryzen, 64-bit. Each test allocates N integers sequentially.
`carena` frees all memory at once via `carena_free`. `malloc` allocates and frees individually.

| Allocations | malloc      | carena     | Speedup |
|-------------|-------------|------------|---------|
| 1,000,000   | 23.407 ms   | 5.596 ms   | 4.18x   |
| 10,000,000  | 224.556 ms  | 50.799 ms  | 4.42x   |
| 100,000,000 | 2153.962 ms | 500.424 ms | 4.30x   |
