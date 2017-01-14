
//#include "5_6.h"


void Multiply(double **res, double **A, double **B, int ARows, int ACols , int BRows, int BCols){
	if(ACols==BRows){
		for(int r=0; r<ARows; r++) {
			for(int c=0; c<BCols; c++) {
				res[r][c] = 0;
				for(int i=0; i<ACols; i++) {
					res[r][c] += A[r][i]*B[i][c];
				}
			}
		}
	}
}





void Multiply(double *res , double *A, double **B, int ACols , int BRows, int BCols){
	if(ACols==BRows){
		for(int c=0; c<BCols; c++) {
			res[c] = 0;
			for(int i=0; i<ACols; i++) {
				res[c] += A[i]*B[i][c];
			}
		}
	}
}




void Multiply(double *res , double **A, double *B, int ARows, int ACols , int BRows){
	for(int r=0; r<ARows; r++) {
		res[r] = 0;
		for(int i=0; i<ACols; i++) {
			res[r] += A[r][i]*B[i];
		}
	}
}


void Multiply(double **res , double scalar , double **B, int BRows, int BCols){
	for(int r=0; r<BRows; r++) {
		for(int c=0; c<BCols; c++) {
			res[r][c] = scalar*B[r][c];
		}
	}
}


void Multiply(double **res, double **B, double scalar, int BRows, int BCols){
	for(int r=0; r<BRows; r++) {
		for(int c=0; c<BCols; c++) {
			res[r][c] = B[r][c]*scalar;
		}
	}
}


