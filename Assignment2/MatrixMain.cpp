#include "Matrix2x2.hpp"


int main(int argc, char* argv[]) {
	Matrix2x2 test(1,2,3,4.3);
	test.Print();
	std::cout << "det(test) = " << 	test.CalcDeterminant() << "\n";
	std::cout << "test inverse = " << "\n";
	test.CalcInverse().Print();
	Matrix2x2 A;
	A = -test;
	A.Print();
	Matrix2x2 B;
	B = A + test;
	B.Print();
	B = A - test;
	B.Print();
return 0;}