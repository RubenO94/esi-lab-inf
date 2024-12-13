# Feature: Gestão de Funcionários

## Descrição
Esta feature permite carregar, listar e gerir os dados dos funcionários do sistema.

## Funcionalidades
1. **Carregamento de Funcionários:**
   - Carregar dados de um ficheiro ou via stdin.
2. **Listagem de Funcionários:**
   - Exibir todos os funcionários carregados.

## Exemplos de Uso
### **Carregar Funcionários via Ficheiro**
**Input:**
```bash
./prog -f data/employees.txt
```
**Output:**
```bash
Funcionários carregados com sucesso:
- ID: 0001, Nome: Paulo Silva, NIF: 179204181, Telefone: 123456789
- ID: 0002, Nome: Maria João Pires, NIF: 204168169, Telefone: 96543210
```
### **Carregar Funcionários via Stdin**
**Input:**
```bash
./prog
```
**Output (interação):**
```bash
Erro: Ficheiro de funcionários não fornecido.
Por favor, insira os dados manualmente:
Formato esperado: <ID Funcionário>;<Nome>;<NIF>;<Telefone>
Digite "FIM" para terminar.
> 0001;Paulo Silva;179204181;123456789
> 0002;Maria João Pires;204168169;96543210
> FIM
Funcionários carregados: 2.
```
### **Listar Funcionários**
**Input:**
```bash
./prog --list-employees
```
**Output (interação):**
```bash
Funcionários:
1. ID: 0001, Nome: Paulo Silva, NIF: 179204181, Telefone: 123456789
2. ID: 0002, Nome: Maria João Pires, NIF: 204168169, Telefone: 96543210
```
