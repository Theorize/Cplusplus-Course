#include <cmath>
#include <iostream>
#include "5_4.h"


double calc_mean(double a[] , int length){
	double mean = 0;
	for(int i=0; i<length; i++){mean += a[i];}
	std::cout << mean << "\n";
	mean /= ((double)(length));
	return mean;
}

double calc_std(double a[] , int length){
	double std = 0;

	if(length != 1){
		double mean = 0;
		for(int i=0; i<length; i++){mean += a[i];}
		mean /= ((double)(length));
		
		for(int i=0; i<length; i++){std += pow(a[i]-mean, 2);}
		std /= ((double)(length-1));
		std = sqrt(std);
	}

	return std;
}