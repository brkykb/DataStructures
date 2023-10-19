#include <stdio.h>

struct complex add(struct complex,struct complex);

struct complex{

    int im;
    int real;

};

int main(void){

    struct complex a,b;

    a.im=5;
    a.real=3;
    b.im=1;
    b.real=2;

    add(a,b);

    return 0;
}

struct complex add(struct complex a,struct complex b){

    struct complex result;

    result.im=a.im+b.im;
    result.real=a.real+b.real;

    return result;
}