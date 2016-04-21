#include<stdio.h>
#include "hw3.h"

// Create the structure
struct geoData createGeoData(int max, float error, float x)
{
	struct geoData tempStruct;
	tempStruct.maxTerms = max;
	tempStruct.x = x;
	tempStruct.errorTol = error;
	return tempStruct;
}

// Calculate the geometric series
struct geoData calculateGeo(struct geoData gd)
{
	float powX = 1;
	float expVal = 1/(1+gd.x);	//Expected Value
	float termVal = 0.0;
	float errVal = 0.0;
	int i=0;

	for(i=0;i<gd.maxTerms;i++)
	{
		if(i==0) termVal = 1.0;
		else
		{
			powX = powX * gd.x;			//Calculate exponent of x
			if(i%2 == 0)				//for even powers, add
			{
				termVal = termVal + powX;	//Calculate the series
			}
			else
			{
				termVal = termVal - powX;	//for odd powers, subtract
			}
		}
		errVal = termVal - expVal;
		if(errVal < 0) errVal = -errVal;		//absolute error

		if(errVal < gd.errorTol ) 
		{
			i++;
			break;
		}
	}

	struct geoData lastTerm = createGeoData(i,errVal,termVal);
	return lastTerm;
}

// Print Geometric Series
void printGeoData(struct geoData gd)
{
	printf("%d %f %f\n",gd.maxTerms,gd.x,gd.errorTol);
}

// The function called in main
void calculateGeoSeries(struct geoData gd[],int arraySize)
{
	int i=0;
	for(i=0;i<arraySize;i++)
	{
		if ((gd[i].x > 0 ) && (gd[i].x < 1) && (gd[i].maxTerms > 0))
				//Conditions, x should lie between 0 and 1 and maxterms > 0
		{
			printGeoData(calculateGeo(gd[i]));
		}
	}
}
