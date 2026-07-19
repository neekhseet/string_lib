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

char* string_concat(const char *a, const char *b)
{
    if (!a || !b) return NULL;

    size_t len_a = string_len(a);
    size_t len_b = string_len(b);

    char *res = (char *)malloc(len_a + len_b + 1);
    if (!res) return NULL;

    char *dst = res;
    while (*a != '\0') {
        *dst++ = *a++;
    }

    while (*b != '\0') {
        *dst++ = *b++;
    }

    *dst = '\0';

    return res;
}
char* string_reverse(const char *src)
{
    if (src == NULL) return NULL;
    
    size_t str_len = string_len(src);
    
    char *res = (char *)malloc(sizeof(char) * (str_len + 1));
    if (res == NULL) return NULL;

    for (size_t i = 0; i < str_len; ++i)
    {
        res[i] = src[str_len - 1 - i];
    }
    
    res[str_len] = '\0';
    
    return res;
}

int string_starts_with(const char *dest, const char *prefix)
{
    if (dest == NULL || prefix == NULL) return 0;

    size_t prefix_len = string_len(prefix);
    for (int i = 0; i < prefix_len; ++i)
        if (dest[i] != prefix[i]) return 0;

    return 1;
}