# Custom Memory Allocator (malloc clone)

A simplified memory allocator written in C using segregated free lists and slab allocation.

## Overview
Implements `my_alloc()` and `my_free()` as drop-in replacements for `malloc()` and `free()`. Designed for small, fixed-size allocations using four size bins (8, 16, 32, 64 bytes) and a slab allocator to preallocate memory in chunks.

## Features
- Segregated free lists
- Slab allocation to reduce overhead
- Manual heap size enforcement
- Custom block headers

## Usage
Compile and link `alloc.c` and `alloc.h` with your project. See `test_alloc.c` for usage examples.

## Status
✅ Completed — used in systems programming coursework (Fall 2024)
