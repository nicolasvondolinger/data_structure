CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/main.o #$(OBJ)/listaAdjacencia.o $(OBJ)/node.o  
#HDRS = $(INC)/listaAdjacencia.hpp $(INC)/node.hpp
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/tp2.out 

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
