all: compile

compile: main.c
	gcc -o main main.c

clean:
	rm -rf *.o main

run:
	./main