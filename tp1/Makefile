#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Nicolas Von Dolinger (meira@dcc.ufmg.br)
# Histórico	: 2021-10-18 - arquivo criado
#		: 2021-10-21 - estrutura de diretórios
#               : 2021-11-15 - Versao 1.1 memlog
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/node.o $(OBJ)/stack.o $(OBJ)/binaryTree.o $(OBJ)/main.o
HDRS = $(INC)/Node.h $(INC)/Stack.h $(INC)/BinaryTree.h $(INC)/msgassert.h 
#OBJS = $(OBJ)/node.o $(OBJ)/stack.o  $(OBJ)/main.o
#HDRS = $(INC)/Node.h $(INC)/Stack.h $(INC)/msgassert.h 
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/main

all: $(EXE)
#all:  mem perf gprof

run: $(EXE)
	$(EXE) -a "0 & 1" 10
	$(EXE) -a "0 | 1 & 2" 010
	$(EXE) -a "~ ( 0 & 1 ) & 2" 101
	$(EXE) -a "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" 00000000010
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out

$(EXE): $(OBJS) | $(BIN)
	$(CC) $(OBJS) -o $(EXE) $(LIBS)

$(BIN):
	mkdir -p $(BIN)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS) | $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ):
	mkdir -p $(OBJ)

