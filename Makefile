CC=g++
CFLAGS=-g
EX=statSem
DEPS=inputProcessing.h Scanner.h token.h testTree.h parser.h StaticSem.h
OBJ=inputProcessing.o Scanner.o token.o testTree.o parser.o StaticSem.o

all: $(EX)

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(EX): Main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : clean 
clean :
	rm -rf *.o tempInput.sp2020 $(EX)