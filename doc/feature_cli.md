# Feature: Interface de Linha de Comando (CLI)

## Descrição
Esta feature permite a interação com o programa através de uma interface de linha de comando (CLI), com suporte para múltiplas flags e funcionalidades, incluindo o carregamento de dados, listagens e exibição de ajuda.

## Funcionalidades
1. **Parsing de Argumentos:**
   - Suporte a flags curtas e longas:
     - `-f` ou `--funcionarios`: Especifica o ficheiro de funcionários.
     - `-m` ou `--menu`: Especifica o ficheiro da ementa semanal.
     - `-e` ou `--escolhas`: Especifica o ficheiro de escolhas.
     - `-tab`: Indica que os ficheiros usam tabulação como delimitador.
     - `-bin`: Indica que os ficheiros estão em formato binário.
     - `-ajuda`: Exibe as instruções de uso.
   - Flags de listagem:
     - `--list-employees`: Lista todos os funcionários carregados.
     - `--list-menu`: Lista a ementa semanal.
     - `--list-choices`: Lista as escolhas semanais dos utentes.

2. **Validação de Argumentos:**
   - Verifica se as flags são válidas.
   - Garante que as flags de listagem só são processadas se os dados correspondentes estiverem carregados.

3. **Exibição de Ajuda:**
   - Apresenta as opções disponíveis e exemplos de uso.

---

## Exemplos de Uso
### **Ajuda**
**Input:**
```bash
./prog -ajuda
```
**Output:**
```bash
Uso: ./prog [opções]
Opções:
  -f, --funcionarios <ficheiro>  Especifica o ficheiro de funcionários.
  -m, --menu <ficheiro>         Especifica o ficheiro de ementa semanal.
  -e, --escolhas <ficheiro>     Especifica o ficheiro de escolhas.
  -tab                          Usa ficheiros separados por tabulação.
  -bin                          Usa ficheiros binários.
  --list-employees              Lista os funcionários carregados.
  --list-menu                   Lista a ementa semanal carregada.
  --list-choices                Lista as escolhas semanais dos utentes.
  -ajuda                        Mostra este menu de ajuda.
```
### **Parsing Completo**
**Input:**
```bash
./prog -f data/employees.txt -m data/menu.txt -e data/choices.txt -tab --list-employees
```
**Output:**
```bash
Modo tabulação ativado.
Ficheiro de Funcionários: data/employees.txt
Ficheiro de Ementa: data/menu.txt
Ficheiro de Escolhas: data/choices.txt

Funcionários carregados:
1. ID: 0001, Nome: Paulo Silva, NIF: 179204181, Telefone: 123456789
2. ID: 0002, Nome: Maria João Pires, NIF: 204168169, Telefone: 96543210
```
### **Erro: Flag inválida**
**Input:**
```bash
./prog -x data/employees.txt
```
**Output:**
```bash
Erro: Opção desconhecida ou argumento inválido: -x
Use './prog -ajuda' para mais informações.
```
### **Input Manual via Stdin**
**Input:**
```bash
./prog
```
**Output:**
```bash
Erro: Nenhum ficheiro fornecido.
Por favor, insira os dados manualmente para continuar.

== Funcionários ==
Formato esperado: <ID Funcionário>;<Nome>;<NIF>;<Telefone>
Digite "FIM" para terminar.
> 0001;Paulo Silva;179204181;123456789
> 0002;Maria João Pires;204168169;96543210
> FIM
Funcionários carregados: 2.

== Menu ==
Formato esperado: <Dia da Semana>;<Data>;<Prato Peixe>;<Calorias Peixe>;...;<Prato Vegetariano>;<Calorias Vegetariano>
Digite "FIM" para terminar.
> 2feira;18.11.2024;pescada cozida;180;vitela estufada;330;sopa de legumes;120;grão com legumes;250
> FIM
Menus carregados: 1.

== Escolhas ==
Formato esperado: <Dia da Semana>;<ID Funcionário>;<Tipo de Prato>
Digite "FIM" para terminar.
> 2feira;0001;P
> 2feira;0002;V
> FIM
Escolhas carregadas: 2.
```
