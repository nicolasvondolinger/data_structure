#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-02 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm -pg -g
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/funop.o $(OBJ)/fun.o 
HDRS = $(INC)/fun.h
CFLAGS = -Wall -I$(INC) -pg -c -g

EXE = $(BIN)/funop

run:  $(EXE)
	$(EXE) 40
	$(EXE) 40
	$(EXE) 40

$(BIN)/funop: $(OBJS)
	$(CC) -pg -o $(BIN)/funop $(OBJS) $(LIBS)

$(OBJ)/funop.o: $(HDRS) $(SRC)/funop.c
	$(CC) $(CFLAGS) -o $(OBJ)/funop.o $(SRC)/funop.c 

$(OBJ)/fun.o: $(HDRS) $(SRC)/fun.c
	$(CC) $(CFLAGS) -o $(OBJ)/fun.o $(SRC)/fun.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
