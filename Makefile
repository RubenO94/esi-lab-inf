# Definimos o compilador
CC = gcc

# Flags para o compilador
CFLAGS = -Wall -Wextra

# Diretório dos ficheiros fonte
SRC_DIR = ./src

# Diretório dos ficheiros objeto
OBJ_DIR = ./bin

# Nome do programa final
BIN = prog

# Lista de todos os ficheiros .c no diretório SRC_DIR
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)

# Lista de ficheiros .o correspondentes no diretório OBJ_DIR
OBJ = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.c=.o))

# Comando de criação de diretórios
MKDIR = mkdir -p

# Regra padrão (alvo principal)
all: $(BIN)

# Regra para criar o binário final a partir dos ficheiros objeto
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Regra genérica para compilar os ficheiros .c em ficheiros .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar todos os ficheiros gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Declara que os alvos não são ficheiros reais
.PHONY: all clean
