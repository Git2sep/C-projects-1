#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "proj1.h"



/*********************************
 * Problem 3 required functions  *
 *********************************/

int is_normalized ( float f ) {

	//get the bit representation of the floats
	char* bits = get_bits_float (f);

	int i;

	//these are used to check if there are zero's in the string
	int zero = 0;
	int one = 0;

	//start at 1 since we aren't looking at the sign bit
	//loop through the bit representation to see if there are 0's
	for(i=1; i<9; i++) {


		if((bits[i]) == 48)
			zero = zero + 1;

		else
			one = one + 1;
	}

	free(bits);
	bits = NULL;

	//this is to return true or false based upon the result
	if((zero > 0) && (one > 0))
		return 1;

	else
		return 0;

}

/***********/ 

int is_denormalized ( float f ) {

	//get the bit representation of the floats
	char* bits = get_bits_float (f);

	int i;

	//these are used to check if there are zero's in the string
	int zero = 0;
	int one = 0;

	//start at 1 since we aren't looking at the sign bit
	//loop through the bit representation to see if there are 0's
	for(i=1; i<9; i++) {


		if((bits[i]) == 48)
			zero = zero + 1;

		else
			one = one + 1;
	}

	free(bits);
	bits = NULL;


	//this is to return true or false based upon the result
	if((one > 0))
		return 0;

	else
		return 1;

	

}

/***********/ 

int is_special ( float f ) {

	//get the bit representation of the floats
	char* bits = get_bits_float (f);

	int i;

	//these are used to check if there are zero's in the string
	int zero = 0;
	int one = 0;

	//start at 1 since we aren't looking at the sign bit
	//loop through the bit representation to see if there are 0's
	for(i=1; i<9; i++) {


		if((bits[i]) == 48)
			zero = zero + 1;

		else
			one = one + 1;
	}

	free(bits);
	bits = NULL;


	//this is to return true or false based upon the result
	if((zero > 0))

		return 0;

	else
		return 1;
}

/***********/ 

char * get_M ( float f ) {

	//get the bit representation of the floats
	char* bits = get_bits_float (f);

	int i;

	//create the buffer
	char * buffer;

	//allocate memory for the buffer
	buffer = (char *)malloc(sizeof(char) * 24);

	//based upon whether it is normalized or not we have 1 or 0 in the front
	if (is_denormalized(f)) {
		*(buffer + 0) = '0'; 

		//add the period 
		*(buffer + 1) = '.';
	}

	else if(is_normalized(f)) {
		*(buffer + 0) = '1';

		//add the period 
		*(buffer + 1) = '.';	
	}




	if(!is_special(f)) {
		//start at 9 since we aren't looking at the sign bit or exp
		//loop through the bit representation and add to the buffer
		for(i=9; i<33; i++) {
			//increment through the bits and add to the buffer
			*(buffer + (i - 7)) = bits[i];
			}
		}

	else {
		*(buffer) = '\0';
	}
	

	free(bits);
	bits = NULL;
	return buffer;

}

/***********/ 

int get_s ( float f ) {
	
	//get the bit representation of the floats
	char* bits = get_bits_float (f);

	free(bits);
	return (bits[0] - 48);


}

/***********/ 

int get_E ( float f ) {
	
	if(is_special(f)) 
		return 255;

	else if(is_denormalized(f)) 
		return -126;

	else {
		//get the adress of the float and cast it to int so we can manipulate
		int n = *((int*) (&f));

		//now shift the bits so that we can use bitwise & to compare
		return ((n>>23) &(0b11111111)) -127; //subtract 127 because half the numbers will be negative
	} 
}





/*********************************
 * Problem 4 required functions  *
 *********************************/


float get_float_from_bits( char * bits ) {

	//get all the variables needed here
	float s = get_s_from_bits(bits);
	float M =  get_M_from_bits(bits);
	float E = get_E_from_bits(bits);

	float answer = pow(-1.0,s)*M*pow(2.0,E);

	free(bits);
	bits = NULL;
	return answer;

}

/***********/ 

type get_type_from_bits( char * bits ) {

	//loop through the exp part and count the zero's and the one's
	int zero = 0;
	int one = 0;
	int i;

	for(i=1; i<9; i++) {

		if((bits[i]-48)==0) {
			zero++;
		}
		else {
			one++;
		}
	}


    

	//now based upon the resluts of the incremented zeros and ones
	//return the correct type
	if((zero > 0) && (one > 0))
		return NORM;

	if(one > 0)
		return SPECIAL;

	else 
		return DENORM;
	
}

