// MAT class function
#include "iostream"
#include "MAT.h"

MAT::MAT(int n){ // Uninit contructor, val is 0
	dim = n;
	val = (VEC **)malloc(dim * sizeof(VEC *)); // Allocate memory for vectors of the matrix
	
	for(int i=0; i<dim; i++){
		val[i] = new VEC(dim);
	}
}

MAT::MAT(const MAT &m){ // Copy constructor
	dim = m.dim;
	val = (VEC **)malloc(dim * sizeof(VEC *)); // Allocate memory for vectors of the matrix

	for(int i=0; i<dim; i++){
		val[i] = new VEC(*(m.val[i]));
	}
}

MAT::MAT(int n, double *array){ // Init constructor
	dim = n;
	val = (VEC **)malloc(dim * sizeof(VEC *)); // Allocate memory for vectors of the matrix

	for(int i=0; i<dim; i++){
		val[i] = new VEC(dim);
		for(int j=0; j<dim; j++){
			(*val[i])[j] = *(array++);
		}
	}
}

int MAT::size(){ // Dimension of the matrix
	return dim;
}

void MAT::show(){ // Print the Matrix
	std::cout << "--------------------" << std::endl;
	for(int i=0; i<dim; i++){
		val[i]->show();
	}
	std::cout << "--------------------" << std::endl;
}

MAT &MAT::transpose(){ // Transpose
	MAT *nm = new MAT(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			(*(*nm).val[i])[j] = (*val[j])[i];
		}
	}

	return *nm;
}

MAT MAT::dot(const MAT m){ // Dot product
	MAT nm(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		(*nm.val[i]) = (*nm.val[i]).dot((*m.val[i]));
	}

	return nm;
}

bool MAT::operator==(const MAT m){ // Equality comparison operator
	bool flag = true; // Declare a flag to represent the result of comparison

	if(dim == m.dim){
		for(int i=0; i<dim; i++){
			if((*val[i]) != (*m.val[i])){
				flag = false;
				break;
			}
		}
	}else{
		flag = false;
	}
	
	return flag;
}

bool MAT::operator!=(const MAT m){ // Inequality comparison operator
	bool flag = false; // Declare a flag to represent the result of comparison

	if(dim == m.dim){
		for(int i=0; i<dim; i++){
			if((*val[i]) != (*m.val[i])){
				flag = true;
				break;
			}
		}
	}else{
		flag = true;
	}
	
	return flag;
}

MAT &MAT::operator-(){ // Unary operator, negative value
	MAT *nm = new MAT(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			(*(*nm).val[i]) = -(*val[i]);
		}
	}

	return *nm;
}

MAT &MAT::operator=(const MAT m){ // Matrix assignment
	dim = m.dim;
	for(int i=0; i<dim; i++){
		(*val[i]) = (*m.val[i]);
	}

	return *this;
}

MAT &MAT::operator+=(const MAT m){ // M += M1
	dim = m.dim;
	for(int i=0; i<dim; i++){
		(*val[i]) += (*m.val[i]);
	}

	return *this;
}

MAT &MAT::operator-=(const MAT m){ // M -= M1
	dim = m.dim;
	for(int i=0; i<dim; i++){
		(*val[i]) -= (*m.val[i]);
	}

	return *this;
}

MAT &MAT::operator*=(const MAT m){ // M *= M1
	MAT nm(*this); // A copy of Matrix
	MAT tm(m); // A copy of Matrix
	tm = tm.transpose();

	for(int i=0; i<dim; i++){
		for(int j=0; j<tm.dim; j++){
			(*nm.val[i])[j] = ((*val[i]) * (*tm.val[j]));
		}
	}
	(*this) = nm;

	return *this;
}

MAT &MAT::operator/=(const MAT m){ // M /= M1
	dim = m.dim;
	for(int i=0; i<dim; i++){
		(*val[i]) /= (*m.val[i]);
	}

	return *this;
}

MAT MAT::operator+(const MAT m){ // M + M1
	MAT nm(*this); // A copy of Matrix
	
	for(int i=0; i<dim; i++){
		(*nm.val[i]) += (*m.val[i]);
	}
	
	return nm;
}

MAT MAT::operator-(const MAT m){ // M - M1
	MAT nm(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		(*nm.val[i]) -= (*m.val[i]);
	}

	return nm;
}

MAT MAT::operator*(const MAT m){ // M * M1
	MAT nm(*this); // A copy of Matrix
	MAT tm(m); // A copy of Matrix
	tm = tm.transpose();

	for(int i=0; i<dim; i++){
		for(int j=0; j<tm.dim; j++){
			(*nm.val[i])[j] = ((*val[i]) * (*tm.val[j]));
		}
	}
	
	return nm;
}

MAT MAT::operator/(const MAT m){ // M / M1
	MAT nm(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		(*nm.val[i]) /= (*m.val[i]);
	}

	return nm;
}

VEC &MAT::operator[](int n){ // Indexing
	if(n < 0){
		n = 0;
	}else if(n >= dim){
		n = dim - 1;
	}

	return (*val[n]);
}

MAT MAT::operator+(const double a){ // M + double, all element add the same value
	MAT nm(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		(*nm.val[i]) = (*val[i]) + a;
	}

	return nm;
}

MAT MAT::operator-(const double a){ // M - double,  the same value  are minused by elements
	MAT nm(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		(*nm.val[i]) = (*val[i]) - a;
	}

	return nm;
}

MAT MAT::operator*(const double a){ // M * double
	MAT nm(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		(*nm.val[i]) = (*val[i]) * a;
	}

	return nm;
}

MAT MAT::operator/(const double a){ // M / double, , all element are devided by the same value
	MAT nm(*this); // A copy of Matrix

	for(int i=0; i<dim; i++){
		(*nm.val[i]) = (*val[i]) / a;
	}

	return nm;
}

MAT::~MAT(){ // Destructor
	for(int i=0; i<dim; i++){
		(*val[i]).~VEC();
	}

	delete [] val;
}

MAT operator+(double a, const MAT m){ // double + M, all element add the same value
	MAT nm(m); // A copy of Matrix

	for(int i=0; i<m.dim; i++){
		(*nm.val[i]) = a + (*nm.val[i]);
	}

	return nm;
}

MAT operator-(double a, const MAT m){ // double - M,  the same value  are minused by elements
	MAT nm(m); // A copy of Matrix

	for(int i=0; i<m.dim; i++){
		(*nm.val[i]) = a - (*m.val[i]);
	}

	return nm;
}

MAT operator*(double a, const MAT m){ // double * M
	MAT nm(m); // A copy of Matrix

	for(int i=0; i<m.dim; i++){
		(*nm.val[i]) = a * (*nm.val[i]);
	}

	return nm;
}

MAT operator/(double a, const MAT m){ // double * M
	MAT nm(m); // A copy of Matrix

	for(int i=0; i<m.dim; i++){
		(*nm.val[i]) = a / (*nm.val[i]);
	}

	return nm;
}

MAT *newMAT(int n){ // Create dynamic MAT
	MAT *mp; // Declare a new Matrix pointer
	mp = (MAT *)malloc(sizeof(MAT)); // Allocate memory for vectors of the matrix
	mp->dim = n;
	mp->val = (VEC **)calloc(n, sizeof(VEC*)); // Allocate memory for vectors of the matrix

	return mp;
}