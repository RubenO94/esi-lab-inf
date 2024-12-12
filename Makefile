# Definimos o compilador que vamos usar (gcc, o mais comum para C).
CC = gcc

# Adicionamos flags que dizem ao compilador para mostrar mais avisos e erros:
# -Wall: Mostra avisos padrão.
# -Wextra: Mostra avisos extras que ajudam a evitar erros.
CFLAGS = -Wall -Wextra

# Lista de todos os ficheiros .c (código fonte) que fazem parte do programa.
# Aqui indicamos onde estão os ficheiros que precisamos compilar. (Ir adicionando aqui, confrome vamos criando ficheiros .c)
SRC_DIR = ./src
SRC = $(shell find $(SRC_DIR) -name '*.c')

# Lista de ficheiros .o (ficheiros "objeto") gerados a partir dos ficheiros .c.
# Aqui, substituímos ".c" por ".o" automaticamente.
OBJ = $(SRC:.c=.o)

# Nome do programa final (ficheiro binário que será gerado após a compilação).
BIN = prog


# Detecta o ambiente (Windows ou Unix/Linux) e escolhe o comando para limpar.
# No Windows usamos "del", em Linux usamos "rm".
# opção /Q em Windows é igual ao -f (force) em Linux
RM = rm -f
ifeq ($(OS),Windows_NT)
	RM = del /Q
# Substitui "/" por "\" no Windows
	OBJ = $(subst /,\,$(SRC:.c=.o))  
else
	OBJ = $(SRC:.c=.o)
endif

# Regras do Makefile começam aqui. O "all" é o alvo padrão.
# Sempre que digitamos "make" no terminal, o Makefile executa o alvo "all".
all: $(BIN)

# Esta regra descreve como criar o programa final (binário).
# O $(BIN) depende de todos os ficheiros .o.
# O comando abaixo do $(BIN) compila todos os ficheiros .o num único programa.
$(BIN): $(OBJ)
# Compila o programa final a partir dos ficheiros .o.
	$(CC) $(CFLAGS) -o $@ $^

# Esta é uma regra genérica para criar ficheiros .o a partir de ficheiros .c.
# O %.o corresponde a qualquer ficheiro .o, e o %.c ao ficheiro fonte correspondente.
%.o: %.c
# Compila o ficheiro .c num ficheiro .o (ficheiro "objeto").
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza: remove ficheiros temporários ou gerados (ficheiros .o e o binário final).
clean:
# Remove todos os ficheiros objeto (.o) e o binário final.
# O comando varia depender do sistema operativo.
	$(RM) $(OBJ) $(BIN) 2>>logs/make-clean.log

# Declara que "all" e "clean" são "falsos", ou seja, não se referem a ficheiros reais.
# Isto é necessário para evitar problemas se houver ficheiros com os mesmos nomes.
.PHONY: all clean
