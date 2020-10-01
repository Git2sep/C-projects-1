#include "project2.h"  
/*
/This function takes a long integer and swaps the highest bits with the lowest bits,
/then returns the newly created integer.
/author: Christian Miljkovic - 04/3/17
*/
int problem2(int x) 
{

	int temp,a; 
	printf("Enter a number");
	scanf("%d",&a);
	//make sure to hold the digits that you want to swap
	temp = (x>>a);

	//push off the digits that you already have
	//by shifting the original digit then add the buffer variable
	x = (x<<a) + temp;

	return x;

	
}
