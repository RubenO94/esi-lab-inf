# Dependências de Funcionalidades

**Nota:** À medida que cada funcionalidade for implementada, editem este ficheiro e marquem a checkbox correspondente como concluída (`[x]`).

## 1. Interface de Linha de Comando (CLI)
- [ ] **Parsing de argumentos (`--list-employees`, `--list-menu`, `--list-choices`)**
  - Depende de:
    - `load_employees()` (da feature **Employees**).
    - `load_menu()` (da feature **Menu**).
    - `load_choices()` (da feature **Choices**).

- [ ] **Exibição de ajuda (`-ajuda`)**
  - Depende de:
    - Nenhuma funcionalidade externa.

## 2. Gestão de Funcionários
- [ ] **Carregamento de dados (`load_employees()`)**
  - Depende de:
    - `file_exists()` (da feature **Utils**).
    - Validação dos dados.

- [ ] **Listagem de funcionários (`list_employees()`)**
  - Depende de:
    - Dados carregados por `load_employees()`.

## 3. Gestão da Ementa Semanal
- [ ] **Carregamento de dados (`load_menu()`)**
  - Depende de:
    - `file_exists()` (da feature **Utils**).
    - Validação dos dados.

- [ ] **Listagem de ementa (`list_menu()`)**
  - Depende de:
    - Dados carregados por `load_menu()`.

## 4. Gestão das Escolhas Semanais
- [ ] **Carregamento de dados (`load_choices()`)**
  - Depende de:
    - `file_exists()` (da feature **Utils**).
    - Validação dos dados.

- [ ] **Listagem de escolhas (`list_choices()`)**
  - Depende de:
    - Dados carregados por `load_choices()`.

## 5. Utils
- [ ] **Validação de ficheiros (`file_exists()`)**
  - Depende de:
    - Funções do sistema operativo (e.g., `fopen`, `stat`).

- [ ] **Validação de dados**
  - Depende de:
    - Regras específicas de validação para cada tipo de ficheiro (funcionários, menu, escolhas).
