# Trabalho Prático - Laboratório de Informática

Este projeto foi desenvolvido como parte da unidade curricular de Laboratório de Informática. Consiste num sistema que faz a gestão de informações de utentes, ementas e escolhas semanais, com documentação e relatório em LaTeX.

## Estrutura do Projeto
O projeto está organizado da seguinte forma:

```plaintext

├── src/                  # Código fonte
│   ├── cli/              # Funções relacionadas à linha de comando
│   ├── logic/            # Lógica principal do programa
│   ├── models/           # Estruturas de dados
│   └── utils/            # Funções utilitárias (ex.: manipulação de ficheiros)
├── doc/
│   ├── doxygen/          # Documentação técnica gerada
│   └── relatorio/        # Relatório em LaTeX
├── data/                 # Ficheiros de dados de exemplo
├── README.md             # Este ficheiro
├── Makefile              # Automação de compilação

```

## Como Compilar
Para compilar o projeto:
```bash
make
```
## Executar o Programa
Após a compilação, execute o programa com as seguintes opções:
```bash
./prog -tab employees.txt menu.txt choices.txt
```
## Instruções de Uso
Para mais informações sobre o funcionamento do programa, consulta a [Documentação da CLI](doc/feature_cli.md).

---

## Features 

1. [Gestão de Funcionários](doc/feature_employees.md)  
   Permite carregar, listar e gerir os dados dos funcionários.

2. [Gestão da Ementa Semanal](doc/feature_menu.md)  
   Permite carregar, listar e gerir a ementa semanal.

3. [Gestão das Escolhas Semanais](doc/feature_choices.md)  
   Permite carregar, listar e gerir as escolhas feitas pelos utentes.

4. [Interface de Linha de Comando (CLI)](doc/feature_cli.md)  
   Permite interagir com o programa usando argumentos e comandos.

