/*
 * author: Christian Miljkovic 
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_2_opt. It should perform the same 
// task as the implemented level_2 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 

// Note: you may observe that this function performs "useless" looping
// over an array of structures that are all filled with zero bits. 
// Your task is not to remove that "useless" code, but modify it 
// so that it is more cache friendly. 
// You also should not be removing any parts of the structures.
//
// (In an actual application, the structures would be populated with
// real data and the loop would be computing some real results.) 


char * level_2()
{    
    data_2 * B = (data_2 * ) calloc( LARGER, sizeof(data_2) ) ;
    if (!B) return 0; 
    double sum_f = 0.0;
    double sum_n = 0; 
    char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) );    
    sum_c[2*LARGER] = '\0'; 
    
    int i; 

    for(i = 0; i < LARGER; i++){
        sum_f += B[i].f1 + B[i].f2; 
    }

    for(i = 0; i < LARGER; i++){
        sum_n += B[i].n1 + B[i].n2; 
    }

    for(i = 0; i < LARGER; i++){ 
        sum_c[2*i] = B[i].c1;
    }

    for(i = 0; i < LARGER; i++){
        sum_c[2*i+1] = B[i].c2;
    }
    
    
    free(B); 
    return sum_c;
}


/*
This function is the same as the level_2 function above except it is optimized
to minimize cache misses by condensing the for loops in the above function
into two for loops, and performing the neccesary operations there. This
takes advantage of the temporal locality, and also takes advantage of an optimized
data structure which can be found in the header file.
*/
char * level_2_opt()
{    
    // DO NOT modify the following declarations 
    double sum_f = 0.0;
    double sum_n = 0;           //use bitwise because it is faster
    char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) );    
    sum_c[2*LARGER] = '\0';    //again use bitwise multiplication because it is faster
    
    // enter your code here (make sure to free the array B once 
    // before returning) 
    data_opt_2 * B = (data_opt_2 * ) calloc( LARGER, sizeof(data_opt_2) ) ;
    if (!B) return 0;
    
    int i;

    //condense the for loops into 2 so you avoid going over the same data in memory
    //this takes advantage of spatial and temporal locality because you are using the
    //data that you need repeatedly
    for(i = 0; i < LARGER; i++) {

        sum_f += B[i].f2 + B[i].f1; //since the order of the struct data fields start with 
        sum_n += B[i].n1 + B[i].n2;  //double then float then int we access this information in sequential order

        //we use an if-else statement in order to condense the previous for loops
        //in order to eliminate the stride2 accessing and bring it to stride1
     }

     //we have to add 2 to the i because over the i+1 being accessed so we need to
     //jump by two, this is where the temporal locality becomes apparent.
     for(i = 0; i < LARGER; i+=2) {   //use i again for temporal locality

        sum_c[i] = B[i].c1; //again due to the strucutre we access this one first
        sum_c[i+1] = B[i].c2;
    }
    
    free(B);
    //DO NOT modify the rest of this function 
    return sum_c;
}

