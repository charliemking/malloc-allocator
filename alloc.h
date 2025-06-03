#ifndef _ALLOC
#define _ALLOC

extern void *my_alloc(unsigned int size);
extern void my_free(void *ptr);

extern int max_heap_size;

extern void *heap[4];

typedef struct blk_header {
    unsigned int size;
    void *next;
} blk_header_t;

// utility functions
extern void print_bin(int bin);
extern void print_heap();
extern void count_heap_blks();

#define NUM_HEAP_BLOCKS 8

#endif