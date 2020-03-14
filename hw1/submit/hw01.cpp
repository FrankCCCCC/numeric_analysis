// EE4070 Hw01 Gram-Schmidt Process
// 106033233 周聖諺
// 2020/03/14
#include "iostream"
#include "math.h"
#include "VEC.h"
#include "MAT.h"

using namespace std;

MAT readMat(){ // Read mx.dat to contruct a Matrix and return 
    int size = 0; // Matrix Dimension

    std::cin >> size; // Read Matrix Dimension

    MAT M(size); // Declare Matrix to store

    for(int i = 0; i < size; i++){ // Read file and construct matrix
        for(int j = 0; j < size; j++){
            std::cin >> M[i][j];
        }
    }
    
    return M;
}

MAT gramSchmidt1(MAT A){ // Algorithm 1. Classic Gram-Schmidt Process
    std::cout << "Algorithm 1. Gram-Schmidt Process" << std::endl;

    MAT matA(A.transpose()); // Declare a copy of Matrix A with transpose
    int ASize = A.size(); // dimension of input Matrix A
    int matASize = matA.size(); // dimension of the copy of Matrix A
    MAT matG(matASize); // Declare Matrix G

    matG[0] = matA[0];
    
    for(int k=1; k<matASize; k++){ // Access row as column(Matrix A transposed)
        matG[k] = 0;
        for(int i=0; i<k; i++){
            matG[k] = matG[k] + (matA[k] * matG[i]) * matG[i] / (matG[i] * matG[i]);
        }
        matG[k] = matA[k] - matG[k];
    }

    return matG.transpose(); // Transpose Matrix G back to origin
}

MAT gramSchmidt2(MAT A){ // Algorithm 2. Modified Gram-Schmidt Process, 1
    std::cout << "Algorithm 2. Modified Gram-Schmidt Process, 1" << std::endl;

    MAT matA(A.transpose()); // Declare a copy of Matrix A
    int aSize = A.size(); // dimension of input Matrix A
    int matASize = matA.size(); // dimension of the copy of Matrix A
    MAT matG(matASize); // Declare Matrix G

    matG[0] = matA[0];
    
    for(int k=1; k<matASize; k++){ // Access row as column(Matrix A transposed)
        matG[k] = matA[k];
        for(int i=0; i<k; i++){
            matG[k] = matG[k] - (matG[k] * matG[i]) * matG[i] / (matG[i] * matG[i]);
        }
    }

    return matG.transpose(); // Transpose Matrix G back to origin
}

MAT gramSchmidt3(MAT A){ // Algorithm 3. Modified Gram-Schmidt Process, 2
    std::cout << "Algorithm 3. Modified Gram-Schmidt Process, 2" << std::endl;

    MAT matA(A.transpose()); // Declare a copy of Matrix A with transpose
    int aSize = A.size(); // dimension of input Matrix A
    int matASize = matA.size(); // dimension of the copy of Matrix A
    MAT matG(matASize); // Declare Matrix G

    matG[0] = matA[0];
    
    for(int k=1; k<matASize; k++){ // Access row as column(Matrix A transposed)
        matG[k] = matA[k];
        for(int i=0; i<k; i++){
            matG[k] = matG[k] - (((matG[k] * matG[i]) / (matG[i] * matG[i])) * matG[i]);
        }
    }

    return matG.transpose(); // Transpose Matrix G back to origin
}

MAT gramSchmidt4(MAT A){ // Algorithm 4. Modified Gram-Schmidt Process, 3
    std::cout << "Algorithm 4. Modified Gram-Schmidt Process, 3" << std::endl;

    MAT matA(A.transpose()); // Declare a copy of Matrix A with transpose
    int aSize = A.size(); // dimension of input Matrix A
    int matASize = matA.size(); // dimension of the copy of Matrix A
    MAT matG(matASize); // Declare Matrix G
    
    matG = matA;

    for(int j=0; j<matASize-1; j++){ // Access row as column(Matrix A transposed)
        double alpha = matG[j] * matG[j];
        for(int k=j+1; k<matASize; k++){
            matG[k] = matG[k] - ((matG[k] * matG[j] / alpha) * matG[j]);
        }
    }

    return matG.transpose(); // Transpose Matrix G back to origin
}

double verify(MAT G){ // Verify the Matrix G is orthogonal
    MAT d = G.transpose() * G; // Multiply Matrix G to get diagonal Matrix D
    double error = 0; // Declare variable error with initial vlaue 0

    for(int i=0; i<G.size(); i++){ // Calculate the sum of sqaure of elements in Matrix D
        for(int j=0; j<G.size(); j++){
            if(i != j){error += d[i][j] * d[i][j];}
        }
    }

    error = sqrt(error); // Sqare root of error
    std::cout << "sigma = " << error << std::endl;

    return error;
}

int main(int argc, char *argv[]){
    MAT input (readMat()); // Declare Matrix input from read in file

    if(argc == 1){ // When there is no other parameter
        MAT gs4(gramSchmidt4(input)); // Default algorithm
        verify(gs4); // Verify
    }else if(argc == 2){
        if(argv[1][0] == '1'){ // If the paramete is 1, run Gram-Schmidt Algorithm 1, etc
            MAT gs1(gramSchmidt1(input));
            verify(gs1);
        }else if(argv[1][0] == '2'){
            MAT gs2(gramSchmidt2(input));
            verify(gs2);
        }else if(argv[1][0] == '3'){
            MAT gs3(gramSchmidt3(input));
            verify(gs3);
        }else if(argv[1][0] == '4'){
            MAT gs4(gramSchmidt4(input));
            verify(gs4);
        }
        // else{
        //     MAT gs1(gramSchmidt1(input));
        //     MAT gs2(gramSchmidt2(input));
        //     MAT o(gs2 - gs1);

        //     gs1[0].show();
        //     gs2[0].show();
        //     (gs1[0] - gs2[0]).show();
        //     verify(gs1);
        //     verify(gs2);
        // }
    }

    return 0;
}