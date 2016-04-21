#ifndef HW3_H_
#define HW3_H_

#include<stdio.h>

struct geoData{
	int maxTerms;
	float errorTol;
	float x;
};

struct geoData createGeoData(int max, float error, float x);
	// Creates the new structure for new entry for geometric series

struct geoData calculateGeo(struct geoData gd);
	// Calculates the actual geometric series

void printGeoData(struct geoData gd);
	// Prints the last term in geometric series

void calculateGeoSeries(struct geoData gd[],int arraySize);
	// Function called in main which calls all other functions

#endif
