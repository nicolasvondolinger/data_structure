CXX = g++
CXXFLAGS = -g

BIN = bin
INC = include
SRC = src
OBJ = obj
EXE = out.exe
HEADERS = $(INC)/*.hpp
IN = $(wildcard $(SRC)/*.cpp)
IN2 = $(subst $(SRC)/,$(OBJ)/,$(IN))
OUT = $(patsubst %.cpp,%.o,$(IN2))

$(OBJ)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXE): $(OUT)
	$(CXX) $(CXXFLAGS) -o $(BIN)/$(EXE) $(OBJ)/*.o

all: $(EXE)

default: $(OUT)

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*