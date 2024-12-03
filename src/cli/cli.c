#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cli.h"
#include <stdarg.h>
#include "../utils/file_utils.h"

void print_program_message(const char *program_name, const char *format, ...)
{
  va_list args;
  va_start(args, format);

  printf("%s: ", program_name);
  vprintf(format, args);

  va_end(args);
}

void print_error_message(const char *program_name, const char *format, ...)
{
  va_list args;
  va_start(args, format);

  fprintf(stderr, "%s: Erro: ", program_name);
  vfprintf(stderr, format, args);

  va_end(args);
}

void print_help(const char *program_name)
{
  printf("Uso: %s [opcoes] <ficheiro_utentes> <ficheiro_ementa> <ficheiro_escolhas>\n", program_name);
  printf("Opcoes:\n");
  printf("  -ajuda   Mostra esta mensagem de ajuda e sai.\n");
  printf("  -tab     Usa ficheiros de entrada separados por tabulacao.\n");
  printf("  -bin     Le ficheiros de entrada em modo binario.\n");
  printf("\nSe algum ficheiro for omitido, sera lido a partir do stdin.\n");
}

int validate_args(int argc, const char *argv[], CLIOptions *options)
{
  const char *program_name = argv[0];
  int file_count = 0;

  if (argc < 2)
  {
    print_error_message(program_name, "Argumentos insuficientes. Use -ajuda para mais informacoes.\n");
    return 0;
  }

  options->is_tab = 0;
  options->is_bin = 0;
  options->employees_file = NULL;
  options->menu_file = NULL;
  options->choices_file = NULL;

  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-ajuda") == 0)
    {
      options->show_help = 1;
      // print_help(argv[0]);
      return 1;
    }
    else if (strcmp(argv[i], "-tab") == 0)
    {
      options->is_tab = 1;
    }
    else if (strcmp(argv[i], "-bin") == 0)
    {
      options->is_bin = 1;
    }
    else
    {
      // Validação dos ficheiros de entrada
      switch (file_count)
      {
      case 0:
        options->employees_file = argv[i];
        break;
      case 1:
        options->menu_file = argv[i];
        break;
      case 2:
        options->choices_file = argv[i];
        break;
      default:
        print_error_message(argv[0], "Muitos ficheiros indicados.");
        return 0;
      }
      file_count++;
    }
  }

  // Se o ficheiro não foi especificado nos argumentos, então dá entrada com stdin
  if (!options->employees_file)
    options->employees_file = "stdin";
  if (!options->menu_file)
    options->menu_file = "stdin";
  if (!options->choices_file)
    options->choices_file = "stdin";

  // Check file existence (if not stdin)
  if (strcmp(options->employees_file, "stdin") != 0 && !file_exists(options->employees_file))
  {
    print_error_message(argv[0], "Erro: Ficheiro '%s' nao existe", options->employees_file);
    // printf("%s: Error: File '%s' does not exist.\n", program_name, options->employees_file);
    return 0;
  }
  if (strcmp(options->menu_file, "stdin") != 0 && !file_exists(options->menu_file))
  {
    print_error_message(argv[0], "Erro: Ficheiro '%s' nao existe", options->menu_file);
    return 0;
  }
  if (strcmp(options->choices_file, "stdin") != 0 && !file_exists(options->choices_file))
  {
    print_error_message(argv[0], "Erro: Ficheiro '%s' nao existe", options->choices_file);
    return 0;
  }

  return 1;
}