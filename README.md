# Custom Malloc Allocator

I implemented a custom memory allocator in C that mimics the behavior of `malloc` and `free`. It uses segregated free lists and slab allocation to manage memory across bins (8–64 bytes) with strict heap limits. This was one of my most technically challenging projects and helped me deeply understand systems programming and performance optimization.