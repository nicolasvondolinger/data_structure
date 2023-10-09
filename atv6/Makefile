CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/node.o $(OBJ)/graph.o $(OBJ)/ListaAdjacencia.o $(OBJ)/main.o
HDRS = $(INC)/node.hpp $(INC)/graph.hpp $(INC)/ListaAdjacencia.hpp
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/pa6.out  # Nome do executável corrigido

all: $(EXE)

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
