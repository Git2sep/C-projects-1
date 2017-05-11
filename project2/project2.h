

#ifndef _PROJECT2_H_
#define _PROJECT2_H_


//This function takes four long parameters q,x,y,z then
//checks to see if x is non-negative, and if so changes the value of z.
// then later performs the equivalent of bit shift operations on the other values
// and returns the sum and product of these values once the equivalent shifts have occured.
//@authoer: Christian Miljkovic - 04/3/17

long problem1(long q, long x, long y, long z);


/*
/This function takes a long integer and swaps the highest bits with the lowest bits,
/then returns the newly created integer.
/author: Christian Miljkovic - 04/3/17
*/
int problem2(int x);


/*
This program takes a parameter x and checks to see if it is less than zero.
If it is less than zero it will increment x until it is positive, and then also 
keep track of how many times you had to increment x and return that number.
author: Christian Miljkovic - 04/3/17
 */
int problem3(int x);


/*
This function takes a pointer and an int, and uses the int for a loop
and then dereferences the pointer vairbale to use the value and multiply it 
over and over again. 
@author: Christian Miljkovic - 04/09/17
*/
long comp4(int *x, int y);


/*
This function takes two int variables q and r, and then computes 
the sum of r^3 until r reaches the value of q, all while adding this to a single
holding variable which is later returned. 
@author: Christian Miljkovic - 04/09/17
*/
long problem4(int q, int r);

/*
This procedure takes a pointer to an array, and the length of the array
then loops through the array and changes the variables within in it by 
multiplying it by 201.
@author: Christian Miljkovic - 04/09/17
*/
void comp5(long *array, int len);

/*
This function takes an int size as a parameter in order to create an array of the specified size.
Then once the memory is allocated and array is created loop through the array and place
the index value that corresponds to the given location in the array. Once the looping is copmplete,
pass the created array into comp5 where the values inside the array will be multipled by 201 and then
return this newly computed array.
@author: Christian Miljkovic - 04/09/17
*/
long* problem5(int size);

#endif



