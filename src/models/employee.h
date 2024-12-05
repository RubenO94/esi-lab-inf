// TODO: Criar a Esturura de dados para Funcioário;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

/**
 * @brief Representa os dados de um funcionário.
 */
typedef struct
{
  int employee_number; // Número do funcionário
  char name[50];       // Nome
  int nif;             // NIF
  int phone;           // Telefone
} Employee;

/**
 * @brief Carrega os dados dos funcionários a partir de um ficheiro.
 * @param filename Nome do ficheiro.
 * @param employees Array de funcionários.
 * @param count Ponteiro para o número total de funcionários carregados.
 */
void load_employees(const char *filename, Employee employees[], int *count);

#endif
