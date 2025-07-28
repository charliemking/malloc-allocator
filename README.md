# Custom Memory Allocator in C (malloc/free clone)

This project implements a custom dynamic memory allocator in C as a drop-in replacement for `malloc()` and `free()`. It uses slab allocation and segregated free lists to manage memory in fixed-size bins, enforcing a strict heap size cap for predictable usage.

---

## Features

- `my_alloc()` and `my_free()` mimic standard memory allocation behavior
- Segregated free lists for efficient management of small allocations
- Slab allocator design with fixed-size bins (8–64 bytes)
- Heap growth is capped to encourage tight memory discipline

---

## File Structure

malloc-allocator/
├── alloc.c # Core implementation of myAlloc/myFree
├── alloc.h # Interface
├── t.txt # Test cases for validation
└── README.md
