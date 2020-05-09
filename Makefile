CC=g++
CFLAGS=-march=native -O4
OUT=Cube

all: build

#  ---  ---  ---  ---  #

build: Main Window
	${CC} ${CFLAGS} Main.o Window.o -o ${OUT} -lSDL2 -lGL -lGLU

Main:
	${CC} ${CFLAGS} -c src/Main.cpp -o Main.o

Window:
	${CC} ${CFLAGS} -c src/Window/Window.cpp -o Window.o

#  ---  ---  ---  ---  #

clean:
	rm *.o
