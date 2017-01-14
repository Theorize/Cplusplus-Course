#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <cmath>

//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			std::cout << A[i][j];
			std::cout << "\t";
		}
		std::cout << "\n";
	}
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){
	
	
	// Allocate memory to an array that is to be a copy of A.
	ComplexNumber** ACopy;
	ACopy = new ComplexNumber* [3];
	for (int i=0; i<3; i++){ 
		ACopy[i] = new ComplexNumber [3];
		for(int j=0; j<3; j++){ 
			ACopy[i][j] = ComplexNumber(A[i][j]);
		}
	}

	// Allocate memory to an array that will become A^n in each iteration.
	ComplexNumber** APower;
	APower = new ComplexNumber* [3];
	for (int i=0; i<3; i++){ 
		APower[i] = new ComplexNumber [3];
	}

	// Allocate memory to an array that will become A^(n-1) in each iteration 
	// and intialise it as the identity matrix.
	ComplexNumber** APrev;
	APrev = new ComplexNumber* [3];
	for (int i=0; i<3; i++){ 
		APrev[i] = new ComplexNumber [3];
		for(int j=0; j<3; j++){
			APrev[i][j] = ComplexNumber(0);
		}
		APrev[i][i] = ComplexNumber(1);
	}

	// Intialise the factorial
	double nFact = 1;
	double R;
	double Im;

	// Intialise the result matrix to with all entries ((A[i][j])^0)/0! = 1/
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			res[i][j] = ComplexNumber(1);
		}
	}



	for(int n=1; n<nMax; n++){

		// Multiply ACopy and APrev = A^(n-1) together and save it to APower = A^n.
		for(int r=0; r<3; r++) {
			for(int c=0; c<3; c++) {
				APower[r][c] = 0;
				for(int i=0; i<3; i++) {
					APower[r][c] = APower[r][c] + ACopy[r][i]*APrev[i][c];
				}
			}
		}
		
		// Multiply nFact = (n-1)! by n to get n!.
		nFact *= n;
		
		// Set res = current res + APower/nfrac.
		for(int r=0; r<3; r++){
			for(int c=0; c<3; c++){
				R = RealPart(APower[r][c]);
				Im = ImaginaryPart(APower[r][c]);
				res[r][c] = res[r][c] + ComplexNumber(R/nFact,Im/nFact);
			}
		}

		// Set APrev = APower, ready for the next round.
		for (int r=0; r<3; r++){ 
			for(int c=0; c<3; c++){ 
				APrev[r][c] = ComplexNumber(APower[r][c]);
			}
		}
	}

	//printMatrix(res, 3,3);

	// Deallocate memory to ACopy.
	for(int j=0; j<3; j++){ delete[] ACopy[j];}
	delete[] ACopy;
	// Deallocate memory to APrev.
	for(int j=0; j<3; j++){ delete[] APrev[j];}
	delete[] APrev;
	// Deallocate memory to APower.
	for(int j=0; j<3; j++){ delete[] APower[j];}
	delete[] APower;
}
 