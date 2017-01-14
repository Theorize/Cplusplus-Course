#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include <cmath>
#include <vector>
#include <cassert>
#include "Vector.hpp"

template <typename T>
class Matrix
{
private:
   std::vector<T> mData; // entries of matrix
   int mNumRows, mNumCols; // dimensions
   bool isRowMajor; // T if Internal represenation is row major, F is column major
public:
   Matrix(const Matrix<T>& otherMatrix);
   Matrix(int numRows, int numCols, bool rowMajor);
   ~Matrix();
   int GetNumberOfRows() const;
   int GetNumberOfColumns() const;
   T& operator()(int i, int j); //1-based indexing
   T& Read(int i, int j) const; //1-based indexing
   //overloaded assignment operator
   Matrix<T>& operator=(const Matrix<T>& otherMatrix);
   Matrix<T> operator+() const; // unary +
   Matrix<T> operator-() const; // unary -
   Matrix<T> operator+(const Matrix<T>& m1) const; // binary +
   Matrix<T> operator-(const Matrix<T>& m1) const; // binary -
   // scalar multiplication
   Matrix<T> operator*(T a) const;
   double CalculateDeterminant() const;
   // declare vector multiplication friendship
   template <typename U> friend Vector<U> operator*(const Matrix<U>& m, 
                           const Vector<U>& v);
   template <typename U> friend Vector<U> operator*(const Vector<U>& v, 
                           const Matrix<U>& m);

   std::vector<T> getData() const; //returns vector
   bool getOrder() const; //returns isRowMajor variable.

};

// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
 template <typename T>
Matrix<T>::Matrix(const Matrix<T>& otherMatrix)
{
   mNumRows = otherMatrix.mNumRows;
   mNumCols = otherMatrix.mNumCols;
   isRowMajor = otherMatrix.isRowMajor;
   mData = std::vector<T> (mNumRows*mNumCols);
   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mData[i] = otherMatrix.mData[i];
   }
}

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
template <typename T>
Matrix<T>::Matrix(int numRows, int numCols, bool rowMajor)
{
   assert(numRows > 0);
   assert(numCols > 0);
   mNumRows = numRows;
   mNumCols = numCols;
   isRowMajor = rowMajor;
   mData = std::vector<T> (mNumRows*mNumCols);
   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mData[i] = 0;
   }
}


// Overwritten destructor to correctly free memory
template <typename T>
Matrix<T>::~Matrix()
{
   mData.clear();
}

// Method to get number of rows of matrix
template <typename T>
int Matrix<T>::GetNumberOfRows() const
{
   return mNumRows;
}

// Method to get number of columns of matrix
template <typename T>
int Matrix<T>::GetNumberOfColumns() const
{
   return mNumCols;
}

template <typename T>
bool Matrix<T>::getOrder() const
{
   return isRowMajor;
}

template <typename T>
std::vector<T> Matrix<T>::getData() const{
   return mData;
}


// Overloading the round brackets
// Note that this uses `one-based' indexing,
// and a check on the validity of the index

template <typename T>
T& Matrix<T>::operator()(int i, int j)
{
   assert(i > 0);
   assert(i < mNumRows+1);
   assert(j > 0);
   assert(j < mNumCols+1);
   if(isRowMajor == 1){return mData[(i-1)*mNumCols+j-1];}
   else{return mData[(j-1)*mNumRows+i-1];}
}


//Read only version of ()
template <typename T>
T& Matrix<T>::Read(int i, int j) const{
   assert(i > 0);
   assert(i < GetNumberOfRows()+1);
   assert(j > 0);
   assert(j < GetNumberOfColumns()+1);
   if(isRowMajor == 1){return getData()[(i-1)*GetNumberOfColumns()+j-1];}
   else{return getData()[(j-1)*GetNumberOfRows()+i-1];}
}


// Overloading the assignment operator
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& otherMatrix)
{
   assert(mNumRows = otherMatrix.mNumRows);
   assert(mNumCols = otherMatrix.mNumCols);
   isRowMajor = otherMatrix.getOrder();

   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mData[i] = otherMatrix.mData[i];
   }
   return *this;
}

// Overloading the unary + operator
template <typename T>
Matrix<T> Matrix<T>::operator+() const
{
   Matrix<T> mat(mNumRows, mNumCols, isRowMajor);
   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mat.mData[i] = mData[i];
   }
   return mat;
}


// Overloading the unary - operator
template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
   Matrix<T> mat(mNumRows, mNumCols, isRowMajor);
   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mat.mData[i] = -mData[i];
   }
   return mat;
}


// Overloading the binary + operator
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& m1) const
{
   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   Matrix mat(mNumRows, mNumCols, isRowMajor);
   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mat.mData[i] = mData[i] + m1.mData[i];
   }
   return mat;
}


// Overloading the binary - operator
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& m1) const
{
   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   Matrix mat(mNumRows, mNumCols, isRowMajor);
   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mat.mData[i] = mData[i] - m1.mData[i];
   }
   return mat;
}

// Overloading scalar multiplication
template <typename T>
Matrix<T> Matrix<T>::operator*(T a) const
{
   Matrix<T> mat(mNumRows, mNumCols, isRowMajor);
   for (int i=0; i<mNumRows*mNumCols; i++)
   {
      mat.mData[i] = a*mData[i];
   }
   return mat;
}


// Overloading matrix multiplied by a vector
template <typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
   int original_vector_size = v.GetSize();
   assert(m.GetNumberOfColumns() == original_vector_size);
   int new_vector_length = m.GetNumberOfRows();
   Vector<T> new_vector(new_vector_length);

   for (int i=0; i<new_vector_length; i++)
   {
      for (int j=0; j<original_vector_size; j++)
      {
         new_vector[i] += m.Read(i+1,j+1)*v.Read(j);
      }
   }

   return new_vector;
}

// Overloading vector multiplied by a matrix
template <typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
   int original_vector_size = v.GetSize();
   assert(m.GetNumberOfRows() == original_vector_size);
   int new_vector_length = m.GetNumberOfColumns();
   Vector<T> new_vector(new_vector_length);

   for (int i=0; i<new_vector_length; i++)
   {
      for (int j=0; j<original_vector_size; j++)
      {
         new_vector[i] += v.Read(j)*m.Read(j+1,i+1);
      }
   }

   return new_vector;
}


// Calculate determinant of square matrix recursively
template <class T>
double Matrix<T>::CalculateDeterminant() const
{
   assert(mNumRows == mNumCols);
   double determinant = 0.0;

   if (mNumRows == 1)
   {
      determinant = ((double)(Read(1,1)));
   }
   else
   {
      // More than one entry of matrix
      for (int i_outer=0; i_outer<mNumRows; i_outer++)
      {
         Matrix sub_matrix(mNumRows-1, 
                             mNumRows-1,0);
         for (int i=0; i<mNumRows-1; i++)
         {
            for (int j=0; j<i_outer; j++)
            {
               sub_matrix(i+1,j+1) = Read(i+2, j+1);
            }
            for (int j=i_outer; j<mNumRows-1; j++)
            {
               sub_matrix(i+1,j+1) = Read(i+2,j+2);
            }
         }
         double sub_matrix_determinant = 
                  sub_matrix.CalculateDeterminant();

         determinant += pow(-1.0, i_outer)*
                  ((double)(Read(1,i_outer+1)))*sub_matrix_determinant;
      }
   }
   return determinant;
}

#endif
//Code from Appendix.tex line 608 save as Matrix.hpp
