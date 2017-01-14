#include <cmath>
#include <iostream>
#include "5_3.h"

void swap_pointer(double *a, double *b){
	double hold = *a;
	*a = *b;
	*b = hold;
}

void swap_ref(double &a, double &b){
	double hold = a;
	a = b;
	b = hold;
}