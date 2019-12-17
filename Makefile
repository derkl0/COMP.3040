CC = g++
CFLAGS = -c -g -Og -Wall -Werror -pedantic -std=c++17
OBJ = main.o Character.o Alphabet.o String.o DFA.o
DEPS = 
LIBS =
EXE = foundations_kiesling

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)