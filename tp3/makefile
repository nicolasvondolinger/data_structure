CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/matrix.o $(OBJ)/main.o
HDRS = $(INC)/matrix.hpp 
CFLAGS = -g -Wall -c -I$(INC)
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

EXE = $(BIN)/tp3.out

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

valgrind: $(EXE)
	valgrind $(VALGRIND_FLAGS) ./$(EXE)

cachegrind: $(EXE)
	valgrind --tool=cachegrind ./$(EXE)
