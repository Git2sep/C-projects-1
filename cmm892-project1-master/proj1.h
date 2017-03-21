/*
 * This is the header file for project 1.
 * It contains declarations of functions
 * that are defined in proj1.c file.
 * 
 * If you define any additional functions, 
 * you should add their declarations to this file
 * in an appropriate section below.  
 * 
 */ 

#ifndef PROJ1_H_
#define PROJ1_H_

const static int MAX_LINES = 1000;
const static int BIAS = 127;
const static int FRAC_BITS = 23;
const static int EXP_BITS = 8;
const static int FLOAT_BITS = 32; 

typedef enum type { DENORM, NORM, SPECIAL } type; 



/*********************************
 * Problem 3 required functions  *
 *********************************/

/*
 * Determines if the parameter f represented using
 * IEEE single precission floating point is using normalized 
 * encoding. Returns zero to indicate false, and any non-zero 
 * value to indicate true.
 * Assumption sizeof(int) = sizeof(float).
 */
int is_normalized ( float f ) ;

/*
 * Determines if the parameter f represented using
 * IEEE single precission floating point is using denormalized 
 * encoding. Returns zero to indicate false, and any non-zero 
 * value to indicate true.
 * Assumption sizeof(int) = sizeof(float).
 */
int is_denormalized ( float f );

/*
 * Determines if the parameter f represented using
 * IEEE single precission floating point is using special value 
 * encoding. Returns zero to indicate false, and any non-zero 
 * value to indicate true.
 * Assumption sizeof(int) = sizeof(float).
 */
int is_special ( float f ) ;

/*
 * Computes and return the value of M (fractional part) of   
 * IEEE single precission floating point number. 
 * Assumption sizeof(int) = sizeof(float).
 * get_M() allocates memory to store the bit-level representation
 * of the fractional part of f. 
 */
char * get_M ( float f ) ;

/*
 * Computes and return the value of s (sign) of   
 * IEEE single precission floating point number. 
 * Assumption sizeof(int) = sizeof(float).
 */
int get_s ( float f );

/*
 * Computes and return the value of E (exponent) of   
 * IEEE single precission floating point number. 
 * Assumption sizeof(int) = sizeof(float).
 */
int get_E ( float f ) ;





/*********************************
 * Problem 4 required functions  *
 *********************************/

/* 
 * Computes and returns the IEEE single precision floating point number
 * represented by the bit-vector bits. 
 */ 
float get_float_from_bits( char * bits ) ;  

/* 
 * Computes and returns the type (normalized, denormalized or special)
 * of the IEEE single precision floating point number
 * represented by the bit-vector bits. 
 * Returns NORM, DENORM or SPECIAL to denote normalized, denormalized or 
 * special encoding. 
 */ 
type get_type_from_bits( char * bits ) ;
 
/* 
 * Computes and returns the sign bit
 * of the IEEE single precision floating point number
 * represented by the bit-vector bits. 
 * Returns 0 or 1 to denote the leading bit of the bit vector 
 * (0 indicates positive value, 1 indicates negative value). 
 */ 
int get_s_from_bits ( char * bits ); 
  
/* 
 * Computes and returns the value of the exponent
 * of the IEEE single precision floating point number
 * represented by the bit-vector bits. 
 * Returns the actual value of the exponent for both normalized 
 * and denormalized encodings, or 255 for the special encoding.  
 */ 
int get_E_from_bits ( char * bits ); 
  
/* 
 * Computes and returns the value of the fractional part (represented 
 * in decimal) of the IEEE single precision floating point number
 * represented by the bit-vector bits. 
 * Returns the actual value of the fractional part for both normalized 
 * and denormalized encodings; returns NAN or INFINITY for specialized encoding.   
 */ 
float get_M_from_bits ( char * bits ); 




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



/*
 * Computes and returns a c-string containting
 * the binary vector representation of the parameter n. 
 * get_bits_int() allocates memory to store the bit-level representation
 * of the number n.
 */
char * get_bits_int ( int n );

/*
 * Computes and returns a c-string containting
 * the binary vector representation of the parameter f. 
 * get_bits_float() allocates memory to store the bit-level representation
 * of the number f.
 */
char * get_bits_float ( float f );



/* 
 * Determines if the two function arguments are equal or not. 
 * Returns 0 to indicate false, anything else to indicate true. 
 */ 
int  assert_equals_int(int a, int b);

/* 
 * Determines if the two function arguments are equal or not. 
 * Returns 0 to indicate false, anything else to indicate true. 
 */ 
int assert_equals_float(float a, float b);

/* 
 * Determines if the two function arguments are equal or not. 
 * Returns 0 to indicate false, anything else to indicate true. 
 */ 
int assert_equals_string(char* a, char * b);



#endif
