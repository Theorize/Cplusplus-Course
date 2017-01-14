#include <cassert>
#include <cmath>
#include <iostream>
#include <fstream>
#include "3_3.h"

void implicit_Euler(int n){
	assert(n>1);
	double h = 1/((double)(n));

	double xrecord[n];
	double yrecord[n];

	for(int i=0; i<n; i++){
		xrecord[i] = i*h;
	}

	yrecord[0] = 1;
	for(int i=1; i<n; i++){
		yrecord[i] = yrecord[i-1]/(1+h);
	}

	std::ofstream write_output("xy.dat");
	assert(write_output.is_open());
	write_output << xrecord[0] <<","<<yrecord[0] << "\n";
	for(int i =1; i<n; i++) {
		write_output << xrecord[i] << "," << yrecord[i] << "\n";
		write_output.flush();
	}

	write_output.close();
}




//Do the data writeout last.  Copy and paste from another one.