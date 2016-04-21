/*
   Program takes 3 integer values and add them and another part of program takes 
   3 float values and divide the 1st value by 2nd and then divides the result be 3rd value.

   by Ashish Magar (amagar1@binghamton.edu)
*/

#include<stdio.h>

//Declarations
void addValues(int a,int b,int c);
double divideValues(float value1,float value2,float value3);
void callfunc(float n1,float n2,float n3);

//main
int main()
{
	printf("\nWelcome!! This program performs the addition of three integers 2,4,6 \nand division of three numbers 36.0,3.0,2.0\n");

//Addition
	addValues(2,4,6);
//Division
	callfunc(36.0,3.0,2.0);

	printf("\nThank you..\n\n");
	return 0;
}

//Definitions:

//Function performs addition and prints the addition
void addValues(int a,int b,int c)
{
	int addition=0;
	addition = a + b + c;
	printf("\n The addition is (%d + %d + %d) = %d \n",a,b,c,addition);
}

//Function divides the number and returns the division
double divideValues(float value1,float value2,float value3)
{
	double temp = 0.0;
	temp = value1/value2;
	temp = temp/value3;
	return(temp);
}

//Function calls divide function and prints the result
void callfunc(float n1,float n2,float n3)
{
	double division = 0.0;
	division = divideValues(n1,n2,n3);
	printf("\n The division is { (%.1f / %.1f) / %.1f } = %.4f \n",n1,n2,n3,division);
}
