# Makefile for project 1
#
# You should not need to modify this file. 

CC		= gcc

CFLAGS		= -g  -Wall

CLIBS		= -lm 

all: prob1 prob2 prob3 prob4 

prob1: prob1.c 
	$(CC) $(CFLAGS) -o prob1 prob1.c 

prob2: prob2.c 
	$(CC) $(CFLAGS) -o prob2 prob2.c 

prob3: prob3.c proj1.o proj1.h
	$(CC) $(CFLAGS) -o prob3 prob3.c proj1.o $(CLIBS) 

prob4: prob4.c proj1.o proj1.h
	$(CC) $(CFLAGS) -o prob4 prob4.c proj1.o $(CLIBS) 

proj1.o: proj1.c proj1.h
	$(CC) $(CFLAGS) -c proj1.c 


clean:		
	rm -f *~ *.o a.out core prob1 prob2 prob3 prob4 

run_prob2: 
	./prob2 mary_corrupt.txt mary_fixed.txt

run_prob3:
	./prob3

run_prob4:
	./prob4

test_prob1:
	valgrind ./prob1

test_prob2: 
	valgrind ./prob2 mary_corrupt.txt mary_fixed.txt

test_prob3:
	valgrind ./prob3

test_prob4:
	valgrind ./prob4

