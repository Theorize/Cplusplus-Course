#include <cmath>
#include <iostream>
#include "5_10.h"

void guassian_elimination( double **A, double *b , double *u, int n){
	int max;
	double m;
	double ubPrev;
	double swapRow[n];
	double swapB;

	//printMatrix(A,3,3);
	
	for(int k=1; k<n; k++){

		/* PIVOT!!! (i.e. swap the current row with the
		 row that has the maximal value in the column k.) */
		max = k-1;
		for(int i=k-1; i<n; i++){   
			// i is the index we want to return for the max.
			if(A[i][k-1] > A[max][k-1]){max = i;}
		}
		
		if(max!=k-1){
			//interchange the k-th row with the max-th row.
			for(int j=0; j<n; j++){
				//1st, store k, so that it may be written over.
				swapRow[j]=A[k-1][j];
				//2nd change k to max.
				A[k-1][j] = A[max][j];
				//Lastly, change max to k (as stored in swapRow).
				A[max][j] = swapRow[j];
			}

			//The entries of b must also be swapped.
			swapB = b[k-1];
			b[k-1] = b[max];
			b[max] = swapB;
		}
		
		//std::cout << "After Pivot\n";
		//printMatrix(A,3,3);
		
		//And then continue... :)

		//loop 1: k=2, n=3, i=2.
		// m = A[2][1]/A[1][1]

		for(int i=k; i<n; i++){
			m = A[i][k-1]/A[k-1][k-1];
			//std::cout << "i =" << i << "m=" << m << "\n";
			

			for(int j=k-1; j<n; j++){ 
				A[i][j] -= m*A[k-1][j]; 
				//std::cout << "i =" << i << "j=" << j << "\n";
				//printMatrix(A,3,3);
			}
			//std::cout << "b[i]="<< b[i];
			b[i] -= m*b[k-1];
			//std::cout << "  m = "<< m << ", b[k-1]="<< b[k-1] << ", b[" <<i <<"] = "<< b[i]<<"\n";
		}
	}

	//k=0, 
	for(int k=n-1; k>-1; k--){
		ubPrev = 0;

		//i=1 ubprev = A[0][1]*u[1]+ A[0][2]*u[2]
		for(int i=k+1; i<n ;i++){ubPrev += A[k][i]*u[i];}
		u[k] = (b[k] - ubPrev)/A[k][k];
	}

	//std::cout << "u = (" << u[0] << ", " << u[1] << ", " << u[2] << ") \n";
}
