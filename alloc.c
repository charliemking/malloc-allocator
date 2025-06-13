// Completed the code required in the functions below to implement a segregated memory allocator.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alloc.h"

int max_heap_size = 1024;  // default is a 1K heap (pretty small)

void *heap[4] = {NULL,NULL,NULL,NULL}; // the heap bins for each segregated size 8,16,32,64

unsigned int heap_size = 0; // A variable that keeps track of total size of the heap

const unsigned int bytes[4] = {8, 16, 32, 64};

// allocate_slab uses the default malloc library to allocate memory
// input: size in bytes of slab to allocate
// return: pointer to slab allocated, NULL if allocation would cause the heap to exceed max_heap_size
void *allocate_slab(unsigned int size) {
    if (heap_size + size > max_heap_size) return NULL;

    void* mem = malloc(size);
    if (!mem) return NULL;
    heap_size += size;
    return mem;
}

// Returns a pointer to a heap block of the appropriate
// size.
// If no suitable block exists in the selected bin's free list, this function calls
// allocate_slab to get space NUM_HEAP_BLOCKS blocks of the
// bin's defined size and places them on the bin's free list, then returns
// one of them.
int findSize(unsigned int size){
    for (int i = 0; i < 4; i++) {
        if (size <= bytes[i]) {
            return i;
        }
    }
    printf("Malloc failed, out of memory!\n");
    exit(0);
}

void *my_alloc(unsigned int size) {
    if (size == 0) return NULL;

    int index = findSize(size);
    blk_header_t* block = (blk_header_t*)heap[index];
    if (block) {
        heap[index] = block->next;
        return (void*)((char*)block + sizeof(blk_header_t));
    }
    else {
        unsigned int blockSize = bytes[index];
        
        void* slab = allocate_slab((sizeof(blk_header_t) + blockSize) * NUM_HEAP_BLOCKS);
        if (!slab) {
            printf("Malloc failed, out of memory!\n");
            exit (0);
        }

        for (int i = 0; i < NUM_HEAP_BLOCKS; i++) {
            blk_header_t* block = (blk_header_t*)((char*)slab + i * (sizeof(blk_header_t) + blockSize));
            block->size = blockSize;
            block->next = heap[index];
            heap[index] = (void*)block;
        }

        blk_header_t* allocatedBlock = (blk_header_t*)(heap[index]);
        heap[index] = allocatedBlock->next;

        return (void*)((char*)allocatedBlock + sizeof(blk_header_t));

    }
    //return NULL;
}

void my_free(void *ptr) {
    blk_header_t* block = (blk_header_t*)((char*)ptr - sizeof(blk_header_t));
    int index = findSize(block->size);
    block->next = heap[index];
    heap[index] = (void*)block;
    block->size = 0;
    return;
}
