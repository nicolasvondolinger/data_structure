CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/main.o $(OBJ)/sortMethods.o $(OBJ)/memlog.o
HDRS = $(INC)/sortMethods.hpp $(INC)/memlog.hpp $(INC)/msgassert.hpp
CFLAGS = -g -Wall -c -I$(INC) -pg
LDFLAGS = -pg

EXE = $(BIN)/tp2.out 

all: mem perf gprof cachegrind

mem: $(EXE)
	valgrind --tool=memcheck --leak-check=full ./$(EXE)

perf: $(EXE)
	./$(EXE)

gprof: $(EXE)
	./$(EXE)
	gprof $(EXE) gmon.out > /tmp/greedy.txt

cachegrind: $(EXE)
	valgrind --tool=cachegrind ./$(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out cachegrind.out.*

$(EXE): $(OBJS) | $(BIN)
	$(CC) $(OBJS) -o $(EXE) $(LIBS) $(LDFLAGS)

$(BIN):
	mkdir -p $(BIN)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS) | $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ):
	mkdir -p $(OBJ)
