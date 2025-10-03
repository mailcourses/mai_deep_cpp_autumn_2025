
CC=g++
FLAGS=-std=c++20 -Wall -Wextra #-Werror

main: main.o square.o
	$(CC) $(FLAGS) main.o square.o -o main

main.o: square.hpp main.cpp
	$(CC) $(FLAGS) -c main.cpp

square.o: square.hpp square.cpp
	$(CC) $(FLAGS) -c square.cpp

clean:
	rm -rf *.o main
