#include "../includes/string.h"

size_t string_len(const char *str)
{
    if (str == NULL) return 0;

    int len = 0;
    for (int i = 0; str[i] != '\0' && len < MAX_LEN; ++i)
    {
        len++;
    }

    return len;
}

void string_copy(char *dest, const char *src)
{
    int i = 0;
    for (; src[i] != '\0' && i < MAX_LEN; ++i)
    {
        dest[i] = src[i];
    };
    dest[i] = '\0';
}