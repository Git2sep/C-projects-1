/* Here we have the declerations of the headers with the functions that are going to be used*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/* 
 * Source code based on the code example in the manual
 * page for getline().
 */ 

int main(void)
{
   FILE *stream;   /*declaring a File pointer in memory*/
   char *line = NULL;
   size_t len = 0;
   ssize_t read; /*this is initialized to zero since it is a global variable*/

   stream = fopen("/usr/include/string.h", "r"); /*this function opens the string.h header file and reads it*/
   if (stream == NULL) /*if stream doesn't become a pointer then exit*/
       exit(EXIT_FAILURE);


  //read variable is holding what getline returns, and if it equals -1 that means 
  //that it is the end of the string... so read is essentailly taking in the stream of characters from the file
  //getLine doesn't stop when it comes across a NULL value
  //get line requires size_t btw and is defined in stdlib.h
  //&line is the address where the first character of the input string will be located
  //&len is the address that holds the size of the input buffer
  //stream is the string of characters that are being read from the string.h header file
   while ((read = getline(&line, &len, stream)) != -1) {
       printf("Retrieved line of length %zu :\n", read); //zu is for size_t variables so tells us how long the string is
       printf("%s", line); //this prints out the actual string of characters
   }

   free(line); //deallocates the memory used for line
   fclose(stream); //need to do this because then we are still teading the file
   exit(EXIT_SUCCESS);
}
