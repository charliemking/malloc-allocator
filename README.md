# Custom Memory Allocator (malloc clone)

A simplified memory allocator written in C using segregated free lists and slab allocation.

## Overview
Implements `my_alloc()` and `my_free()` as drop-in replacements for `malloc()` and `free()`. 
Designed for small, fixed-size allocations using four size bins (8, 16, 32, 64 bytes) and a slab allocator 
to preallocate memory in chunks.

## Features
- Segregated free lists
- Slab allocation to reduce overhead
- Heap size enforcement
- Custom block headers (`blk_header_t`)
- Trace file execution with allocation/deallocation operations

## Usage
Compile with:
```
gcc -Wall -g alloc.c alloc_test.c -o alloc_test
```

Then run with:
```
./alloc_test
```
(Default input: `t1.txt`, with heap size defined inside the trace file or passed interactively.)

## Files
- `alloc.c` — main allocator implementation
- `alloc.h` — header file with block struct and function declarations
- `alloc_test.c` — trace runner for testing memory behavior
- `t3.txt`, `t5.txt`, `t6.txt` — sample trace files for evaluation

## Status
✅ Completed — developed for systems programming coursework (Fall 2024)
