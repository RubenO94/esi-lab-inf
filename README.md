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
## Opções Disponíveis

- **`-ajuda`**: Exibe as instruções de utilização.
- **`-tab`**: Indica que os ficheiros estão no formato tabulado.
- **`-bin`**: Indica que os ficheiros estão no formato binário.

