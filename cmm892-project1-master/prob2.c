
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char swap (unsigned char c);

/*
 * This program unscrambles any text by changing the higher and lowest order bits 
 and then outputs the to a text file that is given within the parameters.
 author: Christian Miljkovic
 */ 

//argc lets us index argv[] and argv contains the input and output files
int main (int argc, char *argv[] )  {
    
   FILE *stream;   /*declaring a File pointer in memory*/
   char *line = NULL;
   size_t len = 0;
   ssize_t read; /*this is initialized to zero since it is a global variable*/
   FILE *output;
    
   stream = fopen(argv[1], "r"); /*this function opens the argc file and reads it*/
   if (stream == NULL) /*if stream doesn't become a pointer then exit*/
       exit(EXIT_FAILURE);

    output = fopen(argv[2],"w");
    if(output == NULL)
    	exit(EXIT_FAILURE);


   //read points to line
   while ((read = getline(&line, &len, stream)) != -1) {

	   	
	   	int i;
		for(i = 0; i < read; i++) {
			unsigned char c = (unsigned char) *(line + i);
			fprintf(output, "%c", swap(c));
		} 
   }

   //close off any allocated memory 
   fclose(argv[1]);
   fclose(argv[2]);
   return 0;

}

/*
This function takes an unsigned character and swaps the 4 highest order bits
with the lowest order bits.
Returns the character with the swaped 4 highest and lowest order bits.
*/
unsigned char swap (unsigned char c) {

	return (unsigned char)(((c)>>4)+((c)<<4));
}
