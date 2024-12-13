# Feature: Gestão das Escolhas Semanais

## Descrição
Esta feature permite carregar, listar e gerir as escolhas dos utentes.

## Funcionalidades
1. **Carregamento de Escolhas:**
   - Carregar dados de um ficheiro ou via stdin.
2. **Listagem das Escolhas:**
   - Exibir todas as escolhas realizadas pelos utentes.

## Exemplos de Uso
### **Carregar Escolhas via Ficheiro**
**Input:**
```bash
./prog -e data/choices.txt
```
**Output:**
```bash
Escolhas carregadas com sucesso:
- 2feira, ID Funcionário: 0001, Tipo de Prato: P (Peixe)
- 2feira, ID Funcionário: 0002, Tipo de Prato: V (Vegetariano)
```
### **Carregar Ementa via Stdin**
**Input:**
```bash
./prog
```
**Output (interação):**
```bash
Erro: Ficheiro de escolhas não fornecido.
Por favor, insira os dados manualmente:
Formato esperado: <Dia da Semana>;<ID Funcionário>;<Tipo de Prato>
Digite "FIM" para terminar.
> 2feira;0001;P
> 2feira;0002;V
> FIM
Escolhas carregadas: 2.
```
### **Listar Escolhas**
**Input:**
```bash
./prog --list-choices
```
**Output:**
```bash
Escolhas Semanais:
- 2feira: Funcionário 0001 escolheu Peixe.
- 2feira: Funcionário 0002 escolheu Vegetariano.
```
