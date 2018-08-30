#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* safe_malloc(size_t num_bytes)
{
    void* ptr = malloc(num_bytes);
    if (ptr == NULL) {
            printf("ERROR: malloc(%lu)\n", num_bytes);
            exit(EXIT_FAILURE);
    }
    memset(ptr,0,num_bytes);
    return ptr;
}

FILE* safe_fopen(const char* path, const char* mode)
{
    FILE* fp = fopen(path, mode);
    if (fp == NULL) {
        printf("ERROR: %s not exist!\n",path);
        exit(EXIT_FAILURE);
    }
    return fp;
}

char *new_string(char *s){
    int len = strlen(s);
    char *ns = safe_malloc(len+1);
    memcpy(ns, s, len+1);
    return ns;
}
