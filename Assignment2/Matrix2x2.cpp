#include "Matrix2x2.hpp"
#include <cmath>

// Override default constructor
// Set all entries to zero
Matrix2x2::Matrix2x2()
{
	val00 = 0.0;
	val01 = 0.0;
	val10 = 0.0;
	val11 = 0.0;
}

// Constructor that sets a matrix as {{a,b},{c,d}}.
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
	val00 = a;
	val01 = b;
	val10 = c;
	val11 = d;
}

// Overwrite copy constructor.
Matrix2x2::Matrix2x2(const Matrix2x2& other){
	val00 = other.Getval00();
	val01 = other.Getval01();
	val10 = other.Getval10();
	val11 = other.Getval11();
}

void Matrix2x2::Print() const{
	std::cout << val00 << "\t" << val01 << "\n";
	std::cout << val10 << "\t" << val11 << "\n";
}


// Get det
double Matrix2x2::CalcDeterminant() const{
	return (val00*val11 - val10*val01);
}


//Get inverse if it exists.
Matrix2x2 Matrix2x2::CalcInverse() const{
	double det = val00*val11 - val10*val01;
	if(det != 0){
		return Matrix2x2(val11/det, -val01/det, -val10/det, val00/det);
	}
}


// Overload the assignment operator.
Matrix2x2& Matrix2x2::
               operator=(const Matrix2x2& A)
{
	val00 = A.Getval00();
	val01 = A.Getval01();
	val10 = A.Getval10();
	val11 = A.Getval11();
	return *this;
}

// Overload the unary - operator
Matrix2x2 Matrix2x2::operator-() const
{	
	Matrix2x2 B;
	B.val00 = -val00;
	B.val01 = -val01;
	B.val10 = -val10;
	B.val11 = -val11;
	return B;
}

// Overloading the binary + operator
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& A) const
{
   Matrix2x2 B;
   B.val00 = val00 + A.val00;
   B.val01 = val01 + A.val01;
   B.val10 = val10 + A.val10;
   B.val11 = val11 + A.val11;
   return B;
}

// Overloading the binary - operator
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& A) const
{
   Matrix2x2 B;
   B.val00 = val00 - A.val00;
   B.val01 = val01 - A.val01;
   B.val10 = val10 - A.val10;
   B.val11 = val11 - A.val11;
   return B;
}

void Matrix2x2::MultScalar(double scalar){
	val00 = scalar*val00;
	val10 = scalar*val10;
	val01 = scalar*val01;
	val11 = scalar*val11;
}









