#include "project2.h" 
#include <stdlib.h> 
#include <stdio.h>

/*
This procedure takes a pointer to an array, and the length of the array
then loops through the array and changes the variables within in it by 
multiplying it by 201.
@author: Christian Miljkovic - 04/09/17
*/
void comp5(long *array, int len) {

	//create a counter so that you can loop through the array
	int i = 0;

	//create two seperate temp variables so that you can change the data in the array
	long temp;
	long *pt_temp;

	//loop through the array
	while(i < len) {

		//get the location of the index within the array
		pt_temp = &(array[i]);

		//now dereference the value from the memory location
		temp = *pt_temp;

		//now write to the memory location and change the value by 
		//multiplying by 201
		*pt_temp = 201*temp;

		//dont forget to counter
		i++;
	}

	
}
/*
This function takes an int size as a parameter in order to create an array of the specified size.
Then once the memory is allocated and array is created loop through the array and place
the index value that corresponds to the given location in the array. Once the looping is copmplete,
pass the created array into comp5 where the values inside the array will be multipled by 201 and then
return this newly computed array.
@author: Christian Miljkovic - 04/09/17
*/
long* problem5(int size) {
	


	//allocate enough memory for the array of the size given by the parameter
	long *array = (long*)malloc(size*sizeof(long)); //we want the array to be of type long

	//check to make sure that the value of the size of the array to be created is not zero
	//indicating that malloc was succesful 
	if(array == 0) { 
		return 0; 
	}


	//create a counter variable that will help loop through the newly created array
	int i = 0;

	//loop through the array and fill in each position or location with the index number
	while(i < size)	 {

		//index the array and input the index value in that position
		array[i] = i;

		//don't forget to increment the counter
		i += 1;
	}

	//now call the comp5 function in order to change the values within the array 
	comp5(array, size);


	//return the newly computer array
	return array;

}
