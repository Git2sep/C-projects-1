/*
 * author:  Christian Miljkovic
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_1_opt. It should perform the same 
// task as the implemented level_1 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry. 

long level_1(long * B, long * A, int x)
{
    long * C = (long * ) malloc (N*sizeof(long) );
    if (!C) return 0; 
    
    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r ] += B[ r*N + c ] + A[ c*N + r ] ;

    long ret = C[x];
    free (C); C = 0; 
    return ret;
}


/*
This function does the same as the level_1 function above, however,
it is optimized by minimizing cache misses by reducing the stride when
the array's B and A are accesed thus increasing spatial locality. 
This is done through splitting the double for loop
into two seperate nested for loops.
*/
long level_1_opt(long * B, long * A, int x)
{
    // DO NOT modify the following declarations 
    long * C = (long * ) malloc (N*sizeof(long) );
    if (!C) return 0; 
    
    // enter your code here 
    int c, r, k; //using the k variable in order to store a multiplication for temporal locality

    //we want to split the for loops in half because if we don't then one of the array's
    //will be accessed with stride-N thus reducing spatial locality
    for(r = 0; r < N; r++) { //we switch c with r because then B will be accessed in a
                                //stride-1 fashion

        k = r*N; //this is in order to help with temporal locality by placing 
                //the calulation in the register, so that it does not need to happen again


        for(c = 0; c < N; c++) {

            //we only include the reference to B array otherwise accessing A would "clog"
            //the cahce's and also reduce spatial locality causing thrashing
            C[ r ] += B[ k + c ];
        }
    }

    //now here we perform the other part of the split for loop so as to take advantage of 
    //spatial locality due to stride-1 accessing and also temporal locality since we are 
    // only focusing on array A
    for(c = 0; c < N; c++) {

        k = c*N; //this is in order to help again with temporal locality
        for(r = 0; r < N; r++) {

            C[ r ] += A[k + r];
        }
    }


    //DO NOT modify the rest of this function 
    long ret = C[x];
    free (C); C = 0; 
    return ret;
}


