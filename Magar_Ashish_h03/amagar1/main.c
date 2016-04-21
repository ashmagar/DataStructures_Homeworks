#include<stdio.h>
#include "hw3.h"

int main()
{
	int arraySize = 7;
	int i = 0;
	struct geoData gd[arraySize];
	float x = 0.0;

	for(i=0;i<arraySize;i++)
	{
		gd[i] = createGeoData(50,0.001,x);
		x += 0.2;
		if(x>1) x=0.5;
	}
	calculateGeoSeries(gd,arraySize);

	return 0;
}

//inputs
/*
50, 0.001, 0.0
50, 0.001, 0.2
50, 0.001, 0.4
50, 0.001, 0.6
50, 0.001, 0.8
50, 0.001, 1.0
50, 0.001, 0.5
*/
