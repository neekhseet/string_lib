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

char string_find_char(const char *a, char c)
{
    if (a == NULL) return '\0';

    for (int i = 0; a[i] != '\0' && i < MAX_LEN; ++i)
    {
        if (a[i] == c)
        {
            return c;
        }
    }

    return '\0';
}

int string_find_char_index(const char *a, char c)
{
    if (a == NULL) return -1;

    for (int i = 0; a[i] != '\0' && i < MAX_LEN; ++i)
    {
        if (a[i] == c) return i;
    }

    return -1;
}

char* string_substr(const char *src,const char *substr)
{
    if (src == NULL || substr == NULL) return NULL;
    if (substr[0] == '\0') return NULL;

    size_t substr_len = string_len(substr);

    for (int i = 0; src[i] != '\0' && i < MAX_LEN; ++i)
    {   
        int j = 0;
        while (src[i + j] == substr[j] && substr[j] != '\0' && (i + j) < MAX_LEN) {
            ++j;
        }

        if (j == substr_len) {
            char *res = (char *)calloc(substr_len + 1, sizeof(char));
            if (res == NULL) return NULL;

            for (int k = 0; k < substr_len; ++k) {
                res[k] = src[i + k];
            }
            
            return res;
        }
    }
    return NULL;
}
