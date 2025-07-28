# Custom Memory Allocator in C (malloc/free clone)

This project implements a custom dynamic memory allocator in C as a drop-in replacement for `malloc()` and `free()`. It uses slab allocation and segregated free lists to manage memory in fixed-size bins, enforcing a strict heap size cap for predictable usage.

---

## Features

- `myAlloc(size_t size)` and `myFree(void *ptr)` mimic standard memory allocation behavior
- Segregated free lists for efficient management of small allocations
- Slab allocator design with fixed-size bins (8–64 bytes)
- Heap growth is capped to encourage tight memory discipline

---

## File Structure

malloc-allocator/
├── allocator.c # Core implementation of myAlloc/myFree
├── allocator.h # Interface
├── test.c # Test cases for validation
└── README.md
