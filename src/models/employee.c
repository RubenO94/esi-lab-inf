#include <stdio.h>
#include "employee.h"

void load_employees(const char *filename, Employee employees[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    *count = 0;
    while (fscanf(file, "%d;%49[^;];%d;%d\n", 
                  &employees[*count].employee_number,
                  employees[*count].name,
                  &employees[*count].nif,
                  &employees[*count].phone) == 4) {
        (*count)++;
    }

    fclose(file);
}
