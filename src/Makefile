CC =gcc
FLAGS =-Wall -Werror -Wextra -lstdc++
SRC =s21_vector.cpp

all: test

clean:
	rm -rf tests *.o

build: clean
	$(CC) $(FLAGS) $(SRC) -o tests -g

leak: build
	leaks -atExit -- tests

test: build
	./tests