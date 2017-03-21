# Project 1

Due date: March 2 at 11:55pm. 

**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own. 
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help 
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part 
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

The `Makefile` provided with this project compiles and builds all of the required programs. 
To compile and build all of the program run:

    make all
    
To compile and build individual problems run:

    make prob1
    make prob2 
    ...
    
To run programs for each problem you can either execute 
    
    ./prob1 in_file  out_file 
    ./prob2
    ...

or, you can use the rules defined in the `Makefile`:
    
    make run_prob1
    make run_prob2 
    ...
    
Finally, to run programs using `valgrind` you can use the rules
defined in the `Makefile`:
    
    make test_prob1
    make test_prob2 
    ... 
    
To remove all previously compiled and built files, run

    make clean 

##Problem 1 (10 points) 

The code in `prob1.c` is a slightly modified version of the code example from the manual page of `getline()` function. 
Read the documentation of `getline()` function and answer the questions in `problem1_answers.md` file. 

### Deliverables: 
Answers to the questions in the file `problem1_answers.md` 

##Problem 2 (30 points) 

Some nasty scrambler messed up the text of the nursery rhyme *Mary Had a Little Lamb* (see https://en.wikipedia.org/wiki/Mary_Had_a_Little_Lamb) - the result is in the file called `mary_corrupt.txt`. 
Your task for this problem is to "unscramble" the characters written to  `mary_corrupt.txt` to recover the
original nursery rhyme.

The nasty scrambler left some clues: 

**Clue 1**: the corrupted file is still a text file - you should be able to work with individual 
ASCII characters even though they do not look like the English characters

**Clue 2**: for each original character, the 4 high order bits and the 4 low order bits were swapped. 

**Clue 3**: the swap operation (when performed correctly) the second time should produce the original file back

**Clue 4**: the type `char` in C is signed, you may find it handy to use the `unsigned char` in parts of the solution. 

### Programming requirements:

- Implement the program in `prob2.c` file. All functions should be specified in that file.
- The program should work with two command line arguments: the first one is the name of the input file, 
the second is the name of the output file. 
- The program should work with any "scrambled" input file that is created following the same
pattern, not only with `mary_corrupt.txt`.
- The program should be leak-free: any memory that is allocated should be freed before the program terminates.
- The program has to be documented (file preamble with brief description and name of the author, 
inline comments). 


### Deliverables: 

Implementation of the program in file `prob2.c`. 

## Problem 3 (30 points) 

The program in `prob3.c` extract information about bit-vector representation of six single precision
floating point numbers. It uses several functions to accomplish that. Your job is to implement most of those functions.
The header file `proj1.h` provides the declarations and descriptions of those functions. 
The definitions of those function should be written in `proj1.c`. 

The program in `prob3.c`  should serve as a guide for correctness of the implementation, but passing those tests does not guarantee the correctness of the implementation. We will test the function implementation on other values. 



### Programming requirements:

- Implement the required functions in `proj1.c` file: 

        int is_normalized ( float f ) ;
        int is_denormalized ( float f );
        int is_special ( float f ) ;
        char * get_M ( float f ) ;
        int get_s ( float f );
        int get_E ( float f ) ;
- Implement any additional functions in `proj1.c` files. Add the declarations of those
functions to `proj1.h` if need be. 
- The functions should work with any single precision floating point numbers. 
- The program should be leak-free: any memory that is allocated should be freed before the program terminates.
- The code has to be documented (the author's name in `proj1.c`, function descriptions, inline comments).  
- You should not  use any of the functions defined in the math library. 


### Deliverables: 
Implementation if functions in `proj1.c` file.



## Problem 4 (30 points) 

The program in `prob4.c` converts six bit-vectors to their single precision
floating point equivalents. It uses several functions to accomplish that. Your job is to implement most of those functions.
The header file `proj1.h` provides the declarations and descriptions of those functions. 
The definitions of those function should be written in `proj1.c`. 

The program in `prob4.c`  should serve as a guide for correctness of the implementation, but passing those tests does not guarantee the correctness of the implementation. We will test the function implementation on other values. 



### Programming requirements:

- Implement the required functions in `proj1.c` file: 

        float get_float_from_bits( char * bits ) ;  
        type get_type_from_bits( char * bits ) ;
        int get_s_from_bits ( char * bits ); 
        int get_E_from_bits ( char * bits ); 
        float get_M_from_bits ( char * bits ); 
- Implement any additional functions in `proj1.c` files. Add the declarations of those
functions to `proj1.h` if need be.
- The functions should work with any 32-bit long c-string sequences.
- The program should be leak-free: any memory that is allocated should be freed before the program terminates.
- The code has to be documented (the author's name in `proj1.c`, function descriptions, inline comments). 
- You should not  use any of the functions defined in the math library. The only exception
is the use of `pow()` function in the computations of the 
final formula (-1)^s * M * 2^E in `get_float_from_bits()` function. 


### Deliverables: 
Implementation if functions in `proj1.c` file.

======================================

**Expected output from `prob3.c`**: 

    Test 0 PASSED. 
        value 2.010000e+02
        bit vecotr 01000011010010010000000000000000 
        2.010000e+02 is normalized 
        E = 7
        M = 1.10010010000000000000000
        s = 0

    Test 1 PASSED. 
        value 1.200000e+38
        bit vecotr 01111110101101001000111001010010 
        1.200000e+38 is normalized 
        E = 126
        M = 1.01101001000111001010010
        s = 0

    Test 2 PASSED. 
        value -1.024250e+03
        bit vecotr 11000100100000000000100000000000 
        -1.024250e+03 is normalized 
        E = 10
        M = 1.00000000000100000000000
        s = 1

    Test 3 PASSED. 
        value 1.401298e-45
        bit vecotr 00000000000000000000000000000001 
        1.401298e-45 is denormalized 
        E = -126
        M = 0.00000000000000000000001
        s = 0

    Test 4 PASSED. 
        value inf
        bit vecotr 01111111100000000000000000000000 
          inf is special 
        E = 255
        M = 
        s = 0

    Test 5 PASSED. 
        value -nan
        bit vecotr 11111111110000000000000000000000 
         -nan is special 
        E = 255
        M = 
        s = 1



**Expected output from `prob4.c`**: 

    Test 0 PASSED. 
                  bit vector:  01000011010010010000000000000000
               correct value:  2.010000e+02
              computed value:  2.010000e+02
                               E: 7 
                               M: 1.570312e+00 

    Test 1 PASSED. 
                  bit vector:  01111110101101001000111001010010
               correct value:  1.200000e+38
              computed value:  1.200000e+38
                               E: 126 
                               M: 1.410593e+00 

    Test 2 PASSED. 
                  bit vector:  11000100100000000000100000000000
               correct value:  -1.024250e+03
              computed value:  -1.024250e+03
                               E: 10 
                               M: 1.000244e+00 

    Test 3 PASSED. 
                  bit vector:  00000000000000000000000000000001
               correct value:  1.401298e-45
              computed value:  1.401298e-45
                               E: -126 
                               M: 1.192093e-07 

    Test 4 PASSED. 
                  bit vector:  01111111100000000000000000000000
               correct value:  inf
              computed value:  inf
                               E: 255 
                               M: inf 

    Test 5 PASSED. 
                  bit vector:  11111111110000000000000000000000
               correct value:  -nan
              computed value:  -nan
                               E: 255 
                               M: nan 
