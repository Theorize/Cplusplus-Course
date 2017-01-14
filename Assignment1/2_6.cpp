#include <iostream>
#include <cmath>

double newton_Raphson(double initialGuess, double epsilon){
	
	double x_next, diff, f, dash;
	double x_prev;
	x_prev = initialGuess;

	do{
		f = exp(x_prev) + pow(x_prev, 3) - 5;
		dash = exp(x_prev) + 3*pow(x_prev, 2);
		x_next = x_prev - f/dash;
		diff = fabs(x_next - x_prev);
		x_prev = x_next;
		//std::cout << x_prev << "\n";
		// NOTE!  This is a very bad condition, as it would lead to an infinite while loop if we did not have convergence.
	} while (diff > epsilon);

	return x_next;}