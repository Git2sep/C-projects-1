# Project 2: Working with Object Code 

Due date: April 9 at 11:55pm. 

**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own. 
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help 
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part 
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

-----

Things to remember for all of the programs:

- The assembly code generated from the code that you write may not be exactly the same as the decompiled versions of the posted files. It is sufficient that the functions perform the same tasks for all inputs.
- The program project2 tests your functions on a limited set of inputs. The fact that your implementation passes the test does not guarantee that the code that you wrote is correct.


## Project Description

In this lab, we give you 5 object files, problem1.o, problem2.o, ..., problem5.o, and withhold their corresponding C sources. 
Each object file implements a particular function (e.g. problem1.o defines function `problem1`). The later
objects files contain an additional function. We ask you to understand the x86-64 assembly code for each of these 
functions and figure out what that function tries to do. Your task is to write the C code for all the functions. 

The problems are numbered in order of difficulty. You should attempt to solve them in that order. But you can jump around
and work on the problems in any order you wish (this is definitely a good strategy if you are stuck on a particular problem). 

## Reading the Assembly

The object files whose assembly code you seek to understand are in the `objs/` subdirectory.
Suppose you set out to figure out what function `problem1` (implemented in objs/problem1.o) does. 
Here are two approaches to do this. You should use them both to help uncover the mystery.

### Using `objdump` 

Disassemble the object files. Read the assembly and try to understand what the function tries to achieve. To disassemble 
`problem1.o`, run 

    objdump -rd problem1.o  
    
(same applies to the object files for all other problems). 

### Using `gdb` 

You can build an executable program from the object files in the `objs` subdirectory. To do so, run 

    make clean
    make project2_given 

This produces the program `project2_given`.  
You can run this program in `gdb`. 
This will/may help you to determine how the other functions are called and what arguments
are passed to them.  



## Writing Your C Functions 

The repository contains all files you need to work on this project. There are the problem files 
`problem1.c` ... `problem5.c` and the header file `project2.h`. You need to develop your code within those files. 

To compile each function use the provided `Makefile` as follows: 

    make clean
    make problem1.o

This should generate your object code for `problem1.c`. For other problems, simply replace the number 1 with the number of the problem. 




## Test Your Solutions


After you finish each function you can test its correctness (or at least partially test its correctness) as follows:

    make clean
    make project2
    ./project2 
    problem1 passed the initial test
    problem2 passed the initial test
    problem3 passed the initial test
    problem4 passed the initial test
    problem5 passed the initial test

This suggest that all functions run correctly on these limited initial tests. 



*NOTE: Passing the tests does not guarantee that you will get a perfect grade (i.e. your implementation is not necessarily correct).
During grading, we will manually examine your source code to determine its correctness. 
(If you look carefully at the code for  `project2` you could figure out how each test works and how to write you functions
to satisfy the particular test that `project2` program uses (by simply returning what the test expects to be returned). <br>
DO NOT DO THAT! We will use a different test program to validate your functions.)*



## Programming requirements:

- The C code has to be written following the high-level programming language conventions - it has to look like C, not like assembly transliterated to C: 
    - no `goto` statements, 
    - all computations should be simplified as much as possible 
    - etc
    
- Some of the functions used may be very simple and could be combined into a single function - do not do that! 
All functions should be implemented (if there is a call to a function in assembly that you see in the decompiled object files, then you should be implementing that function - unless, of course, it is a call to one
of the library functions). 

- All functions should to be documented
    - Include one to two sentence description of what the function is doing above each function definition.
    - Include inline comments. 
    - Include the name of the author in every file that you write. 



## Committing and Pushing Your Work 

You should commit your code regularly to the repository on GitHub (this is your backup and a proof to us that you are working on it).
At the least, you should commit your work after every single problem. You are **required** to make at least 5 commits (including the push to the remote repository) before the due date for the project. 

Please, run `make clean` before committing the changes so that the object files are not uploaded together with your sources. 

## Brain Teaser  

There is an additional file in the repository for those who finish early. Figuring out the
C code for the brain_teaser.o function is optional and will not be graded. Consider that
an extra challenge once you complete all other problems. 

