# Makefile para compilar la práctica 7 de C&A.
# Cristian Abrante Dorta.

CC = g++
CXXFLAGS= --std=c++11 -g
OBJECTS= ./src/Alphabet/Alphabet.o ./src/CFG/CFG.o ./src/Production/Production.o ./src/main.o

Practica7: ${OBJECTS}
	${CC} ${CXXFLAGS} -o cfg.out ${OBJECTS}
