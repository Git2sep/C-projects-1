# Project 3: Writing Cache Aware Code 

Due date: April 23 at 11:55pm. 

**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own. 
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help 
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part 
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

-----



## Project Description

In this project you will practice anlyzing cache use and how to tweak C code to make it (more) cache friendly.
The repository contains five files: `level_0`, ..., `level_4` with different C functions that perform operations that are fairly memory intensive. Your
task is to implement equivalent functions (i.e., your functions should perform exactly the same tasks) but in a cache-aware manner. Your functions
should be called `level_0_opt`, ..., `level_4_opt`.

Notes: 

* Do not modify the code where the comments state so.
* You can add any variables or data structure you want, but you are not allowed to remove/modify available variables or data structures.
* Feel free to add additional helper functions. If you do, name them starting with the name of the function in which they are used. For example, if
you want a helper function for level_1_opt function, it should be called level_1_opt_helper (or some other suffix). The cache misses
that occur within the helper function will count towards the function that calls it.
* Do not use recursion.
* Your changes should not change the underlying algorithm. They should make the existing implementation more efficient. For example, if one of
the functions implements a bubble sort, do not change it to quick sort.
* Always remember that cache friendly means locality of data access, both temporal and spatial.
* You should first understand what the function does, then attempt to optimize it.



## Working on This Project 

### Files

Your repository contains the following files

*  `proj3.c` - the actual program that calls all the functions and performs preliminary correctness checks (should not be modified);
*  `proj3.h` - the header file containing structure definitions, and function declarations (;if you need to define additional structures or declare
additional functions, you should add them to this file)
*  `level_0.c`, ..., `level_4.c` - functions that you need to optimize;
*  `Makefile` - the makefile for this project

### Compiling and Building the Code

You can combile and build the code by running

    $ make clean
    $ make

This produces `proj3` program that shows which of the functions completed and if the results produced by the optimized functions match the results
produced by the unoptimized functions (note, that this program does not perform a complete check, but should be a good indicator if the functions are
setting the right values). The sample output is shown below:


    $ ./proj3
    level_0 completed
    level_0_opt completed
        level_0_opt PASSED
    level_1 completed
    level_1_opt completed
        level_1_opt FAILED
    level_2 completed
    level_2_opt completed
        level_2_opt FAILED
    level_3 completed
    level_3 completed
        level_3_opt FAILED
    level_4 completed
    level_4 completed
        level_4_opt FAILED
    $



## Checking Cache Performance of the Code 

