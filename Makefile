CCFLAGS = -g -O0 -Wall -Iinc
CC = gcc
CXX = g++

all: test

test: linkedList.o test.o
	$(CC) $(CCFLAGS) -o $@ $^

linkedList.o: src/linkedList.c 
	$(CC) $(CCFLAGS) -c -o $@ $^	

test.o: tests/test.c 
	$(CC) $(CCFLGAS) -c -o $@ $^	
	

clean:
	rm *.o test
