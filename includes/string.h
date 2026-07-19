#pragma once
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_LEN 100

size_t string_len(const char *str);
void string_copy(char **dest, const char *src);
int string_comp(const char *a, const char *b);
char string_find_char(const char *a, char c);
int string_find_char_index(const char *a, char c);
char* string_substr(const char *src, const char *substr);
char* string_concat(const char *a, const char *b);
char* string_reverse(const char *src);
int string_starts_with(const char *dest, const char *prefix);
#ifdef __cplusplus
}
#endif