When you complete each level, you should run the program in the cache simulator to see its cache performance. To do so, execute make run followed
by make results. The sample outputs are shown below:

    $ make run
    valgrind --tool=cachegrind --D1=1024,16,32 --cachegrind-out-file=cache.trace ./proj3 > valgrind.log 2>&1
    
    $ make results
    cg_annotate --threshold=0.001 --show=D1mr,D1mw cache.trace 	
    --------------------------------------------------------------------------------
    I1 cache:         32768 B, 64 B, 8-way associative
    D1 cache:         1024 B, 32 B, 2-way associative
    LL cache:         6291456 B, 64 B, 12-way associative
    Command:          ./proj3
    Data file:        cache.trace
    Events recorded:  Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
    Events shown:     D1mr D1mw
    Event sort order: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
    Thresholds:       0.001 100 100 100 100 100 100 100 100
    Include dirs:     
    User annotated:   
    Auto-annotation:  off

    --------------------------------------------------------------------------------
         D1mr      D1mw 
    --------------------------------------------------------------------------------
    6,141,744 3,755,268  PROGRAM TOTALS

    --------------------------------------------------------------------------------
         D1mr      D1mw  file:function
    --------------------------------------------------------------------------------
      659,633         0  /build/glibc-t3gR2i/glibc-2.23/stdlib/random_r.c:random_r
      143,585    65,538  /build/glibc-t3gR2i/glibc-2.23/stdlib/random.c:random
      131,077 2,955,997  /home/asia/Data/NYU_Teaching/csci201/projects/project3/proj3.c:main
            1    65,536  /build/glibc-t3gR2i/glibc-2.23/stdlib/rand.c:rand
    1,202,430         0  /home/asia/Data/NYU_Teaching/csci201/projects/project3/level_3.c:level_3
    1,638,402         1  /home/asia/Data/NYU_Teaching/csci201/projects/project3/level_1.c:level_1
      268,547   453,808  /build/glibc-t3gR2i/glibc-2.23/malloc/malloc.c:_int_malloc
    1,048,578         0  /home/asia/Data/NYU_Teaching/csci201/projects/project3/level_0.c:level_0
      131,075         0  /home/asia/Data/NYU_Teaching/csci201/projects/project3/level_0.c:level_0_opt
      150,007         2  ???:???
      112,757         3  /build/glibc-t3gR2i/glibc-2.23/malloc/malloc.c:malloc
       80,529    29,713  /build/glibc-t3gR2i/glibc-2.23/malloc/malloc.c:_int_free
            9    72,949  /home/asia/Data/NYU_Teaching/csci201/projects/project3/proj3.c:flood_cache
       37,500     6,250  /home/asia/Data/NYU_Teaching/csci201/projects/project3/level_4.c:addFront
       27,014         0  /build/glibc-t3gR2i/glibc-2.23/stdlib/erand48_r.c:erand48_r
      100,010        69  /build/glibc-t3gR2i/glibc-2.23/malloc/malloc.c:malloc_consolidate
      100,001    78,907  /home/asia/Data/NYU_Teaching/csci201/projects/project3/level_4.c:level_4
      100,035       790  /build/glibc-t3gR2i/glibc-2.23/malloc/malloc.c:free
      100,001     6,252  /home/asia/Data/NYU_Teaching/csci201/projects/project3/level_2.c:level_2
      100,000         0  /build/glibc-t3gR2i/glibc-2.23/stdlib/drand48-iter.c:__drand48_iterate
            1         0  /build/glibc-t3gR2i/glibc-2.23/stdlib/drand48.c:drand48
            2    16,725  /build/glibc-t3gR2i/glibc-2.23/string/../sysdeps/x86_64/multiarch/../memset.S:__GI_memset
        2,165         5  /build/glibc-t3gR2i/glibc-2.23/elf/dl-addr.c:_dl_addr
        3,003       713  /build/glibc-t3gR2i/glibc-2.23/elf/dl-lookup.c:do_lookup_x
          839       315  /build/glibc-t3gR2i/glibc-2.23/elf/dl-lookup.c:_dl_lookup_symbol_x
        1,499       606  /build/glibc-t3gR2i/glibc-2.23/elf/../sysdeps/x86_64/dl-machine.h:_dl_relocate_object
          344         6  /build/glibc-t3gR2i/glibc-2.23/elf/do-rel.h:_dl_relocate_object
          319         0  /build/glibc-t3gR2i/glibc-2.23/string/../sysdeps/x86_64/multiarch/../strcmp.S:strcmp
          395       244  /build/glibc-t3gR2i/glibc-2.23/elf/dl-lookup.c:check_match



You can also run a sigle command 
    
    make run_test
    
to trigger compilation of the source code, run of the executable and cache
performance evaluation, but if there are errors along the way, you will still need 
to track them down using separate commands. 

The table contains numbers of cache read misses (D1mr) and cache write misses (D1mw). You should be looking at the lines that show the results of
all of the level_N and level_N_opt functions. In the above example you can see that the level_0 function had 1,048,578 cahe read misses and
the level_1_opt function had 131,075 cache read misses (this is almost the order of magnitude difference!!!). The reduction in the number of cache
misses will not be always so large. Your want both numbers (for cache read and write misses) to be as low as possible. (Note, that sometime
reducing one of those implies the other one goes up. This is fine, as long as there is overall benefit.)
The other optimized versions of functions will appear on the list when you write their implementation.



## Committing and Pushing Your Work 

You should commit your code regularly to the repository on GitHub (this is your backup and a proof to us that you are working on it).
At the least, you should commit your work after every single problem. You are **required** to make at least 5 commits (including the push to the remote repository) before the due date for the project. 

Please, run `make clean` before committing the changes so that the object files are not uploaded together with your sources. 

