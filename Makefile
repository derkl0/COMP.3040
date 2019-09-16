CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
OBJ = main.o Character.o Alphabet.o String.o
DEPS = 
LIBS =
EXE = foundations_kiesling

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)