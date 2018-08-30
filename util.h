#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <stdlib.h>

void* safe_malloc(size_t num_bytes);
FILE* safe_fopen(const char* path, const char* mode);
char* new_string(char *s);

#endif
