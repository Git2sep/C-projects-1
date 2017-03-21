#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "proj1.h"

/* 
 * Test program for problem 3.
 * This program makes use of functions that extrac
 * bit-level representation of single precision floating
 * point values. 
 * 
 * DO NOT MODIFY THE CONTENT OF THIS FILE 
 */ 


int main()
{
    int i;
    //values for conversion
    float values[6] = {201.0, 1.2e+38, -1024.25,  1.401298e-45, INFINITY, -NAN };
    

    //correct values after conversion
    int values_E[6] = {7, 126, 10, -126, 255, 255};
    char * values_M[6] = { "1.10010010000000000000000", "1.01101001000111001010010", 
        "1.00000000000100000000000", "0.00000000000000000000001", "\0", "\0" } ;
    int signs[6] = {0, 0, 1, 0, 0, 1 }; 
     
    //test function on the six different values  
    for (i = 0; i < 6; i++){
        float f = values[i];
        
        int value_E = get_E(f); 
        char * value_M  = get_M(f);
        int sign = get_s(f); 
        
        //determine correctness of the results 
        if( assert_equals_int(value_E, values_E[i]) 
            && assert_equals_string(value_M, values_M[i] ) 
            && assert_equals_int (sign, signs[i] ) ) {
                
            printf("Test %i PASSED. \n", i );
        }
        else {
            printf("Test %i FAILED. \n", i );
        }
        
        //print values and the results 
        printf("\tvalue %e\n", f );
        char * bits = get_bits_float(f); 
        printf("\tbit vecotr %s \n", bits ); 
        
        if ( is_normalized( f ) )
            printf ("\t%e is normalized \n", f );

        if ( is_denormalized( f ) )
            printf ("\t%e is denormalized \n", f );
        
        if ( is_special( f ) )
            printf ("\t%5.3f is special \n", f );
        
        printf( "\tE = %d\n", value_E);
        printf( "\tM = %s\n", value_M);
        printf( "\ts = %d\n", sign );
        printf("\n");
        
        //free memory 
        if (value_M != NULL) {
            free(value_M);
            value_M = NULL;
        } 
        if (bits != NULL ) {
            free(bits);
            bits = NULL;
        } 
    }
    
    return 0;
}
