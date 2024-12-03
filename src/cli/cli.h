#ifndef CLI_H
#define CLI_H

/**
 * @brief Estrutura para armazenar as opções da linha de comando.
 */
typedef struct
{
  int show_help;              // Flag para a opção -ajuda
  int is_tab;                 // Flag para o modo tabulação
  int is_bin;                 // Flag para o modo binário
  const char *employees_file; // Nome do ficheiro de dados dos funcionários
  const char *menu_file;      // Nome do ficheiro de ementa semanal
  const char *choices_file;   // Nome do ficheiro de escolhas dos utentes
} CLIOptions;

/**
 * @brief Exibe uma mensagem formatada que começa com o nome do programa.
 * @param program_name Nome do programa.
 * @param format Formato da mensagem (como printf).
 * @param ... Argumentos variáveis para o formato.
 */
void print_program_message(const char *program_name, const char *format, ...);

/**
 * @brief Exibe uma mensagem de erro formatada que começa com o nome do programa.
 * @param program_name Nome do programa.
 * @param format Formato da mensagem (como printf).
 * @param ... Argumentos variáveis para o formato.
 */
void print_error_message(const char *program_name, const char *format, ...);

/**
 * @brief Função para exibir o menu de ajuda.
 * @param program_name Nome do programa.
 */
void print_help(const char *program_name);

/**
 * @brief Valida os argumentos da linha de comando.
 * @param argc Número de argumentos.
 * @param argv Array de argumentos.
 * @param options Ponteiro para a estrutura CLIOptions.
 * @return 1 se a validação for bem-sucedida, 0 caso contrário.
 */
int validate_args(int argc, const char *argv[], CLIOptions *options);
/**
 * @brief Verifica se uma determinada opção foi passada na linha de comando.
 * @param argc Número de argumentos.
 * @param argv Array de argumentos.
 * @param option Opção a verificar (ex.: "-tab").
 * @return 1 se a opção estiver presente, 0 caso contrário.
 */
int has_option(int argc, char *argv[], const char *option);

#endif
