#include "../includes/string.h"

size_t string_len(const char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len++;
    }

    return len;
}