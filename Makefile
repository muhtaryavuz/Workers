CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lpthread
EXECUTABLE	:= Test


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp $(SRC)/WorkerModule/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(INCLUDE)/WorkerModule -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
