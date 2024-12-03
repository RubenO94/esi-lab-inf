#include "string_utils.h"
#include <string.h>
#include <ctype.h>

void split_string(const char *str, char delimiter, char **tokens, size_t *num_tokens) {
    char *temp = strdup(str);
    char *token = strtok(temp, &delimiter);
    size_t count = 0;

    while (token != NULL) {
        tokens[count++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }
    *num_tokens = count;
    free(temp);
}

void trim_whitespace(char *str) {
    char *start = str;
    while (isspace((unsigned char)*start)) start++;
    char *end = start + strlen(start) - 1;
    while (end >= start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    memmove(str, start, end - start + 2);
}
