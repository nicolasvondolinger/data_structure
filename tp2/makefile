CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/main.o $(OBJ)/sortMethods.o $(OBJ)/memlog.o
HDRS = $(INC)/sortMethods.hpp $(INC)/memlog.hpp $(INC)/msgassert.hpp
CFLAGS = -g -Wall -c -I$(INC) -pg

EXE = $(BIN)/tp2.out 

all: mem perf gprof

mem: $(EXE)
	$(EXE)

perf: $(EXE)
	$(EXE)

gprof: $(EXE)
	$(EXE)
	gprof $(EXE) gmon.out > /tmp/greedy.txt

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
