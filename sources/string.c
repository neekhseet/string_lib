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

void string_copy(char **dest, const char *src)
{
    size_t src_len = string_len(src);
    if (src_len <= 0 ) return;

    char *temp = realloc(*dest, src_len + 1);
    if (temp == NULL) return;
    *dest = temp;

    int i = 0;
    for (; src[i] != '\0' && i < MAX_LEN; ++i)
    {
        (*dest)[i] = src[i];
    };
    
    (*dest)[i] = '\0';
}

int string_comp(const char *a, const char *b)
{
    if (a == NULL || b == NULL) return 0;
    if (a == NULL) return -1;
    if (b == NULL) return 1;

    int i = 0;

    while(a[i] != '\0' && a[i] == b[i] && i < MAX_LEN)
    {
        i++;
    }

    if (i == MAX_LEN) return 0;

    if (a[i] > b[i])
    {
        return 1;
    } else if (a[i] < b[i])
    {
        return -1;
    }

    return 0;
}