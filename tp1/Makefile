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
    # Adicione suas regras de execução aqui
	$(EXE) -a "0 & 1" 10
	$(EXE) -a "0 | ~ ~ 1" 01
	$(EXE) -a "0 | 1 & 2" 010
	$(EXE) -a "~ ( 0 & 1 ) & 2" 101
	$(EXE) -a "~0 & 1 & 2" 011
	$(EXE) -a "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" 00000000001
	$(EXE) -s "0 | 1 & 2" 0e0
	$(EXE) -s "0 | 1 & 2" e00
	$(EXE) -s "0 | 1 & 2" e11
	$(EXE) -s "0 | 1 & 2" e1e
	$(EXE) -s "0 | 1 & 2 & 3" e1ee
	$(EXE) -s "(0 | 1 | 1 | 1 | 1 | 1 )" ea
	$(EXE) -s "0 | ~ ~ 1" ea
	$(EXE) -a "~ ~ ~ ( ~ ( 0 & 1) | ( ~ ~ ~ 2) )" 010
	$(EXE) -a "~ ~ ~ ( ~ ( 0 & 1) | ( ~ ~ ~ 2) )" 110
	$(EXE) -a "~ ~ ~ ( ~ ( 0 & 1) | ( ~ ~ ~ 2) )" 111
	$(EXE) -s "0 | 1 & 2" e0e
	$(EXE) -s "( 0 & 1 ) | ( ~ ( 2 & 3 ) )" aaaa
    # Adicione outros comandos de execução aqui

valgrind: $(EXE)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(EXE) > saida_valgrind.txt
    # Adicione seus testes de Valgrind aqui
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "0 & 1" 10 > saida_valgrind_test1.txt
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "0 | ~ ~ 1" 01 > saida_valgrind_test2.txt
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "0 | 1 & 2" 010 > saida_valgrind_test3.txt
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "~ ( 0 & 1 ) & 2" 101
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "~0 & 1 & 2" 011
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" 00000000001
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "0 | 1 & 2" 0e0
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "0 | 1 & 2" e00
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "0 | 1 & 2" e11
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "0 | 1 & 2" e1e
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "0 | 1 & 2 & 3" e1ee
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "(0 | 1 | 1 | 1 | 1 | 1 )" ea
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "0 | ~ ~ 1" ea
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "~ ~ ~ ( ~ ( 0 & 1) | ( ~ ~ ~ 2) )" 010
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "~ ~ ~ ( ~ ( 0 & 1) | ( ~ ~ ~ 2) )" 110
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -a "~ ~ ~ ( ~ ( 0 & 1) | ( ~ ~ ~ 2) )" 111
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "0 | 1 & 2" e0e
	$(VALGRIND) $(VALGRIND_FLAGS) $(EXE) -s "( 0 & 1 ) | ( ~ ( 2 & 3 ) )" aaaa
    # Adicione outros testes de Valgrind aqui

clean:
	rm -f $(EXE) $(OBJS) gmon.out
