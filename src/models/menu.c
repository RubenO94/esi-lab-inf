/**
 * @file menu.c
 * @author Raúl Ribeiro ({a22552@alunos.ipca.pt})
 * @brief: The main menu look and functions.
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"


#define MAX_UTENTES 5
#define MAX_MEALS 7

// Structure to store a user's data
typedef struct {
    int numero_funcionario;
    char nome[50];
    char prato[MAX_MEALS][50];
    int calorias[MAX_MEALS];
    char dia_semana[MAX_MEALS][10];
    float despesa_total;
    int refeicoes_por_semana;
} Utente;

// Global variable to hold the list of users
Utente utentes[MAX_UTENTES];

// Menu option
int *option;

// Function to show the menu
void show_menu() {
    printf("Bem-Vindo! Escolha a opção: \n");
    printf("1. Apresentação das refeições para um dia\n");
    printf("2. Listagem dos utentes ordenada\n");
    printf("3. Listar refeições e calorias de um utente\n");
    printf("4. Calcular médias de calorias consumidas por dia\n");
    printf("5. Gerar tabela de ementa semanal de um utente\n");

    scanf("%d", option);

    switch(*option) {
        case 1:
            apresentacao_refeicoes();
            break;
        case 2:
            listagem_utentes();
            break;
        case 3:
            listar_refeicoes_calorias();
            break;
        case 4:
            medias_calorias();
            break;
        case 5:
            gerar_ementa_semanal();
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

// Function to present the meals for a given day
void apresentacao_refeicoes() {
    int funcionario_num;
    printf("Informe o numero do funcionario: ");
    scanf("%d", &funcionario_num);
    
    for(int i = 0; i < MAX_UTENTES; i++) {
        if(utentes[i].numero_funcionario == funcionario_num) {
            printf("Funcionario: %d - %s\n", utentes[i].numero_funcionario, utentes[i].nome);
            for(int j = 0; j < MAX_MEALS; j++) {
                if(strlen(utentes[i].prato[j]) > 0) {
                    printf("Dia: %s | Prato: %s | Calorias: %d\n", utentes[i].dia_semana[j], utentes[i].prato[j], utentes[i].calorias[j]);
                }
            }
            return;
        }
    }
    printf("Funcionario não encontrado.\n");
}

// Function to list the users in descending order of employee number
void listagem_utentes() {
    for(int i = 0; i < MAX_UTENTES - 1; i++) {
        for(int j = i + 1; j < MAX_UTENTES; j++) {
            if(utentes[i].numero_funcionario < utentes[j].numero_funcionario) {
                // Swap the two utentes
                Utente temp = utentes[i];
                utentes[i] = utentes[j];
                utentes[j] = temp;
            }
        }
    }

    printf("Listagem dos utentes ordenada por numero de funcionario:\n");
    for(int i = 0; i < MAX_UTENTES; i++) {
        printf("Funcionario: %d - %s | Refeicoes: %d | Despesa total: %.2f\n",
               utentes[i].numero_funcionario, utentes[i].nome, utentes[i].refeicoes_por_semana, utentes[i].despesa_total);
    }
}

// Function to list meals and calories for a user over a given period
void listar_refeicoes_calorias() {
    int funcionario_num;
    int inicio, fim;
    printf("Informe o numero do funcionario: ");
    scanf("%d", &funcionario_num);
    printf("Informe o periodo de dias (inicio e fim): ");
    scanf("%d %d", &inicio, &fim);

    for(int i = 0; i < MAX_UTENTES; i++) {
        if(utentes[i].numero_funcionario == funcionario_num) {
            printf("Refeições e calorias para o funcionario %s (Numero: %d):\n", utentes[i].nome, utentes[i].numero_funcionario);
            for(int j = inicio; j <= fim && j < MAX_MEALS; j++) {
                if(strlen(utentes[i].prato[j]) > 0) {
                    printf("Dia: %s | Prato: %s | Calorias: %d\n", utentes[i].dia_semana[j], utentes[i].prato[j], utentes[i].calorias[j]);
                }
            }
            return;
        }
    }
    printf("Funcionario não encontrado.\n");
}

// Function to calculate the average calories per meal for each day of the week
void medias_calorias() {
    int dia;
    printf("Informe o dia da semana (1-Domingo, 2-Segunda, ..., 7-Sábado): ");
    scanf("%d", &dia);
    
    int total_calorias = 0, refeicoes = 0;
    
    for(int i = 0; i < MAX_UTENTES; i++) {
        for(int j = 0; j < MAX_MEALS; j++) {
            if(dia == j + 1 && strlen(utentes[i].prato[j]) > 0) {
                total_calorias += utentes[i].calorias[j];
                refeicoes++;
            }
        }
    }
    
    if(refeicoes > 0) {
        printf("Media de calorias consumidas no dia %d: %.2f\n", dia, total_calorias / (float) refeicoes);
    } else {
        printf("Nenhuma refeição registrada para o dia %d.\n", dia);
    }
}

// Function to generate a weekly meal table for a given user
void gerar_ementa_semanal() {
    int funcionario_num;
    printf("Informe o numero do funcionario: ");
    scanf("%d", &funcionario_num);
    
    for(int i = 0; i < MAX_UTENTES; i++) {
        if(utentes[i].numero_funcionario == funcionario_num) {
            printf("Tabela de ementa semanal para %s (Funcionario: %d):\n", utentes[i].nome, utentes[i].numero_funcionario);
            for(int j = 0; j < MAX_MEALS; j++) {
                if(strlen(utentes[i].prato[j]) > 0) {
                    printf("Dia: %s | Prato: %s | Calorias: %d\n", utentes[i].dia_semana[j], utentes[i].prato[j], utentes[i].calorias[j]);
                }
            }
            return;
        }
    }
    printf("Funcionario não encontrado.\n");
}

int initialize_menu() {
    // Initialize the data (for example)
    for(int i = 0; i < MAX_UTENTES; i++) {
        utentes[i].numero_funcionario = i + 1;
        snprintf(utentes[i].nome, sizeof(utentes[i].nome), "Funcionario %d", i + 1);
        utentes[i].refeicoes_por_semana = 5;
        utentes[i].despesa_total = 20.5f;

        for(int j = 0; j < MAX_MEALS; j++) {
            snprintf(utentes[i].dia_semana[j], sizeof(utentes[i].dia_semana[j]), "Dia %d", j + 1);
            snprintf(utentes[i].prato[j], sizeof(utentes[i].prato[j]), "Prato %d", j + 1);
            utentes[i].calorias[j] = 200 + (j * 50); // Example calorie count
        }
    }

    option = malloc(sizeof(int));

    while(1) {
        show_menu();
    }

    free(option);
    return 0;
}
