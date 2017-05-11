#include "project2.h" 
#include <stdio.h>
#include <stdlib.h>

/*
This program takes a parameter x and checks to see if it is greater than zero. 
If so it will increment another variable within a for loop and continuously add a random
number to the variable that will be returned. Once the loop is completed then the variable
calculated within the loop is then divided by x and then returned. Essentially, giving the average
of the random numbers given by the rand() function.
author: Christian Miljkovic - 04/3/17
 */
int problem3(int x) {

	// have a value that you will count the number of increments
	int rando;

	int returnVal = 0;

	//compare x to 0 to see if it is positive
	int y = 0;

	//if x is negative then continuously add to it (while) counting the incremenets as well
	//until y becomes greater than x
	while(x > y) {

		//do the incrementing here
		rando = rand();  //take a random number then add it to the value that you will eventually return
		returnVal = returnVal + rando;
		y = y + 1;
		//dont forget to increment
	}

	//return the amount calculated in the loop divided by y
	returnVal = (returnVal/x);
	return returnVal;

}

