# Feature: Gestão da Ementa Semanal

## Descrição
Esta feature permite carregar, listar e gerir a ementa semanal.

## Funcionalidades
1. **Carregamento de Ementa:**
   - Carregar dados de um ficheiro ou via stdin.
2. **Listagem da Ementa:**
   - Exibir a ementa semanal completa.

## Exemplos de Uso
### **Carregar Ementa via Ficheiro**
**Input:**
```bash
./prog -m data/menu.txt
```
**Output:**
```bash
Ementa carregada com sucesso para os seguintes dias:
- 2feira (18.11.2024): Peixe - pescada cozida (180 cal), Carne - vitela estufada (330 cal), Dieta - sopa de legumes (120 cal), Vegetariano - grão com legumes (250 cal)
```
### **Carregar Ementa via Stdin**
**Input:**
```bash
./prog
```
**Output (interação):**
```bash
Erro: Ficheiro de ementa não fornecido.
Por favor, insira os dados manualmente:
Formato esperado: <Dia da Semana>;<Data>;<Prato Peixe>;<Calorias Peixe>;...;<Prato Vegetariano>;<Calorias Vegetariano>
Digite "FIM" para terminar.
> 2feira;18.11.2024;pescada cozida;180;vitela estufada;330;sopa de legumes;120;grão com legumes;250
> FIM
Menus carregados: 1.
```
### **Listar Ementa**
**Input:**
```bash
./prog --list-menu
```
**Output:**
```bash
Ementa Semanal:
- 2feira (18.11.2024): Peixe - pescada cozida (180 cal), Carne - vitela estufada (330 cal), Dieta - sopa de legumes (120 cal), Vegetariano - grão com legumes (250 cal)
```
