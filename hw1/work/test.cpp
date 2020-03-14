#include "iostream"
#include "string.h"
#include "VEC.h"
#include "MAT.h"

using namespace std;

template <class T>
bool check(T input, T expected, string describe){
    if(input == expected){std::cout << "Test Correct: "<< describe << std::endl;}
    else{std::cout << "Test Error: Input is not equal to expected: " << describe << std::endl;}
}

int main(int argc, char *argv[]){
    cout << "Hello World" << endl;
    double a[3] = {1.0,2.0,3.0};
    double a1[3] = {2.0,4.0,6.0};
    double a2[3] = {0.0,0.0,0.0};
    double a3[3] = {1.0,4.0,9.0};
    double a4[3] = {1.0,1.0,1.0};
    double a5[3] = {2.0,3.0,4.0};
    VEC v1(3, a);
    VEC *v2 = new VEC(3);
    VEC *v3 = new VEC(v1);
    *v2 = -(*v3);

    VEC *v4 = new VEC(3, a1);
    VEC *v5 = new VEC(3, a2);
    VEC *v6 = new VEC(3, a3);
    VEC *v7 = new VEC(3, a4);
    VEC *v8 = new VEC(3, a5);
    
    check<VEC>(-v1, *v2, "-v1, v2 should equal");
    check<VEC>(v1, (*v3), "v1, v3 should equal");
    check<VEC>((*v2), -(*v3), "v1, -v3 should equal");
    check<int>(v1.len(), 3, "v1.len(), 3 should equal");
    check<VEC>((*v3).dot(*v3), *v6, "v3*v3, new VEC(3, {1.0,4.0,9.0}) should equal");
    check<bool>((-v1 == *v2), true, "(-v1 == v2), true should equal");
    check<bool>((-v1 != *v2), false, "(-v1 != v2), false should equal");

    check<VEC>((*v3) + (*v3), *v4, "v3+v3, new VEC(3, {2.0,4.0,6.0}) should equal");
    check<VEC>((*v3) - (*v3), *v5, "v3-v3, new VEC(3, {0.0,0.0,0.0}) should equal");
    check<double>(((*v3) * (*v3)), 14, "v3*v3, 14 should equal");
    check<VEC>((*v3) / (*v3), *v7, "v3/v3, new VEC(3, {1.0,1.0,1.0}) should equal");

    check<VEC>((*v3) + 1.0, *v8, "v3+1.0, new VEC(3, {2.0,3.0,4.0}) should equal");
    check<VEC>((*v3) - (-1.0), *v8, "v3-(-1.0), new VEC(3,{2.0,3.0,4.0}) should equal");
    check<VEC>(((*v3) * 2), *v4, "v3*2, new VEC(3,  {2.0,4.0,6.0}) should equal");
    check<VEC>((*v3) / 0.5, *v4, "v3/0.5, new VEC(3, {2.2,4.2,6.2}) should equal");

    check<VEC>(1.0 + (*v3), *v8, "1.0+v3, new VEC(3,{2.0,3.0,4.0}) should equal");
    check<VEC>((-1.0) - (*v3), -(*v8), "(-1.0)-v3, new VEC(3,{-2.0,-3.0,-4.0}) should equal");
    check<VEC>(2 * (*v3), *v4, "2*v3, new VEC(3, {2.0,4.0,6.0}) should equal");
    check<VEC>(0.0 / (*v3), *v5, "0.0/v3, new VEC(3, {0.0,0.0,0.0}) should equal");

    VEC vt(v1);
    vt += v1;
    check<VEC>(vt, *v4, "vt = v1; vt+=v1, new VEC(3, {2.0,4.0,6.0}) should equal");
    vt = v1;
    vt -= v1;
    check<VEC>(vt, *v5, "vt = v1; vt-=v1, new VEC(3, {0.0,0.0,0.0}) should equal");
    // vt = v1;
    // vt *= v1;
    // check<VEC>(vt, *v6, "vt = v1; vt*=v1, new VEC(3, {1.21,4.41,9.61}) should equal");
    vt = v1;
    vt /= v1;
    check<VEC>(vt, *v7, "vt = v1; vt/=v1, new VEC(3, {1.0,1.0,1.0}) should equal");

    

    double b[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    double b1[9] = {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0};
    double b2[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double b3[9] = {30.0, 36.0, 42.0, 66.0, 81.0, 96.0, 102.0, 126.0, 150.0};
    double b4[9] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    double b5[9] = {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    MAT m1(3, b);
    MAT *m2 = new MAT(3);
    MAT *m3 = new MAT(m1);
    *m2 = -m1;
    // (*m2).show();

    MAT *m4 = new MAT(3, b1);
    MAT *m5 = new MAT(3, b2);
    MAT *m6 = new MAT(3, b3);
    MAT *m7 = new MAT(3, b4);
    MAT *m8 = new MAT(3, b5);
    
    check<MAT>(-m1, *m2, "-m1, m2 should equal");
    check<MAT>(m1, (*m3), "m1, m3 should equal");
    check<MAT>((*m2), -(*m3), "m1, -m3 should equal");
    check<int>(m1.size(), 3, "m1.size(), 3 should equal");
    check<bool>((-m1 == *m2), true, "(-m1 == m2), true should equal");
    check<bool>((-m1 != *m2), false, "(-m1 != m2), false should equal");

    check<MAT>((*m3) + (*m3), *m4, "m3+m3, new MAT(3, {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0}) should equal");
    check<MAT>((*m3) - (*m3), *m5, "m3-m3, new MAT(3, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}) should equal");
    check<MAT>(((*m3) * (*m3)), *m6, "m3*m3, new MAT(3, {30.0, 36.0, 42.0, 66.0, 81.0, 96.0, 102.0, 126.0, 150.0}) should equal");
    check<MAT>((*m3) / (*m3), *m7, "m3/m3, new MAT(3, {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}) should equal");

    check<MAT>((*m3) + 1.0, *m8, "m3+1.0, new MAT(3, {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}) should equal");
    check<MAT>((*m3) - (-1.0), *m8, "m3-(-1.0), new MAT(3, {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}) should equal");
    check<MAT>(((*m3) * 2), *m4, "m3*2, new MAT(3, {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0}) should equal");
    check<MAT>((*m3) / 0.5, *m4, "m3/0.5, new MAT(3, {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0}) should equal");

    check<MAT>(1.0 + (*m3), *m8, "1.0+m3, new MAT(3, {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}) should equal");
    check<MAT>((-1.0) - (*m3), -(*m8), "(-1.0)-m3, new MAT(3, {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}) should equal");
    check<MAT>(2 * (*m3), *m4, "2*m3, new MAT(3, {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0}) should equal");
    check<MAT>(0.0 / (*m3), *m5, "0.0/m3, new MAT(3, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}) should equal");

    MAT mt(m1);
    mt += m1;
    check<MAT>(mt, *m4, "mt = m1; mt+=m1, new MAT(3, {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0}) should equal");
    mt = m1;
    mt -= m1;
    check<MAT>(mt, *m5, "mt = m1; mt-=m1, new MAT(3, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}) should equal");
    mt = m1;
    mt *= m1;
    check<MAT>(mt, *m6, "mt = m1; mt*=m1, new MAT(3, {30.0, 36.0, 42.0, 66.0, 81.0, 96.0, 102.0, 126.0, 150.0}) should equal");
    mt = m1;
    mt /= m1;
    check<MAT>(mt, *m7, "mt = m1; mt/=m1, new MAT(3, {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}) should equal");

    

    return 0;
}