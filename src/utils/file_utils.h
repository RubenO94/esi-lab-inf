#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Lê uma linha de um ficheiro.
 * @param fp Ponteiro para o ficheiro.
 * @param buffer Buffer para armazenar a linha.
 * @param size Tamanho do buffer.
 * @return 1 se for bem-sucedido, 0 se alcançar o EOF.
 */
int read_line(FILE *fp, char *buffer, size_t size);

/**
 * @brief Abre um ficheiro no modo especificado.
 * @param filename Nome do ficheiro.
 * @param mode Modo de abertura ("r", "w", "rb", etc.).
 * @return Ponteiro para o ficheiro ou NULL em caso de erro.
 */
FILE *open_file(const char *filename, const char *mode);

/**
 * @brief Verifica se um ficheiro é binário.
 * @param filename Nome do ficheiro.
 * @return 1 se for binário, 0 caso contrário.
 */
int is_file_binary(const char *filename);

/**
 * @brief Verifica se o ficheiro existe.
 * @param filename Nome do ficheiro.
 * @return 1 se o ficheiro existir, 0 caso contrário.
 */
int file_exists(const char *filename);


#endif
