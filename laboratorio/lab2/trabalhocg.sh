#!/bin/bash
reset

g++ tc2.cpp -o teste -lGL -lGLU -lglut 


./teste

clean:
	rm -rf teste
