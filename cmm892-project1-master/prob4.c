#include <math.h>
#include <stdio.h>
#include "proj1.h"

/* 
 * Test program for problem 4.
 * This program makes use of functions that convert the
 * bit-level representation of single precision floating
 * point values to their numerical equivalents. 
 * 
 * DO NOT MODIFY THE CONTENT OF THIS FILE 
 */ 

int main()
{
    int i;
    //values for conversion
    float values[6] = {201.0, 1.2e+38, -1024.25,  1.401298e-45, INFINITY, -NAN };

    //correct values after conversion
    char* bit_vectors [6] = {"01000011010010010000000000000000", "01111110101101001000111001010010", 
            "11000100100000000000100000000000", "00000000000000000000000000000001",
            "01111111100000000000000000000000", "11111111110000000000000000000000" };
            
    //test function on the six different values          
    for ( i = 0; i < 6; i++ ) {
        float f = get_float_from_bits (bit_vectors[i]); 
        int status = assert_equals_float( f, values[i] ) ;
        
        //determine correctness of the results 
        if (status) {
            printf("Test %i PASSED. \n", i );
        }
        else {
            printf("Test %i FAILED. \n", i );
        }
        
        //print values and the results 
        printf("\t%20s:  %s\n", "bit vector", bit_vectors[i] ) ;
        printf("\t%20s:  %e\n", "correct value", values[i] ) ;
        printf("\t%20s:  %e\n", "computed value", f ) ;
        printf("\t\t%20s: %i \n", "E", get_E_from_bits(bit_vectors[i]) ); 
        printf("\t\t%20s: %e \n", "M", get_M_from_bits(bit_vectors[i]) );  
        printf("\n");
    }
    return 0;
}
