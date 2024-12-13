/**
 * @file main.c
 * @author Raúl Ribeiro ({a22552@alunos.ipca.pt}) | Rúben Oliveira ({a24861@alunos.ipca.pt})
 * @brief The main application file.
 * @version 0.1
 * @date 2024-11-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/file_utils.h"
#include "utils/string_utils.h"
#include "cli/cli.h"
#include "models/employee.h"
#include "models/menu.h"

int main(int argc, char const *argv[])
{
  CLIOptions options;
  Employee employees[100];
  int employee_count;

  // Valida os argumentos de entrada.
  // Se não forem válidos, mostra o menu principal.
  if (!validate_args(argc, argv, &options))
  {
    // TODO: Menu de opções;
    // TODO: Se a entrada for Stdin então processar a informação;
    // Initialize the data (for example)
  }

  // Mostra a ajuda se solicitado
  if (options.show_help)
  {
    print_help(argv[0]);
    return 0;
  }

  // Exibe as opcoes para debug
  printf("Opcoes:\n");
  printf("  Separados por tabulacao: %s\n", options.is_tab ? "Sim" : "Nao");
  printf("  Modo binario: %s\n", options.is_bin ? "Sim" : "Nao");
  printf("Ficheiros:\n");
  printf("  Ficheiro de utentes: %s\n", options.employees_file);
  printf("  Ficheiro da ementa: %s\n", options.menu_file);
  printf("  Ficheiro de escolhas: %s\n", options.choices_file);

  // TODO: Parte lógica de processamento dos ficheiros de entrada
  // TODO: Ficho 1 Dados dos utentes; Ficheiro 2 Info da Ementa Semanal; Ficheiro 3 Info das escolhas dos utentes

  load_employees(options.employees_file, employees, &employee_count);
  printf("Total de Funcionarios: %d\n", employee_count);
  for (int i = 0; i < employee_count; i++)
  {
    printf("ID: %d, Nome: %s, NIF: %d, Telefone: %d\n",
           employees[i].employee_number,
           employees[i].name,
           employees[i].nif,
           employees[i].phone);
  }

  // Finalizar
  print_program_message(argv[0], "Processamento concluido.\n");

  return 0;
}

void NewFunction()
{
  initialize_menu();

  while (1)
  {
    show_menu();
  }
}
