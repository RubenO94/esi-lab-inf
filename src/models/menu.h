// TODO: Criar a Esturura de dados para Ementa;
#ifndef MENU_H
#define MENU_H

typedef struct
{
  char day_of_week[10];      // Dia da semana (ex.: "2feira")
  char date[11];             // Data no formato "DD.MM.YYYY"
  char fish_dish[100];       // Prato de peixe
  int fish_calories;         // Calorias do prato de peixe
  char meat_dish[100];       // Prato de carne
  int meat_calories;         // Calorias do prato de carne
  char diet_dish[100];       // Prato de dieta
  int diet_calories;         // Calorias do prato de dieta
  char vegetarian_dish[100]; // Prato vegetariano
  int vegetarian_calories;   // Calorias do prato vegetariano
} WeeklyMenu;

/**
 * @brief Mostra o menu principal da aplicação.
 */
void show_menu();
void apresentacao_refeicoes();
void listagem_utentes();
void listar_refeicoes_calorias();
void medias_calorias();
void gerar_ementa_semanal();
int initialize_menu();
#endif