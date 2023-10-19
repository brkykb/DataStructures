#include <stdio.h>

struct complex{

    int real;
    int im;
};
typedef struct complex complexnumbers;

int main(void){

    complexnumbers a,b;
    complexnumbers *p=&b;

    a.im=3;
    a.real=4;

    p->im=2;
    p->real=5;

    return 0;
}

