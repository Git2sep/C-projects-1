# Makefile for project 3
# 
# DO NOT modify this file 

OBJS := level_0.o level_1.o level_2.o level_3.o  level_4.o 
CC		= gcc
CFLAGS := -g -Og -std=gnu99 

all: $(OBJS) proj3 

proj3: proj3.h proj3.o $(OBJS)
	$(CC) $(CFLAGS) -o proj3  proj3.o $(OBJS)


level_0.o: level_0.c proj3.h 
	$(CC) $(CFLAGS) -c level_0.c 
level_1.o: level_1.c proj3.h 
	$(CC) $(CFLAGS) -c level_1.c 
level_2.o: level_2.c proj3.h 
	$(CC) $(CFLAGS) -c level_2.c 
level_3.o: level_3.c proj3.h 
	$(CC) $(CFLAGS) -c level_3.c 
level_4.o: level_4.c proj3.h 
	$(CC) $(CFLAGS) -c level_4.c 
proj3.o: proj3.c proj3.h  
	$(CC) $(CFLAGS) -c proj3.c 

clean:		
	rm -f *~ proj3 proj3.o level*.o a.out core cache.trace valgrind.log

run: 
	valgrind --tool=cachegrind --D1=1024,2,32 --cachegrind-out-file=cache.trace ./proj3 > valgrind.log 2>&1
		
results:
	cg_annotate --threshold=0.001 --show=D1mr,D1mw  --sort=D1mr,D1mw cache.trace 	
 
run_test:
	rm -f *~ proj3 proj3.o level*.o a.out core cache.trace valgrind.log
	make all
	./proj3
	valgrind --tool=cachegrind --D1=1024,2,32 --cachegrind-out-file=cache.trace ./proj3 > valgrind.log 2>&1
	cg_annotate --threshold=0.001 --show=D1mr,D1mw  --sort=D1mr,D1mw cache.trace |grep level_[0-4]
