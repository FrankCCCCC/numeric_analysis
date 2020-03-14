// Matrix Class
#ifndef MAT_H
#define MAT_H

#include "VEC.h"

class MAT{
	public:
		MAT(int n); // Uninit contructor, val is 0
		MAT(const MAT &m); // Copy constructor
		MAT(int n, double *v); // Init constructor
		~MAT(); // Destructor
		int size(); // Dimension of the matrix
		void show(); // Print the Matrix
		MAT &transpose(); // Transpose
		MAT dot(const MAT m); // Dot product
		bool operator==(const MAT m); // Equality comparison operator
		bool operator!=(const MAT m); // Inequality comparison operator
		MAT &operator-(); // Unary operator, negative value
		MAT &operator=(const MAT m); // Matrix assignment
		MAT &operator+=(const MAT m); // M += M1
		MAT &operator-=(const MAT m); // M -= M1
		MAT &operator*=(const MAT m); // M *= M1
		MAT &operator/=(const MAT m); // M /= M1
		MAT operator+(const MAT m); // M + M1
		MAT operator-(const MAT m); // M - M1
		MAT operator*(const MAT m); // M * M1
		MAT operator/(const MAT m); // M / M1
		VEC &operator[](int n); // Indexing
		MAT operator+(const double a); // M + double, all element add the same value
		MAT operator-(const double a); // M - double,  the same value  are minused by elements
		MAT operator*(const double a); // M * double
		MAT operator/(const double a); // M / double, , all element are devided by the same value
		friend MAT operator+(double a, const MAT m); // double + M, all element add the same value
		friend MAT operator-(double a, const MAT m); // double - M,  the same value  are minused by elements
		friend MAT operator*(double a, const MAT m); // double * M
		friend MAT operator/(double a, const MAT m); // double * M
		friend MAT *newMAT(int n); // Create dynamic MAT
	private:
		int dim; // Define a n * n Matrix
		VEC **val; // Array of n pointers to Vectors
};

MAT operator+(double a, const MAT m);
MAT operator-(double a, const MAT m);
MAT operator*(double a, const MAT m);
MAT operator/(double a, const MAT m);
MAT *newMAT(int n);
#endif