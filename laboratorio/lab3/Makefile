CC = gcc
coisasGlut = -lGL -lGLU -lglut
#coisasTiny = tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp

all: 
	$(CC) -w -O4 -c animacaoBorboleta.c
	$(CC) -g -O4 -s animacaoBorboleta.o $(coisasGlut) -lm -o borboleta
	./borboleta

run:
	./borboleta

clean:
	rm *.o
	rm borboleta
	reset



