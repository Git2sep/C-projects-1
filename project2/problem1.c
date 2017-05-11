#include "project2.h" 

//This function takes four long parameters q,x,y,z then
//checks to see if x is non-negative, and if so changes the value of z.
// then later performs the equivalent of bit shift operations on the other values
// and returns the sum and product of these values once the equivalent shifts have occured.
//@authoer: Christian Miljkovic - 04/3/17

long problem1(long q, long x, long y, long z) {
	
	long returnVal;

	//check to see if x is non-negative
	if(x>=0) {

		//if non-negative then add 3 to the value in register z
		z += 3;
	}

	//once done checking divide x by 4 in order to add it to the value within q
	x = x/4;
	q = q + x;

	//calculate the value that is to be returned
	returnVal = (12 * y) + q;

	return returnVal;

}
