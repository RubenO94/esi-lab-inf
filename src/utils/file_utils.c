#include "file_utils.h"
#include <string.h>

int read_line(FILE *fp, char *buffer, size_t size)
{
    if (fgets(buffer, size, fp) == NULL)
    {
        return 0; // EOF ou erro
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove o '\n'
    return 1;
}

FILE *open_file(const char *filename, const char *mode)
{
    FILE *fp = fopen(filename, mode);
    if (!fp)
    {
        perror("Erro ao abrir o ficheiro");
    }
    return fp;
}

int is_file_binary(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        perror("Erro ao abrir o ficheiro");
        return 0;
    }

    unsigned char buffer[512];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    for (size_t i = 0; i < bytes_read; i++)
    {
        if (buffer[i] == 0)
        { // Contém um byte nulo
            return 1;
        }
    }
    return 0;
}

int file_exists(const char *filename)
{
    FILE *file = fopen(filename, "r"); 
    if (file)
    {
        fclose(file);
        return 1;     // Retorna 1 para indicar que o ficheiro existe
    }
    return 0; // Retorna 0 se o ficheiro não puder ser aberto
}
