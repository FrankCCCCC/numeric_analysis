// Vector Class
#ifndef VEC_H
#define VEC_H

class VEC{
    public:
        VEC(int n); // Uninit contructor, val is 0
        VEC(const VEC &v); // Copy constructor
        VEC(double *v); // Init constructor with smae values
        VEC(int n, double *v); // Init constructor
        ~VEC(); // Destructor
        int len();  // Dimension of the vector
        void show(); // Print the vector
        VEC dot(const VEC v); // Elements product
        double sum(); // The sum of all elements in the matrix
        bool operator==(const VEC v); // Equality comparison operator
        bool operator!=(const VEC v); // Inequality comparison operator
        VEC &operator-(); // Unary operator, negative value
        VEC &operator=(const VEC v); // Vector assignment
        VEC &operator=(const double a); // Assignment with the same value
        VEC &operator+=(const VEC v); // V += V1
        VEC &operator-=(const VEC v); // V -= V1
        // VEC &operator*=(const VEC v);  // V *= V1
        VEC &operator/=(const VEC v); // V /= V1
        VEC operator+(const VEC v); // V + V1
        VEC operator-(const VEC v); // V - V1
        double operator*(const VEC v); // V * V1
        VEC operator/(const VEC v); // V / V1
        double &operator[](int n); // Indexing
        VEC operator+(const double a); // V + double, all element add the same value
        VEC operator-(const double a); // V - double, all element minus the same value
        VEC operator*(const double a); // V * double
        VEC operator/(const double a); // V / double, , all element are devided by the same value
        friend VEC operator+(double a, const VEC v); // double + V, all element add the same value
        friend VEC operator-(double a, const VEC v); // double - V,  the same value  are minused by elements
        friend VEC operator*(double a, const VEC v); // double * V
        friend VEC operator/(double a, const VEC v); // double / V
        
        friend VEC *newVEC(int n); // Create dynamic VEC
    private:
        int dim; // Vector length 
        double *val; // Array to store vector
};

VEC operator+(double a, const VEC v);
VEC operator-(double a, const VEC v);
VEC operator*(double a, const VEC v);
VEC operator/(double a, const VEC v);
VEC *newVEC(int n);
#endif