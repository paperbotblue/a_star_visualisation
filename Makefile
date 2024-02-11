
CC=g++
CFLAGS=-Wall -Wextra
END_FLAGS=-lSDL2 -lSDL2_ttf
SRC=src
OBJ=obj

SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BINDIR=debug/
BIN=$(BINDIR)main
all: $(BIN)

release: BINDIR=
release: CFLAGS=-Wall -O3 -DNDEBUG 
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(END_FLAGS)

$(OBJ)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(END_FLAGS)

run:
	./$(BIN)

clean:
	rm -r $(BIN) $(OBJ)/*.o

new:
	mkdir src res obj inc debug
