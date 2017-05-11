/*
 * author: Christian Miljkovic 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_3_opt. It should perform the same 
// task as the implemented level_3 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
// Note that this function does not return any value. It modifies the array
// that is passed to it, instead. 

void level_3 (int *A, int n)
{
    int  i, j;
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        A[j*n + i] = A[j*n + i] || A[i*n + j];
          
}


/*
This function is an optimized version of the above function level_3 by minimizing 
the number of cache misses. This is done by inverting the nested for loop which 
as a result access memory in a sequential order, thus taking advantage of spatial locality.
*/
void level_3_opt (int *A, int n)
{
    int i, j, k; //use k here in order to help with spacial locality

    for (j = 0; j < n; j++) { //switch the loops so that when we access A it is not stride-k

    	k = j*n; //this is so we load in this caluclation and don't have to repeat it
    	
    	for (i = 0; i < n; i++) {
    		
    		//use k here that we calculated before
    		A[k + i] =  A[k + i] || A[i*n + j];
    	}
    }
}




