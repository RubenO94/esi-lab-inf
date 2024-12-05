// TODO: Criar a Esturura de dados para Ementa;
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