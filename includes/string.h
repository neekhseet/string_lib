#pragma once
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_LEN 100

size_t string_len(const char *str);
void string_copy(char **dest, const char *src);

#ifdef __cplusplus
}
#endif