/***********/ 

int get_s_from_bits ( char * bits ){
        
    int s = *(bits);
           
    free(bits);
	bits = NULL;
    return s;

}

/***********/ 


int get_E_from_bits ( char * bits ) {


	if(get_type_from_bits(bits)==SPECIAL)
		 return 255;

	else if (get_type_from_bits(bits)==DENORM)
		return -126;


	else {

		//initialize the exp value
		int exp = 0;
	    
	    //use a for loop to loop backwards and figure out the exponents
	    int i;
	    int j=0; //use this to increment for the subtraction later
	    int e = 0;

		for(i=8; i!=0; i--) {

			//make sure that the bit returned is 1
			if((bits[i])=='1') {

				e = pow(2,(i - (8-(2 * (j)))));
				exp = exp + e;

				
			}


			j++;
		}

		int bias = 127;

		int E = exp - bias;


	       
	    return E;

	}
}

/***********/ 


float get_M_from_bits ( char * bits ) {

	if(get_type_from_bits(bits)==SPECIAL) {

		int z;
		//check if there are any ones in the frac
		for(z=9; z!=32; z++) {
			if(bits[z]=='1')
				return sqrt(-1);
		}


		return INFINITY;
	}


	else {

		//get the first digit that you will add to later
		float start = 0;
		if(get_type_from_bits(bits)==NORM)
			start = 1;

		//using a for loop increasingly divide the following numbers and add it to the start variable
		int i;

		//start from one because we are going to divide by 10^i
		for(i=9; i!=32; i++) {
			if(bits[i]=='1')
				start += 1.0/(pow(2,i-8));

		}
	    
	    return start;

	}
    
}




/********************************************************************
 * Problem 3 and 4 additional functions  
 ********************************************************************
 * 
 * Specify an additional function declarations in this section.
 ********************************************************************/











/********************************************************************
 * Other functions   
 ********************************************************************
 *
 * You do not have to use the following functions in your own code, 
 * but do not remove them from this file. 
 ********************************************************************/


char* get_bits_int ( int n ) {
	//allocate memory to store the string 
	int num_of_bits =  sizeof(int) * 8;  //*8 since there are 8 bits per byte 
	char * bits_of_numbers = (char*) malloc( num_of_bits + 1);
	
	short bit ; 
	
	int i;
	//convert value of n to bits 
	for ( i = 0; i < num_of_bits; i++ ) {
		bit = n & 1; //grab the last bit
		bits_of_numbers[num_of_bits-i-1] = '0' + bit;
		n = n>>1;    //remove the last bit
	}
	
	bits_of_numbers[num_of_bits] = '\0'; //end with a null character
	return bits_of_numbers; 
}

/***********/ 

char* get_bits_float ( float f ) {
	//allocate memory to store the string
	int num_of_bits =  sizeof(float) * 8;  //*8 since there are 8 bits per byte 
	char * bits_of_numbers = (char*) malloc( num_of_bits + 1);
	
	//interpret the bits as int (this is not equivalent to casting to int) 
	int  p = *((int*) (&f) );
	short bit ; 
	
	int i;
	//convert value of n to bits 
	for ( i = 0; i < sizeof(float)*8; i++ ) {
		bit = p & 1;  //grab the last bit
		bits_of_numbers[num_of_bits-i-1] = '0' + bit;
		p = p>>1;    //remove the last bit
	}
	
	bits_of_numbers[num_of_bits] = '\0'; //end with a null character
	return bits_of_numbers; 
	
}


/***********/ 

int  assert_equals_int(int a, int b){
	if (((unsigned)(a) ^ (unsigned)(b)) == 0 ){
		return 1; 
	}
	else{
		return 0; 
	}
}

/***********/ 

int assert_equals_float(float a, float b){
    unsigned * pa = (unsigned *)(&a);
    unsigned * pb = (unsigned *) (&b);
    if ( ( (*pa) ^ (*pb) ) == 0 ){
		return 1; 
	}
	else{
		return 0; 
	}
}
 
/***********/ 

int assert_equals_string(char* a, char * b){
	return ! strcmp(a,b);
}

/***********/ 














    





    

    






      



    
    
