# Problem 1 

1. There is a call to `free()` on line 26 of `prob1.c`. Which function allocates
the memory that is freed be this call? <br>
**Answer:**
the getline function does the allocation of memory and stores it in the &line using .

2. How many times is the function that you named in answer to 1 called? <br>
**Answer:**
645

3. Does the program have a memory leak? Explain your answer. <br>
**Answer:**
There are no memory leaks because the only allocated memory occurs when getline is called which is then freed at the end. All of the allocation and freeing of memory occurs within the function.


