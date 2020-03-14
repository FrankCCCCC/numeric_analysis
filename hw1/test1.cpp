#include <stdio.h>

int &setNum(int &num2);

int main(int argc, char* argv[]){
    int num1 = 2;
    printf("before setNum(), num1: %d\n", num1);

    int &r = setNum(num1);
    num1+=3;
    printf("after setNum(), num1: %d\n", num1);
    printf("R is %d %p\n", r, &r);
    printf("num1 is %d %p\n", num1, &num1);

    int k = 6;
    int &ref = k;
    ref++;
    printf("K is %d %p\n", k, &k);
    printf("REF is %d %p\n", ref, &ref);
}

int &setNum(int &num2){
    printf("before setting, num2: %d\n", num2);
    num2 = 5;
    printf("after setting, num2: %d\n", num2);
    return num2;
}