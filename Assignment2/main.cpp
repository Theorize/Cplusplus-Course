#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"

int main(int argc, char* argv[]) {
 	ComplexNumber z1(4.0, 3.0);

	std::cout <<"z1="<<z1<<"\n";
	std::cout << "R(z1)="<<RealPart(z1)<<"="<<z1.GetRealPart()<<"\n";
	std::cout << "Im(z1)="<<ImaginaryPart(z1)<<"="<<z1.GetImaginaryPart()<<"\n";

	ComplexNumber z2(z1);
	std::cout << "Copy Check; z2=" << z2 << "\n";

	ComplexNumber z3(2);
	std::cout << "Real Constructor Check; z3=" << z3 << "\n";
	
	ComplexNumber z4 = z1.CalculateConjugate();
	std::cout << "Conjugate Function Check; z1^bar=" << z4 << "\n";
	z1.SetConjugate();
	std::cout << "Conjugate Set Check; The conjugate of z1 is =" << z1 << "\n";

	ComplexNumber z5;
	z5 = z1 * z1.CalculateConjugate();
	std::cout << "z1 * it's conjugate is " << z5 << "\n";

	ComplexNumber z6;
	z6 = z3 * z1;
	std::cout << "z1 * z3 is " << z6 << "\n";

	ComplexNumber z7(1,1);
	z7 = z7 * z1;
	std::cout << "z7 * z1 is " << z7 << "\n";

	z7 = ComplexNumber(1,2);
	std::cout <<"z7="<<z7<<"\n\n\n";

	ComplexNumber** A;
	A = new ComplexNumber* [3];
	for (int i=0; i<3; i++){ 
		A[i] = new ComplexNumber [3];
		for(int j=0; j<3; j++){ A[i][j] = ComplexNumber(i,j);
		}
	}

	ComplexNumber** res;
	res = new ComplexNumber* [3];
	for (int i=0; i<3; i++){ 
		res[i] = new ComplexNumber [3];
		for(int j=0; j<3; j++){ res[i][j] = ComplexNumber(i,j);
		}
	}


	CalculateExponential(A, 60, res);

	for(int j=0; j<3; j++){ delete[] A[j];}
	delete[] A;

	for(int j=0; j<3; j++){ delete[] res[j];}
	delete[] res;

	/* std::cout << "Modulus z1 = "
			  << z1.CalculateModulus() << "\n"; 
	std::cout << "Argument z1 = "
			  << z1.CalculateArgument() << "\n";

	ComplexNumber z2;
	z2 = z1.CalculatePower(3);
	std::cout << "z2 = z1*z1*z1 = " << z2 << "\n";

    ComplexNumber z3;
	z3 = -z2;
	std::cout << "z3 = -z2 = " << z3 << "\n";
    
	ComplexNumber z4;
	z4=z1+z2; std::cout<<"z1+z2="<<z4<<"\n";
	ComplexNumber zs[2];
	zs[0] = z1;
	zs[1] = z2;
	std::cout << "Second element of zs = "
    	      << zs[1] << "\n";  */
	return 0;}
    	     