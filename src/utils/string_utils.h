#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdlib.h>

/**
 * @brief Divide uma string com base num delimitador.
 * @param str String de entrada.
 * @param delimiter Caractere delimitador.
 * @param tokens Array para armazenar os tokens.
 * @param num_tokens Número de tokens encontrados.
 */
void split_string(const char *str, char delimiter, char **tokens, size_t *num_tokens);

/**
 * @brief Remove espaços em branco no início e no fim de uma string.
 * @param str String de entrada.
 */
void trim_whitespace(char *str);

#endif
