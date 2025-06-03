#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "alloc.h"


void usage() {
    printf("Usage: alloc_test -s max heap size -f test_file\n");
    printf("  -s <size> the maximum heap size in bytes.\n");
    printf("  -f <filename> trace file name with sequence of alloc and free requests\n");
}

int main(int argc, char **argv){
    char op;
    int c, id;
    unsigned int req_size;
    char *trace_filename = "t1.txt";
    FILE *tfd = NULL;

    while ((c = getopt(argc, argv, "s:f:")) != -1) {
        if (c == 'f') {
            trace_filename = strdup(optarg);
        } else if (c == 's') {
            max_heap_size = atoi(optarg);
        } else {
            usage();
            exit(1);
        }
    }

    tfd = fopen(trace_filename, "r");
    if (!tfd) {
        fprintf(stderr, "Couldn't open input file '%s'\n", trace_filename);
        return 1;
    }
    void *mem[128] = {NULL}; // never any more than 128 requests in the file.
    // read the request from each line of the file
    while (fscanf(tfd, "%c %d %d", &op, &req_size, &id) != EOF) {
        if (op == 'a') {
            mem[id] = my_alloc(req_size);
            printf("allocated %d id %d\n", req_size, id);
        } else if (op == 'f') {
            my_free(mem[id]);
            printf("free id %d\n", id);
            mem[id] = NULL;
        } else if (op == 'c') {
            count_heap_blks();
        }
    }

    return 0;
}