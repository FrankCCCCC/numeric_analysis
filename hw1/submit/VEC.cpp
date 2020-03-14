// VEC class functions
#include "iostream"
#include "VEC.h"

VEC::VEC(int n){ // Uninit contructor, val is 0
    dim = n;
    val = new double[n]; // Allocate memory for vectors of the vector
}

VEC::VEC(const VEC &v){ // Copy constructor
    dim = v.dim;
    val = new double[dim]; // Allocate memory for vectors of the vector
    for(int i=0; i<dim; i++){
        val[i] = v.val[i];
    }
}

VEC::VEC(double *array){ // Init constructor with smae values
    dim = sizeof(*array) / sizeof(double);
    val = new double[dim]; // Allocate memory for vectors of the vector
    for(int i=0; i<dim; i++){
        val[i] = array[i];
    }
}

VEC::VEC(int n, double *array){ // Init constructor
    dim = n;
    val = new double[n]; // Allocate memory for vectors of the vector
    for(int i=0; i<dim; i++){
        val[i] = array[i];
    }
}

int VEC::len(){  // Dimension of the vector
    return dim;
}

void VEC::show(){ // Print the vector
    for(int i=0; i<dim-1; i++){
        std::cout << val[i] << " ";
    }
    std::cout << val[dim-1] << std::endl;
}

VEC VEC::dot(const VEC v){ // Elements product
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] *= v.val[i];
    }

    return nv;
}

double VEC::sum(){ // The sum of all elements in the matrix
    int s = 0; // Declare a temporary counter

    for(int i=0; i<dim; i++){
        s += val[i];
    }

    return s;
}

bool VEC::operator==(const VEC v){ // Equality comparison operator
    bool flag = true; // Declare a flag to represent the result of comparison

    if(dim == v.dim){
        for(int i=0; i<dim; i++){
            if(val[i] != v.val[i]){
                flag = false;
                break;
            }
        }
    }else{
        flag = false;
    }
    
    return flag;
}

bool VEC::operator!=(const VEC v){ // Inequality comparison operator
    bool flag = false; // Declare a flag to represent the result of comparison

    if(dim == v.dim){
        for(int i=0; i<dim; i++){
            if(val[i] != v.val[i]){
                flag = true;
                break;
            }
        }
    }else{
        flag = true;
    }
    
    return flag;
}

VEC &VEC::operator-(){ // Unary operator, negative value
    VEC *nv = new VEC(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        (*nv).val[i] = -val[i];
    }

    return *nv;
}

VEC &VEC::operator=(const VEC v){ // vector assignment
    dim = v.dim;
    for(int i=0; i<dim; i++){
        val[i] = v.val[i];
    }

    return *this;
}

VEC &VEC::operator=(const double a){ // assignment with the same value
    for(int i=0; i<dim; i++){
        val[i] = a;
    }

    return *this;
}

VEC &VEC::operator+=(const VEC v){ // V += V1
    dim = v.dim;
    for(int i=0; i<dim; i++){
        val[i] += v.val[i];
    }

    return *this;
}

VEC &VEC::operator-=(const VEC v){ // V -= V1
    dim = v.dim;
    for(int i=0; i<dim; i++){
        val[i] -= v.val[i];
    }

    return *this;
}

// VEC &VEC::operator*=(const VEC v){  // V *= V1
//     dim = v.dim;
//     for(int i=0; i<dim; i++){
//         val[i] *= v.val[i];
//     }
// 
//     return *this;
// }

VEC &VEC::operator/=(const VEC v){ // V /= V1
    dim = v.dim;
    for(int i=0; i<dim; i++){
        val[i] /= v.val[i];
    }

    return *this;
}

VEC VEC::operator+(const VEC v){ // V + V1
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] += v.val[i];
    }

    return nv;
}

VEC VEC::operator-(const VEC v){ // V - V1
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] -= v.val[i];
    }

    return nv;
}

double VEC::operator*(const VEC v){ // V * V1
    VEC nv(*this); // A copy of Vector
    double s = 0; // A temporary counter

    for(int i=0; i<dim; i++){
        s += (nv.val[i] * v.val[i]);
    }

    return s;
}

VEC VEC::operator/(const VEC v){ // V / V1
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] /= v.val[i];
    }

    return nv;
}

double &VEC::operator[](int n){ // Indexing
    if(n < 0){n = 0;}
    else if(n >= dim){n = dim - 1;}

    return val[n];
}

VEC VEC::operator+(const double a){ // V + double, all element add the same value
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] += a;
    }

    return nv;
}

VEC VEC::operator-(const double a){ // V - double, all element minus the same value
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] -= a;
    }

    return nv;
}

VEC VEC::operator*(const double a){ // V * double
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] *= a;
    }

    return nv;
}

VEC VEC::operator/(const double a){ // V / double
    VEC nv(*this); // A copy of Vector

    for(int i=0; i<dim; i++){
        nv.val[i] /= a;
    }

    return nv;
}

VEC::~VEC(){ // Destructor
    delete [] val;
}

VEC operator+(double a, const VEC v){ // double + V, all element add the same value
    VEC nv(v); // A copy of Vector

    for(int i=0; i<v.dim; i++){
        nv.val[i] += a;
    }

    return nv;
}

VEC operator-(double a, const VEC v){ // double - V,  the same value  are minused by elements
    VEC nv(v); // A copy of Vector

    for(int i=0; i<v.dim; i++){
        nv.val[i] = a - nv.val[i];
    }

    return nv;
}

VEC operator*(double a, const VEC v){ // double * V
    VEC nv(v); // A copy of Vector

    for(int i=0; i<v.dim; i++){
        nv.val[i] *= a;
    }

    return nv;
}

VEC operator/(double a, const VEC v){ // double / V, , all element are devided by the same value
    VEC nv(v); // A copy of Vector

    for(int i=0; i<v.dim; i++){
        nv.val[i] = a / nv.val[i];
    }

    return nv;
}

VEC *newVEC(int n){ // Create dynamic VEC
    VEC *vp; // Declare a new Matrix pointer
    vp = (VEC *)malloc(sizeof(VEC)); // Allocate memory for vectors of the vector
    vp->dim = n;
    vp->val = (double *)calloc(n, sizeof(double)); // Allocate memory for vectors of the vector

    return vp;
}