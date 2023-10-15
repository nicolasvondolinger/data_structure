CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/node.o $(OBJ)/stack.o $(OBJ)/binaryTree.o $(OBJ)/main.o
HDRS = $(INC)/Node.h $(INC)/Stack.h $(INC)/BinaryTree.h $(INC)/msgassert.h 
CFLAGS = -g -Wall -c -I$(INC)
VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full

EXE = $(BIN)/main
TESTS = test1 test2 test3 test4 test5

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

run: $(EXE)
	$(EXE) -a "0 & 1" 10
	$(EXE) -a "0 | 1 & 2" 010
	$(EXE) -a "~ ( 0 & 1 ) & 2" 101
	$(EXE) -a "~0 & 1 & 2" 011
	$(EXE) -a "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" 00000000001
	$(EXE) -s "0 | 1 & 2" 0e0
	$(EXE) -s "0 | 1 & 2" e00
	$(EXE) -s "0 | 1 & 2" e11
	$(EXE) -s "0 | 1 & 2" e1e
	$(EXE) -s "0 | 1 & 2 & 3" e1ee

clean:
	rm -f $(EXE) $(OBJS) gmon.out
