#ifndef SUBMISSION_MATRIX2X2_HPP_
#define SUBMISSION_MATRIX2X2_HPP_

#include <iostream>

class Matrix2x2 {
	private:
		double val00; // first row, first column
		double val01; // first row, second column
		double val10; // second row, first colum
		double val11; // second row, second column

	public:
		Matrix2x2();
		Matrix2x2(const Matrix2x2& other);
		Matrix2x2(double a, double b, double c, double d);
		double CalcDeterminant() const;
		Matrix2x2 CalcInverse() const;

		Matrix2x2& operator=(const Matrix2x2& z);
		Matrix2x2 operator-() const;
		Matrix2x2 operator+(const Matrix2x2& z) const;
		Matrix2x2 operator-(const Matrix2x2& z) const;

		void MultScalar(double scalar);

		double Getval00() const {return val00;}
		double Getval01() const {return val01;}
		double Getval10() const {return val10;}
		double Getval11() const {return val11;}

		//non mandatory
		void Print() const;
};



#endif /* SUBMISSION_MATRIX2X2_HPP_ */
