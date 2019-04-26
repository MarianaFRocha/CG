CC = g++
coisasGlut = -lGL -lGLU -lglut
#coisasTiny = tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp

all: 
	$(CC) -w -O4 -c Exemplo3D.cpp
	$(CC) -g -O4 -s Exemplo3D.o $(coisasGlut) -lm -o Exemplo3D
	./Exemplo3D

run:
	./Exemplo3D

clean:
	rm *.o
	rm Exemplo3D
	reset



