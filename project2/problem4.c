#include "project2.h" 
/*
This function takes a pointer and an int, and uses the int for a loop
and then dereferences the pointer vairbale to use the value and multiply it 
over and over again. 
@author: Christian Miljkovic - 04/09/17
*/
long comp4(int *x, int y) {
	
	//create a counter for the loop
	int counter = 0;

	//create the return val
	long retunVal = 1; // make it equal to one because you will be multiplying

	while(y > counter) {

		//multiply the value given by the pointer until loop finishes
		retunVal *= (*x); //dereference the pointer given

		//dont forget to incremenet the counter
		counter += 1;
	}

	//return the computed variable from the loop
	return retunVal;
}

/*
This function takes two int variables q and r, and then computes 
the sum of q^3 until q reaches the value of r, all while adding this to a single
holding variable which is later returned. 
@author: Christian Miljkovic - 04/09/17
*/
long problem4(int q, int r) {

	//create the return val
	long returnVal = 0;

	//loop through using the given parameters
	while(q <= r) {

		//continuously add to the return value whatever is given by the call to the function
		returnVal += comp4(&q, 3);

		//dont forget to increment
		q += 1;

	}

	//return what was given from the computation in the while loop
	return returnVal;
	
}
